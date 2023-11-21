#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int N;
    printf("Ingrese el tamaño de la matriz (N x N): ");
    scanf("%d", &N);

    int matriz[N][N];
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            matriz[i][j] = rand() % 10;  
        }
    }

    printf("\nMatriz creada:\n");
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int sumaTriangularSuperior = 0;
    printf("\nElementos del triángulo superior:\n");
    for (int i = 0; i < N; ++i) 
    {
        for (int j = i; j < N; ++j) 
        {
            printf("%d ", matriz[i][j]);
            sumaTriangularSuperior += matriz[i][j];
        }
        printf("\n");
    }

    printf("\nSuma del triángulo superior: %d\n", sumaTriangularSuperior);

    return 0;
}