// PARCIAL 2 SISTEMAS OPERATIVOS 2023
//ALEJANDRO CASTAÑEDA GUALGUAN


//PUNTO 1




#include <stdio.h>

int main() {
    int method, mem_total, block_size, num_processes;
    printf("Ingrese el método (1 = MFT, 2 = MVT): ");
    scanf("%d", &method);
    printf("Ingrese la memoria total: ");
    scanf("%d", &mem_total);
    printf("Ingrese el tamaño del bloque: ");
    scanf("%d", &block_size);
    printf("Ingrese el número de procesos: ");
    scanf("%d", &num_processes);

    int num_blocks = mem_total / block_size;
    int mem_used = 0;
    int internal_frag = 0;
    int external_frag = 0;
    int blocks[num_blocks];
    for (int i = 0; i < num_blocks; i++) {
        blocks[i] = -1;  // -1 indica que el bloque está libre
    }

    printf("\n");

    for (int i = 0; i < num_processes; i++) {
        int size;
        printf("Ingrese el tamaño del proceso P%d: ", i);
        scanf("%d", &size);

        int assigned = 0;
        for (int j = 0; j < num_blocks; j++) {
            if (blocks[j] == -1) {
                if (size <= block_size) {
                    blocks[j] = i;
                    mem_used += block_size;
                    internal_frag += block_size - size;
                    assigned = 1;
                    printf("P%d -> %d se pone en %d, %d fragmentación.\n", i, size, j * block_size, block_size - size);
                    break;
                }
            }
        }
        if (!assigned) {
            printf("P%d -> %d No asignado.\n", i, size);
            external_frag += size;
        }
    }

    printf("\nAsignaciones de memoria: %d\n", mem_used);
    printf("Fragmentación interna: %d\n", internal_frag);
    printf("Fragmentación externa: %d\n", external_frag);

    return 0;
}