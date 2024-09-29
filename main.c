#include <stdio.h>
#include <math.h>

#define MAXN 11 // Polinômios de grau 0 até 10

void mostra_polinomio(float polinomio[], int grau);
void limpa_polinomio(float polinomio[]); //Função para limpar vetor de polinômio com valores residuais de operações passadas
void produto_polinomios(float polinomio1[], float polinomio2[], float polinomio3[], int grau1, int grau2, int grauProduto);
int soma_polinomios(float polinomio1[], float polinomio2[], float polinomio3[], int grau1, int grau2);
float calcula_valor(float polinomio[], int grau, float x);

int main(){

    float polinomio1[MAXN], polinomio2[MAXN], polinomio3[MAXN]; // Polinômios referentes a duas entradas e uma saída
    int option;
    
    do{
        
        printf("\n---CALCULADORA DE POLINOMIOS---\n\n");
        printf("1. Calcular valor de polinomio\n");
        printf("2. Calcular soma de polinomios\n");
        printf("3. Calcular produto de polinomios\n");
        printf("4. Sair\n");
        printf("\nOpção ---> ");
        
        scanf("%d", &option);

        if (option == 1)
        {
            int grau;
            float x;
             // leitura do grau do polinômio 
            printf("Insira o grau do polinomio (Min = 0; Max = 10)\n");
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
            scanf("%f", &x);

            
            float resultado = calcula_valor(polinomio1, grau, x);
            printf("P(%g) = %g\n", x, resultado);

            limpa_polinomio(polinomio1);
        }

        else if (option == 2)
        {
            int grau1, grau2, grauSoma;

            printf("Insira o grau do primeiro polinomio (Min = 0; Max = 10)\n");
            do{
                printf("---> ");
                scanf("%d", &grau1);
                if (grau1 < 0 || grau1 > 10)
                {
                    printf("Valor nao suportado. (Min = 0; Max = 10)\n\n ");
                }
                
            } while (grau1 < 0 || grau1 > 10);

            // leitura do primeiro polinômio
            printf("Insira os coeficientes do polinomio de forma crescente\n---> ");
            for (int i = 0; i < grau1 + 1; i++)
            {
                scanf("%f", &polinomio1[i]);
            }

            printf("Insira o grau do polinomio 2 (Min = 0; Max = 10)\n");
            do{
                printf("---> ");
                scanf("%d", &grau2);
                if (grau2 < 0 || grau2 > 10)
                {
                    printf("Valor nao suportado. (Min = 0; Max = 10)\n\n ");
                }
                
            } while (grau2 < 0 || grau2 > 10);

            // leitura do polinômio 2
            printf("Insira os coeficientes do polinomio de forma crescente\n---> ");
            for (int i = 0; i < grau2 + 1; i++)
            {
                scanf("%f", &polinomio2[i]);
            }

            grauSoma = soma_polinomios(polinomio1, polinomio2, polinomio3, grau1, grau2);
            printf("\nSoma entre:\n");
            mostra_polinomio(polinomio1, grau1);
            mostra_polinomio(polinomio2, grau2);
            printf("\nResultado: ");
            mostra_polinomio(polinomio3, grauSoma);

            limpa_polinomio(polinomio1);
            limpa_polinomio(polinomio2);
            limpa_polinomio(polinomio3);

        }

        else if (option == 3)
        {
            int grau1, grau2, grauProduto;

            printf("Insira o grau do primeiro polinomio (Min = 0; Max = 10)\n");
            do{
                printf("---> ");
                scanf("%d", &grau1);
                if (grau1 < 0 || grau1 > 10)
                {
                    printf("Valor nao suportado. (Min = 0; Max = 10)\n\n ");
                }
                
            } while (grau1 < 0 || grau1 > 10);

            // leitura do primeiro polinômio
            printf("Insira os coeficientes do polinomio de forma crescente\n---> ");
            for (int i = 0; i < grau1 + 1; i++)
            {
                scanf("%f", &polinomio1[i]);
            }

            printf("Insira o grau do polinomio 2 (Min = 0; Max = 10)\n");
            do{
                printf("---> ");
                scanf("%d", &grau2);
                if (grau2 < 0 || grau2 > 10)
                {
                    printf("Valor nao suportado. (Min = 0; Max = 10)\n\n ");
                }
                
            } while (grau2 < 0 || grau2 > 10);

            // leitura do polinômio 2
            printf("Insira os coeficientes do polinomio de forma crescente\n---> ");
            for (int i = 0; i < grau2 + 1; i++)
            {
                scanf("%f", &polinomio2[i]);
            }

            grauProduto = grau1 * grau2;

            produto_polinomios(polinomio1, polinomio2, polinomio3, grau1, grau2, grauProduto);

            printf("\nProduto entre:\n");
            mostra_polinomio(polinomio1, grau1);
            mostra_polinomio(polinomio2, grau2);
            printf("\nResultado: ");
            mostra_polinomio(polinomio3, grauProduto);

            limpa_polinomio(polinomio1);
            limpa_polinomio(polinomio2);
            limpa_polinomio(polinomio3);
        }
        else if (option != 4)
        {
            printf("Opção inválida");
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

float calcula_valor(float polinomio[], int grau, float x){

    float resultado = 0;

    for(int i = 0; i <= grau; i++)
    {
        resultado += polinomio[i] * pow(x, i);
    }

    return resultado;
}

int soma_polinomios(float polinomio1[], float polinomio2[], float polinomio3[], int grau1, int grau2){

    int maiorGrau = grau1;
    if (grau1 < grau2)
    {
        maiorGrau = grau2;
    }

    for(int i = 0; i <= maiorGrau; i++)
    {
        polinomio3[i] = polinomio1[i] + polinomio2[i];
    }

    return maiorGrau; //grau do poliômio resultante é o mesmo do maior grau entre os dois que estão sendo somadados
}

void produto_polinomios(float polinomio1[], float polinomio2[], float polinomio3[], int grau1, int grau2, int grauProduto){

}


void limpa_polinomio(float polinomio[])
{
    for (int i = 0; i < MAXN; i++)
    {
        polinomio[i] = 0;
    }
}