//
// Created by River on 20/6/2022.
//

#ifndef INC_1_7_FRANCOGUARNIERI_HELPER_H
#define INC_1_7_FRANCOGUARNIERI_HELPER_H

#endif //INC_1_7_FRANCOGUARNIERI_HELPER_H

typedef struct ctacte{
    int nro;
    int saldo;
}CtaCte;

typedef struct movimiento{
    int nro;
    int cod;
    int importe;
    struct movimiento* sig;
}Mov;

typedef struct movimientosDiarios{
    int tam;
    Mov* movimientos;
}MovDiarios;

Mov * newMov(int nroCtaCte);

int buscar(int nroCtaCte);

MovDiarios * newMovimientosDiarios(void);

void insertarOrdenado(MovDiarios * nuevoMovDiarios, Mov * nuevoMov);

void imprimirSaldos(MovDiarios  * nuevoMovDiarios);

void imprimirEntradas(MovDiarios  * nuevoMovDiarios);

void imprimirSalidas(MovDiarios  * nuevoMovDiarios);

void imprimirMayorMovDiario(MovDiarios  * nuevoMovDiarios);

