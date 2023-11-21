#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarMatriz(int filas, int columnas, int matriz[][10]) 
{
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            matriz[i][j] = rand() % 10;  
        }
    }
}

void sumaMatrices(int filas, int columnas, int matriz1[][10], int matriz2[][10], int resultado[][10]) 
{
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void restaMatrices(int filas, int columnas, int matriz1[][10], int matriz2[][10], int resultado[][10]) 
{
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void multiplicacionMatrices(int filas, int columnas, int matriz1[][10], int matriz2[][10], int resultado[][10]) 
{
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas; ++k) 
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void diagonalMatriz(int filas, int columnas, int matriz[][10], int diagonal[]) 
{
    for (int i = 0; i < filas && i < columnas; ++i) 
    {
        diagonal[i] = matriz[i][i];
    }
}

int sumaTriangularSuperior(int filas, int columnas, int matriz[][10]) 
{
    int suma = 0;
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = i + 1; j < columnas; ++j) 
        {
            suma += matriz[i][j];
        }
    }
    return suma;
}

void mostrarMatriz(int filas, int columnas, int matriz[][10]) 
{
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); 
    while (1) 
    {
        printf("\nOperaciones sobre matrices:\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicación\n");
        printf("4. Diagonal\n");
        printf("5. Suma triangular superior\n");
        printf("6. Terminar el programa\n");

        int opcion;
        printf("Selecciona una opción (1-6): ");
        scanf("%d", &opcion);

        if (opcion == 6) {
            printf("Programa terminado.\n");
            break;
        }

        int filas, columnas;
        printf("Ingrese el número de filas de las matrices: ");
        scanf("%d", &filas);
        printf("Ingrese el número de columnas de las matrices: ");
        scanf("%d", &columnas);

        int matriz1[10][10], matriz2[10][10], resultado[10][10], diagonal[10];

        switch (opcion) {
            case 1:
                generarMatriz(filas, columnas, matriz1);
                generarMatriz(filas, columnas, matriz2);
                sumaMatrices(filas, columnas, matriz1, matriz2, resultado);
                break;
            case 2:
                generarMatriz(filas, columnas, matriz1);
                generarMatriz(filas, columnas, matriz2);
                restaMatrices(filas, columnas, matriz1, matriz2, resultado);
                break;
            case 3:
                generarMatriz(filas, columnas, matriz1);
                generarMatriz(filas, columnas, matriz2);
                multiplicacionMatrices(filas, columnas, matriz1, matriz2, resultado);
                break;
            case 4:
                generarMatriz(filas, columnas, matriz1);
                diagonalMatriz(filas, columnas, matriz1, diagonal);
                printf("\nDiagonal de la Matriz 1:\n");
                for (int i = 0; i < (filas, columnas); ++i) {
                    printf("%d ", diagonal[i]);
                }
                printf("\n");
                continue;
            case 5:
                generarMatriz(filas, columnas, matriz1);
                printf("\nSuma triangular superior de la Matriz 1: %d\n", sumaTriangularSuperior(filas, columnas, matriz1));
                continue;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
                continue;
        }

        printf("\nMatriz 1:\n");
        mostrarMatriz(filas, columnas, matriz1);
        printf("\nMatriz 2:\n");
        mostrarMatriz(filas, columnas, matriz2);
        printf("\nResultado:\n");
        mostrarMatriz(filas, columnas, resultado);
    }

    return 0;
}