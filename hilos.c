#include <pthread.h>
#include <stdio.h>
int saldo;

void* holaHilo(){
    printf("Hola desde el hilo\n");
    pthread_exit(NULL);
}

void* incrementaSaldo(){
    printf("El saldo actual es: %d\n", saldo);
    saldo += 100;
    printf("El nuevo saldo es: %d\n", saldo);
    pthread_exit(NULL);
}

int main(){
    pthread_t t;
    saldo = 0;
    for(int i = 0; i < 1000; i++)
        pthread_create(&t, NULL, incrementaSaldo, NULL);
    pthread_exit(NULL);
}