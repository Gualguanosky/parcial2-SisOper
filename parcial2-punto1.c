// PARCIAL 2 SISTEMAS OPERATIVOS 2023
//ALEJANDRO CASTAÑEDA GUALGUAN


//PUNTO 1
#include <stdio.h>

int main() {
    // comenzamos declarando las variables que necesitamos en el programa
    int Met;
    int Tot_Men;
    int Tam_bloq;
    int Tot_proc;
    int Mem;
    int Int_frag = 0;
    int Ext_frag = 0;
    //pedimos por pantalla los metodos y datos que necesitamos para operar el programa.
    printf("Puedes dar el metodo de entrada (1 for MFT, 2 for MVT): ");
    scanf("%d", &Met);
    
    printf("puedes decir el # de memoria total: ");
    scanf("%d", &Tot_Men);
    
    if (Met == 1) {
        printf("Ingrese el tamaño del bloque: ");
        scanf("%d", &Tam_bloq);
    }
    
    printf("ingrese el numero total de procesos ");
    scanf("%d", &Tot_proc);
    
    // bucle que hace laasignacion de los procesos en memoria 
    for (int i = 0; i < Tot_proc; i++) {
        int Tot_proc;
        printf("ingrese el tamaño del proceso %d: ", i);
        scanf("%d", &Tot_proc);
        
        if (Met == 1) { // proceso MFT
            if (Tot_proc <= Tam_bloq) {
                printf("P%d -> %d se pone en: %d, %d fragmentacion.\n", i, Tot_proc, Tam_bloq, Tam_bloq - Tot_proc);
                Int_frag += Tam_bloq - Tot_proc;
                Mem += Tam_bloq;
            } else {
                printf("P%d -> %d no asignado.\n", i, Tot_proc);
            }
        } else { // proceso MVT
            if (Tot_proc <= Tot_Men - Mem) {
                printf("P%d -> %d se coloca en la memoria \n", i, Tot_proc);
                Mem += Tot_proc;
            } else {
                printf("P%d -> %d no asignado.\n", i, Tot_proc);
                Ext_frag += Tot_proc;
            }
        }
    }
    //imprimimos resultados
    printf("memoria asignada: %d\n", Mem);
    printf("Fragmentacion interna: %d\n", Int_frag);
    printf("Fragmentacion externa: %d\n", Ext_frag);
    
    return 0;
}
