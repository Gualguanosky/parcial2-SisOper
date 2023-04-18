// PARCIAL 2 SISTEMAS OPERATIVOS 2023
//ALEJANDRO CASTAÑEDA GUALGUAN


//PUNTO 2



#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

void first_fit(int partitions[], int num_partitions, int processes[], int num_processes);
void best_fit(int partitions[], int num_partitions, int processes[], int num_processes);
void worst_fit(int partitions[], int num_partitions, int processes[], int num_processes);

int main() {
    int method, num_partitions, num_processes, i;
    int partitions[MAX_PARTITIONS], processes[MAX_PROCESSES];

    // Leer entrada
    scanf("%d", &method);
    scanf("%d", &num_partitions);
    for (i = 0; i < num_partitions; i++) {
        scanf("%d", &partitions[i]);
    }
    scanf("%d", &num_processes);
    for (i = 0; i < num_processes; i++) {#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

void first_fit(int partitions[], int num_partitions, int processes[], int num_processes);
void best_fit(int partitions[], int num_partitions, int processes[], int num_processes);
void worst_fit(int partitions[], int num_partitions, int processes[], int num_processes);

int main() {
    int method, num_partitions, num_processes, i;
    int partitions[MAX_PARTITIONS], processes[MAX_PROCESSES];

    // Leer entrada
    scanf("%d", &method);
    scanf("%d", &num_partitions);
    for (i = 0; i < num_partitions; i++) {
        scanf("%d", &partitions[i]);
    }
    scanf("%d", &num_processes);
    for (i = 0; i < num_processes; i++) {
        scanf("%d", &processes[i]);
    }

    // Ejecutar método de asignación de memoria
    switch (method) {
        case 1:
            first_fit(partitions, num_partitions, processes, num_processes);
            break;
        case 2:
            best_fit(partitions, num_partitions, processes, num_processes);
            break;
        case 3:
            worst_fit(partitions, num_partitions, processes, num_processes);
            break;
        default:
            printf("Método no válido.\n");
            break;
    }

    return 0;
}

void first_fit(int partitions[], int num_partitions, int processes[], int num_processes) {
    int i, j, partition_size, process_size;
    int partition_used[num_partitions];

    for (i = 0; i < num_processes; i++) {
        process_size = processes[i];
        for (j = 0; j < num_partitions; j++) {
            if (!partition_used[j]) {
                partition_size = partitions[j];
                if (process_size <= partition_size) {
                    partition_used[j] = 1;
                    printf("P%d -> %d se pone en %d, %d particiones.\n", i, process_size, partition_size, j+1);
                    break;
                }#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

void first_fit(int partitions[], int num_partitions, int processes[], int num_processes);
void best_fit(int partitions[], int num_partitions, int processes[], int num_processes);
void worst_fit(int partitions[], int num_partitions, int processes[], int num_processes);

int main() {
    int method, num_partitions, num_processes, i;
    int partitions[MAX_PARTITIONS], processes[MAX_PROCESSES];

    // Leer entrada
    scanf("%d", &method);
    scanf("%d", &num_partitions);
    for (i = 0; i < num_partitions; i++) {
        scanf("%d", &partitions[i]);
    }
    scanf("%d", &num_processes);
    for (i = 0; i < num_processes; i++) {
        scanf("%d", &processes[i]);
    }

    // Ejecutar método de asignación de memoria
    switch (method) {
        case 1:
            first_fit(partitions, num_partitions, processes, num_processes);
            break;
        case 2:
            best_fit(partitions, num_partitions, processes, num_processes);
            break;
        case 3:
            worst_fit(partitions, num_partitions, processes, num_processes);
            break;
        default:
            printf("Método no válido.\n");
            break;
    }

    return 0;
}

void first_fit(int partitions[], int num_partitions, int processes[], int num_processes) {
    int i, j, partition_size, process_size;
    int partition_used[num_partitions];

    for (i = 0; i < num_processes; i++) {
        process_size = processes[i];
        for (j = 0; j < num_partitions; j++) {
            if (!partition_used[j]) {
                partition_size = partitions[j];
                if (process_size <= partition_size) {
                    partition_used[j] = 1;
                    printf("P%d -> %d se pone en %d, %d particiones.\n", i, process_size, partition_size, j+1);
                    break;
                }
            }
        }
        if (j == num_partitions) {
            printf("No se puede asignar %d a ninguna partición disponible.\n", process_size);
        }
    }
}

void best_fit(int partitions[], int num_partitions, int processes[], int num_processes) {
    int i, j, partition_size, process_size, best_fit_index;
    int partition_used[num_partitions];

    for (i = 0; i < num_processes; i++) {
        process_size = processes[i];
        best_fit_index = -1;
        for (j = 0; j < num_partitions; j++) {
            if (!partition_used[j]) {
                partition_size = partitions[j];
                if (process_size <= partition_size && (best_fit_index == -1 || partition_size < partitions[best_fit_index])) {
                    best_fit_index = j;
                }
            }
        }
        if (best_fit_index == -1) {
            printf("No se puede asignar %d a ninguna partición disponible.\n", process_size);
        } else {
            partition_used[best_fit_index] = 1;
            printf("P%d -> %d se pone en %d, %d particiones.\n", i, process_size, partitions[best_fit_index], best_fit_index+1);
        }
    }
}

void worst_fit(int partitions[], int num_partitions
            }
        }
        if (j == num_partitions) {
            printf("No se puede asignar %d a ninguna partición disponible.\n", process_size);
        }
    }
}

void best_fit(int partitions[], int num_partitions, int processes[], int num_processes) {
    int i, j, partition_size, process_size, best_fit_index;
    int partition_used[num_partitions];

    for (i = 0; i < num_processes; i++) {
        process_size = processes[i];
        best_fit_index = -1;
        for (j = 0; j < num_partitions; j++) {
            if (!partition_used[j]) {
                partition_size = partitions[j];
                if (process_size <= partition_size && (best_fit_index == -1 || partition_size < partitions[best_fit_index])) {
                    best_fit_index = j;
                }
            }
        }
        if (best_fit_index == -1) {
            printf("No se puede asignar %d a ninguna partición disponible.\n", process_size);
        } else {
            partition_used[best_fit_index] = 1;
            printf("P%d -> %d se pone en %d, %d particiones.\n", i, process_size, partitions[best_fit_index], best_fit_index+1);
        }
    }
}

void worst_fit(int partitions[], int num_partitions
        scanf("%d", &processes[i]);
    }

    // Ejecutar método de asignación de memoria
    switch (method) {
        case 1:
            first_fit(partitions, num_partitions, processes, num_processes);
            break;
        case 2:
            best_fit(partitions, num_partitions, processes, num_processes);
            break;
        case 3:
            worst_fit(partitions, num_partitions, processes, num_processes);
            break;
        default:
            printf("Método no válido.\n");
            break;
    }

    return 0;
}

void first_fit(int partitions[], int num_partitions, int processes[], int num_processes) {
    int i, j, partition_size, process_size;
    int partition_used[num_partitions];

    for (i = 0; i < num_processes; i++) {
        process_size = processes[i];
        for (j = 0; j < num_partitions; j++) {
            if (!partition_used[j]) {
                partition_size = partitions[j];
                if (process_size <= partition_size) {
                    partition_used[j] = 1;
                    printf("P%d -> %d se pone en %d, %d particiones.\n", i, process_size, partition_size, j+1);
                    break;
                }
            }
        }
        if (j == num_partitions) {
            printf("No se puede asignar %d a ninguna partición disponible.\n", process_size);
        }
    }
}

void best_fit(int partitions[], int num_partitions, int processes[], int num_processes) {
    int i, j, partition_size, process_size, best_fit_index;
    int partition_used[num_partitions];

    for (i = 0; i < num_processes; i++) {
        process_size = processes[i];
        best_fit_index = -1;
        for (j = 0; j < num_partitions; j++) {
            if (!partition_used[j]) {
                partition_size = partitions[j];
                if (process_size <= partition_size && (best_fit_index == -1 || partition_size < partitions[best_fit_index])) {
                    best_fit_index = j;
                }
            }
        }
        if (best_fit_index == -1) {
            printf("No se puede asignar %d a ninguna partición disponible.\n", process_size);
        } else {
            partition_used[best_fit_index] = 1;
            printf("P%d -> %d se pone en %d, %d particiones.\n", i, process_size, partitions[best_fit_index], best_fit_index+1);
        }
    }
}

void worst_fit(int partitions[], int num_partitions