// PARCIAL 2 SISTEMAS OPERATIVOS 2023
//ALEJANDRO CASTAÑEDA GUALGUAN


//PUNTO 1
#include <stdio.h>

int main() {
    int method;
    int total_memory;
    int block_size;
    int num_processes;
    int memory_left;
    int internal_fragmentation = 0;
    int external_fragmentation = 0;
    
    printf("Puedes dar el metodo de entrada (1 for MFT, 2 for MVT): ");
    scanf("%d", &method);
    
    printf("puedes decir el # de memoria total: ");
    scanf("%d", &total_memory);
    
    if (method == 1) {
        printf("Ingrese el tamaño del bloque: ");
        scanf("%d", &block_size);
    }
    
    printf("ingrese el numero total de procesos ");
    scanf("%d", &num_processes);
    
    // Allocate memory to processes
    for (int i = 0; i < num_processes; i++) {
        int process_size;
        printf("ingrese el tamaño del proceso %d: ", i);
        scanf("%d", &process_size);
        
        if (method == 1) { // MFT
            if (process_size <= block_size) {
                printf("P%d -> %d se pone en: %d, %d fragmentacion.\n", i, process_size, block_size, block_size - process_size);
                internal_fragmentation += block_size - process_size;
                memory_left += block_size;
            } else {
                printf("P%d -> %d no asignado.\n", i, process_size);
            }
        } else { // MVT
            if (process_size <= total_memory - memory_left) {
                printf("P%d -> %d se coloca en la memoria \n", i, process_size);
                memory_left += process_size;
            } else {
                printf("P%d -> %d no asignado.\n", i, process_size);
                external_fragmentation += process_size;
            }
        }
    }
    
    printf("memoria asignada: %d\n", memory_left);
    printf("Fragmentacion interna: %d\n", internal_fragmentation);
    printf("Fragmentacion externa: %d\n", external_fragmentation);
    
    return 0;
}
