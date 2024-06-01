#include <stdio.h>

// Función para intercambiar dos caracteres en un array de caracteres
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Función recursiva para generar todas las permutaciones posibles
void permute(char *row, int l, int r) {
    if (l == r) { // Si hemos llegado a una permutación completa
        // Imprime la permutación
        for (int i = 1; i <= r; i++) {
            printf("%c", row[i]);
        }
        printf(" ");
    } else {
        for (int i = l; i <= r; i++) {
            swap(&row[l], &row[i]); // Intercambia el elemento en la posición l con el elemento en la posición i
            permute(row, l + 1, r); // Llama recursivamente para el siguiente índice
            swap(&row[l], &row[i]); // Restaura el array al estado anterior para probar otra permutación
        }
    }
}

int main() {
    int n;
    printf("Ingrese el número máximo (n): ");
    scanf("%d", &n);
    
    char row[n + 1]; // Creamos un array de caracteres de tamaño n+1 para almacenar los números del 1 al n
    row[0] = 'x'; // Agregamos un carácter ficticio al principio para simplificar los índices
    for (int i = 1; i <= n; i++) {
        row[i] = '0' + i; // Inicializamos el array con los números del 1 al n
    }

    printf("Permutaciones:\n");
    permute(row, 1, n); // Llama a la función para generar las permutaciones empezando desde la posición 1
    return 0;
}