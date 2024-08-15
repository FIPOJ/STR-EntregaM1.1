#include <stdio.h>
#include <pthread.h>

pthread_mutex_t cruzamento_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_pode_passar = PTHREAD_COND_INITIALIZER;

int carros_passando = 0;  // Número de carros que estão passando
int sentido_atual = 0;    // Sentido dos carros que estão passando, 1 para norte-sul, -1 para leste-oeste

void pedePassar(int sentido) {
    pthread_mutex_lock(&cruzamento_mutex);

    // Espera até que seja seguro passar
    while (carros_passando > 0 && sentido_atual != sentido) {
        pthread_cond_wait(&cond_pode_passar, &cruzamento_mutex);
    }

    // Atualiza o estado do cruzamento
    sentido_atual = sentido;
    carros_passando++;

    pthread_mutex_unlock(&cruzamento_mutex);
}

void jaPassei(void) {
    pthread_mutex_lock(&cruzamento_mutex);

    carros_passando--;

    // Se não há mais carros no cruzamento, permite que carros do outro sentido passem
    if (carros_passando == 0) {
        pthread_cond_broadcast(&cond_pode_passar);
    }

    pthread_mutex_unlock(&cruzamento_mutex);
}

void* carro(void* arg) {
    int sentido = *(int*)arg;

    pedePassar(sentido);
    printf("Carro passando no sentido %d\n", sentido);
    jaPassei();

    return NULL;
}

int main() {
    pthread_t threads[10];
    int sentidos[10] = {1, 1, -1, -1, 1, -1, 1, -1, 1, -1};

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, carro, &sentidos[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&cruzamento_mutex);
    pthread_cond_destroy(&cond_pode_passar);

    return 0;
}
