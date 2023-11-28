// funciones.c
#include <stdio.h>
#include "funciones.h"
#include "lecturas.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int leerEnteroPositivo(char* mensaje) {
    int numero;
    do {
        printf("%s", mensaje);
        scanf("%d", &numero);
    } while (numero <= 0);
    return numero;
}

int leerEntero(char* mensaje) {
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);
    return numero;
}

int leerEnteroEntre(char* mensaje, int min, int max) {
    int numero;
    do {
        printf("%s", mensaje);
        scanf("%d", &numero);
    } while (numero < min || numero > max);
    return numero;
}

float leerFlotantePositivo(char* mensaje) {
    float numero;
    do {
        printf("%s", mensaje);
        scanf("%f", &numero);
    } while (numero <= 0);
    return numero;
}

float leerFlotante(char* mensaje) {
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
    return numero;
}

float leerFlotanteEntre(char* mensaje, int min, int max) {
    float numero;
    do {
        printf("%s", mensaje);
        scanf("%f", &numero);
    } while (numero < min || numero > max);
    return numero;
}

float leerCarcaterPositivo(char* mensaje) {
    float caracter;
    do {
        printf("%s", mensaje);
        scanf("%f", &caracter);
    } while (caracter <= 0);
    return caracter;
}
