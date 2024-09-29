#include <stdio.h>
#include <math.h>

#define MAXN 11 // Polinômios de grau 0 até 10

void mostra_polinomio(float polinomio[], int grau);
float calcula_valor(float polinomio[], int grau, int x);

int main(){

    float polinomio1[MAXN], polinomio2[MAXN], polinomio3[MAXN];
    int option, grau, x;
    
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
            for (int i = 0; i < grau + 1; i++)
            {
                scanf("%f", &polinomio1[i]);
            }

            mostra_polinomio(polinomio1, grau);
            printf("\nInsira o valor da incognita X\n---> ");
            scanf("%d", &x);

            
            float resultado = calcula_valor(polinomio1, grau, x);
            printf("P(%d) = %g\n", x, resultado);
        }

    
    } while (option != 4);

}

void mostra_polinomio(float polinomio[], int grau){
    
    printf("P(x) = ");
    for(int i = grau; i >= 0; i--)
    {
        if(i == 0)
        {
            printf("%g\n", polinomio[i]);
        }
        else if (polinomio[i] != 0)
        {

            printf("%gx^%d + ", polinomio[i], i);
        }
    }

}

float calcula_valor(float polinomio[], int grau, int x){

    float resultado = 0;

    for(int i = 0; i <= grau; i++)
    {
        resultado += polinomio[i] * pow(x, i);
    }

    return resultado;
}