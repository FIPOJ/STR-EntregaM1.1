#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func1(){
    int x, y, z;
    y = 3;
    z = 4;
    x = y + z;
}

int func2(){
    int x, y, z;
    y = 3;
    z = 4;
    x = y + z;
    return x;
}

char func3(char param){
    char x, y, z;
    if(param == 'a'){
        y = 3;
        z = 4;
        x = y + z;
    } else {
        y = 5;
        z = 5;
        x = y + z;
    }
    if(x == 10){
        return 'a';
    } else {
        return 'b';
    }
}

void func4(float param){
    printf("\nThe parameter is: %.2f", param);
}

short func5(){
    int temp_param;
    printf("\nValue to temp_param will be 15: ");
    temp_param = 15;
    return ((short)temp_param);
}

int main(){
    char param_1 = 'b';
    short param_2;
    int param_3;
    float param_4 = 50.0;

    clock_t begin, end;
    double time_spent;
    int num_samples = 100;
    
    double average_times[5] = {0};
    double best_times[5] = {1e10, 1e10, 1e10, 1e10, 1e10};  // Inicializar com um valor alto
    double worst_times[5] = {0};

    // Função para medir o tempo de execução e armazenar os resultados
    for (int sample = 0; sample < num_samples; sample++) {
        // func1
        begin = clock();
        func1();
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        average_times[0] += time_spent;
        if (time_spent < best_times[0]) best_times[0] = time_spent;
        if (time_spent > worst_times[0]) worst_times[0] = time_spent;

        // func2
        begin = clock();
        param_3 = func2();
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        average_times[1] += time_spent;
        if (time_spent < best_times[1]) best_times[1] = time_spent;
        if (time_spent > worst_times[1]) worst_times[1] = time_spent;

        // func3
        begin = clock();
        param_1 = func3(param_1);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        average_times[2] += time_spent;
        if (time_spent < best_times[2]) best_times[2] = time_spent;
        if (time_spent > worst_times[2]) worst_times[2] = time_spent;

        // func4
        begin = clock();
        func4(param_4);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        average_times[3] += time_spent;
        if (time_spent < best_times[3]) best_times[3] = time_spent;
        if (time_spent > worst_times[3]) worst_times[3] = time_spent;

        // func5
        begin = clock();
        param_2 = func5();
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        average_times[4] += time_spent;
        if (time_spent < best_times[4]) best_times[4] = time_spent;
        if (time_spent > worst_times[4]) worst_times[4] = time_spent;
    }

    // Calcular a média para cada função
    for (int i = 0; i < 5; i++) {
        average_times[i] /= num_samples;
    }

    // Exibir os resultados
    printf("\nMédias de tempo de execução (em segundos):");
    printf("\nfunc1 - Média: %f, Melhor: %f, Pior: %f", average_times[0], best_times[0], worst_times[0]);
    printf("\nfunc2 - Média: %f, Melhor: %f, Pior: %f", average_times[1], best_times[1], worst_times[1]);
    printf("\nfunc3 - Média: %f, Melhor: %f, Pior: %f", average_times[2], best_times[2], worst_times[2]);
    printf("\nfunc4 - Média: %f, Melhor: %f, Pior: %f", average_times[3], best_times[3], worst_times[3]);
    printf("\nfunc5 - Média: %f, Melhor: %f, Pior: %f", average_times[4], best_times[4], worst_times[4]);

    // Determinar a função mais rápida e mais lenta
    int fastest_index = 0;
    int slowest_index = 0;

    for (int i = 1; i < 5; i++) {
        if (average_times[i] < average_times[fastest_index]) {
            fastest_index = i;
        }
        if (average_times[i] > average_times[slowest_index]) {
            slowest_index = i;
        }
    }

    printf("\n\nFunção mais rápida: func%d", fastest_index + 1);
    printf("\nFunção mais lenta: func%d\n", slowest_index + 1);

    return 0;
}
