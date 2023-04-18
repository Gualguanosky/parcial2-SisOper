// PARCIAL 2 SISTEMAS OPERATIVOS 2023
//ALEJANDRO CASTAÑEDA GUALGUAN


//PUNTO 2

#include <stdio.h>
#include <limits.h>


//creamos las dos constantes que es el numero de particiones que tendra nuestro programa
#define MAX_MEM 100
#define MAX_PRO 100

//creamos la funcion firstfit y creamos un bucle con otro buble anidado en los que recorremos los procesos y las particiones y verificamos los casos.
void firstFit(int mem[], int m, int pro[], int j) {
    for (int i = 0; i < j; i++) {
        int allocated = 0;
        for (int k = 0; k < m; k++) {
            if (mem[k] >= pro[i]) {
                printf("Proceso %d asignado a partición %d\n", i + 1, k + 1);
                mem[k] -= pro[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Proceso %d no asignado\n", i + 1);
        }
    }
}
//creamos la funcion bestfit y creamos un bucle con otro buble anidado en los que recorremos los procesos y las particiones y verificamos los casos.
void bestFit(int mem[], int m, int pro[], int j) {
    for (int i = 0; i < j; i++) {
        int min = INT_MAX;
        int index = -1;
        for (int k = 0; k < m; k++) {
            if (mem[k] >= pro[i] && mem[k] - pro[i] < min) {
                min = mem[k] - pro[i];
                index = k;
            }
        }
        if (index != -1) {
            printf("Proceso %d asignado a partición %d\n", i + 1, index + 1);
            mem[index] -= pro[i];
        } else {
            printf("Proceso %d no asignado\n", i + 1);
        }
    }
}
//creamos la funcion worstfit y creamos un bucle con otro buble anidado en los que recorremos los procesos y las particiones y verificamos los casos.
void worstFit(int mem[], int m, int pro[], int j) {
    for (int i = 0; i < j; i++) {
        int max = INT_MIN;
        int index = -1;
        for (int k = 0; k < m; k++) {
            if (mem[k] >= pro[i] && mem[k] - pro[i] > max) {
                max = mem[k] - pro[i];
                index = k;
            }
        }
        if (index != -1) {
            printf("Proceso %d asignado a partición %d\n", i + 1, index + 1);
            mem[index] -= pro[i];
        } else {
            printf("Proceso %d no asignado\n", i + 1);
        }
    }
}

int main() {
    int n, m, j;
    int mem[MAX_MEM], pro[MAX_PRO];

    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &mem[i]);
    }

    scanf("%d", &j);
    for (int i = 0; i < j; i++) {
        scanf("%d", &pro[i]);
    }

    switch(n) {
        case 1:
            firstFit(mem, m, pro, j);
            break;
        case 2:
            bestFit(mem, m, pro, j);
            break;
        case 3:
            worstFit(mem, m, pro, j);
            break;
    }

    return 0;
}
