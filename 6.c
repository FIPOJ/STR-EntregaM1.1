#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_autorizacoes;  // Semáforo para controlar as autorizações
pthread_mutex_t mutex;   // Mutex para proteger o contador
int contador_autorizacoes = 0;  // Contador de autorizações

void autoriza(void) {
    pthread_mutex_lock(&mutex);
    contador_autorizacoes++;
    if (contador_autorizacoes >= 3) {
        sem_post(&sem_autorizacoes);  // Libera uma tarefa "mostra"
        contador_autorizacoes -= 3;   // Decrementa 3 autorizações
    }
    pthread_mutex_unlock(&mutex);
}

void espera_3_autorizacoes(void) {
    sem_wait(&sem_autorizacoes);  // Bloqueia até que 3 autorizações sejam feitas
    printf("Tarefa 'mostra' executando...\n");
}

void* tarefa_calcula(void* arg) {
    printf("Tarefa 'calcula' executando...\n");
    autoriza();  // Informa autorização
    return NULL;
}

void* tarefa_mostra(void* arg) {
    espera_3_autorizacoes();  // Espera até que 3 autorizações sejam feitas
    return NULL;
}

int main() {
    pthread_t threads_calcula[9];
    pthread_t threads_mostra[3];

    // Inicializa o semáforo e o mutex
    sem_init(&sem_autorizacoes, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Cria as threads "calcula"
    for (int i = 0; i < 9; i++) {
        pthread_create(&threads_calcula[i], NULL, tarefa_calcula, NULL);
    }

    // Cria as threads "mostra"
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads_mostra[i], NULL, tarefa_mostra, NULL);
    }

    // Espera todas as threads "calcula" terminarem
    for (int i = 0; i < 9; i++) {
        pthread_join(threads_calcula[i], NULL);
    }

    // Espera todas as threads "mostra" terminarem
    for (int i = 0; i < 3; i++) {
        pthread_join(threads_mostra[i], NULL);
    }

    // Destroi o semáforo e o mutex
    sem_destroy(&sem_autorizacoes);
    pthread_mutex_destroy(&mutex);

    return 0;
}
