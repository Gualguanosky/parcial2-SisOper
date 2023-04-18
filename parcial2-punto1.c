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
    
    printf("Enter method (1 for MFT, 2 for MVT): ");
    scanf("%d", &method);
    
    printf("Enter total memory: ");
    scanf("%d", &total_memory);
    
    if (method == 1) {
        printf("Enter block size: ");
        scanf("%d", &block_size);
    }
    
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    
    // Allocate memory to processes
    for (int i = 0; i < num_processes; i++) {
        int process_size;
        printf("Enter size of process %d: ", i);
        scanf("%d", &process_size);
        
        if (method == 1) { // MFT
            if (process_size <= block_size) {
                printf("P%d -> %d is put in %d, %d fragmentation.\n", i, process_size, block_size, block_size - process_size);
                internal_fragmentation += block_size - process_size;
                memory_left += block_size;
            } else {
                printf("P%d -> %d Not allocated.\n", i, process_size);
            }
        } else { // MVT
            if (process_size <= total_memory - memory_left) {
                printf("P%d -> %d is put in Mem.\n", i, process_size);
                memory_left += process_size;
            } else {
                printf("P%d -> %d Not allocated.\n", i, process_size);
                external_fragmentation += process_size;
            }
        }
    }
    
    printf("Memory allocates: %d\n", memory_left);
    printf("Internal fragmentation: %d\n", internal_fragmentation);
    printf("External fragmentation: %d\n", external_fragmentation);
    
    return 0;
}


int main() {
    int method;
    int total_memory;
    int num_processes;
    int memory_left;
    int internal_fragmentation = -1;
    int external_fragmentation = 0;
    
    printf("Enter method (1 for MFT, 2 for MVT): ");
    scanf("%d", &method);
    
    printf("Enter total memory: ");
    scanf("%d", &total_memory);
    
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    
    // Allocate memory to processes
    for (int i = 0; i < num_processes; i++) {
        int process_size;
        printf("Enter size of process %d: ", i);
        scanf("%d", &process_size);
        
        if (process_size <= total_memory - memory_left) {
            printf("P%d -> %d is put in Mem.\n", i, process_size);
            memory_left += process_size;
            if (internal_fragmentation == -1) {
                internal_fragmentation = total_memory - memory_left;
            } else {
                internal_fragmentation = 0;
            }
        } else {
            printf("P%d -> %d Not allocated.\n", i, process_size);
            external_fragmentation += process_size;
        }
    }
    
    printf("Memory allocates: %d\n",
