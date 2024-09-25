#include <stdio.h>

#define MAXN 11 // Polinômios de grau 0 até 10

int main(){
    int polinomio[MAXN];
    int option;

    do{
        printf("---CALCULADORA DE POLINOMIOS---\n\n");
        printf("1. Calcular valor de polinomio\n");
        printf("2. Calcular soma de polinomios\n");
        printf("3. Calcular produto de polinomios\n");
        printf("4. Sair\n");
        printf("\nOpção ---> ");
        
        scanf("%d", &option);

    
    } while (option != 4);

}