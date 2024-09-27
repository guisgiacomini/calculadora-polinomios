#include <stdio.h>

#define MAXN 11 // Polinômios de grau 0 até 10

void mostra_polinomio(int polinomio[], int grau);
int calcula_valor(int polinomio[], int grau, int x);

int main(){

    int polinomio1[MAXN], polinomio2[MAXN], polinomio3[MAXN], option, grau, x;
    
    do{
        
        printf("---CALCULADORA DE POLINOMIOS---\n\n");
        printf("1. Calcular valor de polinomio\n");
        printf("2. Calcular soma de polinomios\n");
        printf("3. Calcular produto de polinomios\n");
        printf("4. Sair\n");
        printf("\nOpção ---> ");
        
        scanf("%d", &option);

        if (option == 1)
        {
             // leitura do grau do polinômio 
            printf("Insira o grau do polinomio para realizar operacoes (Min = 0; Max = 10)\n");
            do{
                printf("---> ");
                scanf("%d", &grau);
                if (grau < 0 || grau > 10)
                {
                    printf("Valor nao suportado. (Min = 0; Max = 10)\n\n ");
                }
                
            } while (grau < 0 || grau > 10);

            // leitura do polinômio
            printf("Insira os coeficientes do polinomio de forma crescente\n---> ");
            for (int i = 0; i < grau; i++)
            {
                scanf("%d", &polinomio1[i]);
            }

            mostra_polinomio(polinomio1, grau);
            printf("Insira o valor da incognita X\n---> ");
            scanf("%d", &x);

            
            int resultado = calcula_valor(polinomio1, grau, x);



        }

    
    } while (option != 4);

}

void mostra_polinomio(int polinomio[], int grau){
    
    for(int i = grau - 1; i >= 0; i--)
    {
        if(i == 0)
        {
            printf("%d\n", polinomio[i]);
        }
        else if (polinomio[i] != 0)
        {
            printf("%dx^%d + ", polinomio[i], i);
        }
    }

}

int calcula_valor(int polinomio[], int grau, int x){

}