#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <intrin.h>

#define BILLION 1000000000.0

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

uint64_t rdtsc(){
    return __rdtsc();
}

int main(){
    char param_1 = 'b';
    short param_2;
    int param_3;
    float param_4 = 50.0;

    // Usando clock()
    clock_t begin_clock, end_clock;
    double time_spent_clock;

    // Usando time()
    time_t begin_time, end_time;
    double time_spent_time;

    // Usando clock_gettime()
    struct timespec start, end;
    double time_spent_gettime;

    // Usando rdtsc()
    uint64_t begin_rdtsc, end_rdtsc, cycles_spent;

    // Medindo o tempo de execução para func1
    begin_clock = clock();
    for(int i = 0; i < 100; i++) func1();
    end_clock = clock();
    time_spent_clock = (double)(end_clock - begin_clock) / CLOCKS_PER_SEC;
    printf("\nfunc1 - Tempo de execução com clock(): %f segundos", time_spent_clock);

    begin_time = time(NULL);
    for(int i = 0; i < 100; i++) func1();
    end_time = time(NULL);
    time_spent_time = difftime(end_time, begin_time);
    printf("\nfunc1 - Tempo de execução com time(): %f segundos", time_spent_time);

    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 0; i < 100; i++) func1();
    clock_gettime(CLOCK_REALTIME, &end);
    time_spent_gettime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("\nfunc1 - Tempo de execução com clock_gettime(): %f segundos", time_spent_gettime);

    begin_rdtsc = rdtsc();
    for(int i = 0; i < 100; i++) func1();
    end_rdtsc = rdtsc();
    cycles_spent = (end_rdtsc - begin_rdtsc);
    printf("\nfunc1 - Tempo de execução com rdtsc(): %llu ciclos", cycles_spent);

    // Repita para func2, func3, func4 e func5
    // Exemplo para func2
    begin_clock = clock();
    for(int i = 0; i < 100; i++) param_3 = func2();
    end_clock = clock();
    time_spent_clock = (double)(end_clock - begin_clock) / CLOCKS_PER_SEC;
    printf("\nfunc2 - Tempo de execução com clock(): %f segundos", time_spent_clock);

    begin_time = time(NULL);
    for(int i = 0; i < 100; i++) param_3 = func2();
    end_time = time(NULL);
    time_spent_time = difftime(end_time, begin_time);
    printf("\nfunc2 - Tempo de execução com time(): %f segundos", time_spent_time);

    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 0; i < 100; i++) param_3 = func2();
    clock_gettime(CLOCK_REALTIME, &end);
    time_spent_gettime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("\nfunc2 - Tempo de execução com clock_gettime(): %f segundos", time_spent_gettime);

    begin_rdtsc = rdtsc();
    for(int i = 0; i < 100; i++) param_3 = func2();
    end_rdtsc = rdtsc();
    cycles_spent = (end_rdtsc - begin_rdtsc);
    printf("\nfunc2 - Tempo de execução com rdtsc(): %llu ciclos", cycles_spent);

    // Repita para func3, func4, func5
    // Exemplo para func3
    begin_clock = clock();
    for(int i = 0; i < 100; i++) param_1 = func3(param_1);
    end_clock = clock();
    time_spent_clock = (double)(end_clock - begin_clock) / CLOCKS_PER_SEC;
    printf("\nfunc3 - Tempo de execução com clock(): %f segundos", time_spent_clock);

    begin_time = time(NULL);
    for(int i = 0; i < 100; i++) param_1 = func3(param_1);
    end_time = time(NULL);
    time_spent_time = difftime(end_time, begin_time);
    printf("\nfunc3 - Tempo de execução com time(): %f segundos", time_spent_time);

    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 0; i < 100; i++) param_1 = func3(param_1);
    clock_gettime(CLOCK_REALTIME, &end);
    time_spent_gettime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("\nfunc3 - Tempo de execução com clock_gettime(): %f segundos", time_spent_gettime);

    begin_rdtsc = rdtsc();
    for(int i = 0; i < 100; i++) param_1 = func3(param_1);
    end_rdtsc = rdtsc();
    cycles_spent = (end_rdtsc - begin_rdtsc);
    printf("\nfunc3 - Tempo de execução com rdtsc(): %llu ciclos", cycles_spent);

    // Exemplo para func4
    begin_clock = clock();
    for(int i = 0; i < 100; i++) func4(param_4);
    end_clock = clock();
    time_spent_clock = (double)(end_clock - begin_clock) / CLOCKS_PER_SEC;
    printf("\nfunc4 - Tempo de execução com clock(): %f segundos", time_spent_clock);

    begin_time = time(NULL);
    for(int i = 0; i < 100; i++) func4(param_4);
    end_time = time(NULL);
    time_spent_time = difftime(end_time, begin_time);
    printf("\nfunc4 - Tempo de execução com time(): %f segundos", time_spent_time);

    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 0; i < 100; i++) func4(param_4);
    clock_gettime(CLOCK_REALTIME, &end);
    time_spent_gettime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("\nfunc4 - Tempo de execução com clock_gettime(): %f segundos", time_spent_gettime);

    begin_rdtsc = rdtsc();
    for(int i = 0; i < 100; i++) func4(param_4);
    end_rdtsc = rdtsc();
    cycles_spent = (end_rdtsc - begin_rdtsc);
    printf("\nfunc4 - Tempo de execução com rdtsc(): %llu ciclos", cycles_spent);

    // Exemplo para func5
    begin_clock = clock();
    for(int i = 0; i < 100; i++) param_2 = func5();
    end_clock = clock();
    time_spent_clock = (double)(end_clock - begin_clock) / CLOCKS_PER_SEC;
    printf("\nfunc5 - Tempo de execução com clock(): %f segundos", time_spent_clock);

    begin_time = time(NULL);
    for(int i = 0; i < 100; i++) param_2 = func5();
    end_time = time(NULL);
    time_spent_time = difftime(end_time, begin_time);
    printf("\nfunc5 - Tempo de execução com time(): %f segundos", time_spent_time);

    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 0; i < 100; i++) param_2 = func5();
    clock_gettime(CLOCK_REALTIME, &end);
    time_spent_gettime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("\nfunc5 - Tempo de execução com clock_gettime(): %f segundos", time_spent_gettime);

    begin_rdtsc = rdtsc();
    for(int i = 0; i < 100; i++) param_2 = func5();
    end_rdtsc = rdtsc();
    cycles_spent = (end_rdtsc - begin_rdtsc);
    printf("\nfunc5 - Tempo de execução com rdtsc(): %llu ciclos", cycles_spent);

    return 0;
}
