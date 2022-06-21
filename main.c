#include <stdio.h>
#include "helper.h"

int main() {

    MovDiarios * nuevoMovDiarios = newMovimientosDiarios();

    int nroCtaCte=0;
    while(nroCtaCte != -1){
        do{
            printf("\nIngrese el  Nro de la cuenta corriente (Ingrese -1 para finalizar): ");
            scanf("%d", &nroCtaCte);
            if(buscar(nroCtaCte)==-2)
                printf("\nEl  codigo de la cuenta corriente ingresado no existe.");
        } while(buscar(nroCtaCte)==-2);

        if (nroCtaCte != -1){
            insertarOrdenado(nuevoMovDiarios,newMov(nroCtaCte));
        }
    }


    imprimirSaldos(nuevoMovDiarios);
    imprimirEntradas(nuevoMovDiarios);
    imprimirSalidas(nuevoMovDiarios);
    imprimirMayorMovDiario(nuevoMovDiarios);

    return 0;
}
