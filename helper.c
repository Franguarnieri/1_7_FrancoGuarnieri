//
// Created by River on 20/6/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "helper.h"

CtaCte listaCtaCte[]= {{1, 100,},
                          {2, 100},
                          {3, 300},
                          {4, 400},
                          {5, 500}};

MovDiarios * newMovimientosDiarios(){
    MovDiarios * aux=malloc(sizeof(MovDiarios));

    if (aux==NULL){
        printf("\nNo hay memoria disponible.");
        exit (-1);
    }
    aux->tam=0;
    aux->movimientos=NULL;
    return aux;
}

Mov * newMov (nroCtaCte){

        Mov * aux=malloc(sizeof(Mov));

        if (aux==NULL){
            printf("\nNo hay memoria disponible.");
            exit (-1);
        }
        aux->nro=nroCtaCte;
        int pos=buscar(nroCtaCte); //función auxiliar que busca Nro Cta Cte ingresada en el vector que las contiene.
        printf("Ingrese el codigo correspondiente al tipo de movimiento: 1 para indicar ingreso y 2 para indicar salida:");
        scanf("%d",&aux->cod);
        printf("Ingrese el importe del movimiento: ");
        scanf("%d",&aux->importe);
        if(aux->cod==1){
            listaCtaCte[pos].saldo += aux->importe;
            }else listaCtaCte[pos].saldo-=aux->importe;
        aux->sig=NULL;
    return aux;
}

int buscar(int nroCtaCte){      //función auxiliar que busca Nro Cta Cte ingresada en el vector que las contiene.
    if (nroCtaCte== -1) return -1;
    else {
        for (int i = 0; i < sizeof(listaCtaCte)/sizeof(CtaCte); ++i) {
            if (nroCtaCte == listaCtaCte[i].nro){
                return i;
            }
        }
        return -2;
    }
}

void insertarOrdenado(MovDiarios *nuevoMovDiarios,Mov * nuevoMov) {
    if(nuevoMovDiarios->movimientos== NULL){        //1. CASO: no hay elemento alguno en la lista.
        nuevoMovDiarios->movimientos=nuevoMov;      //se inserta como 1er y unico nodo de la lista
    } else {                                        //CASOS: 2. 3. 4. y 5.: SI hay un elemento en la lista y  hay que insertar en forma ordenada.
        Mov * ant=NULL; //por buena pp
        Mov * act=NULL; //por buena pp
        act=nuevoMovDiarios->movimientos;
        ant=act;                                //condición inicial
        while(act != NULL && nuevoMov->nro > act->nro ){  //recorre lista y "avanza" los punteros auxiliares mientras valla encontrando nros menores
            ant=act;    //ant "va siguiendo" a act
            act=act->sig;}
        if(act !=NULL && act->nro == nuevoMov->nro){  //2. CASO: el elemento a insertar coincide con uno de la lista. Lo inserta después.
            nuevoMov->sig=act;
            ant->sig=nuevoMov;
        }else {
            if (act == ant) { //3. CASO: el elemento a insertar es el menor de toda la lista.
                nuevoMovDiarios->movimientos = nuevoMov;
                nuevoMov->sig = act;
            } else {
                if (act == NULL) {  // 4. CASO: el elemento a insertar es el mayor de toda la lista.
                    ant->sig = nuevoMov;
                } else {                // 5. CASO: el elemento a insertar está comprendido entre 2 elementos de la lista.
                    ant->sig = nuevoMov;
                    nuevoMov->sig = act;
                }
            }
        }
    }
    nuevoMovDiarios->tam++;     //By Perico :)
}

void imprimirSaldos(MovDiarios *nuevoMovDiarios) {
    for (int i = 0; i < sizeof(listaCtaCte)/sizeof(CtaCte) ; ++i) {
        printf("\nLa Cuenta Corriente Nro %d tiene saldo $%d ", listaCtaCte[i].nro, listaCtaCte[i].saldo);
    }
}

void imprimirEntradas(MovDiarios *nuevoMovDiarios) {
    if(nuevoMovDiarios->tam == 0){printf("\nNo hay entradas en el dia.");}
    else {
        int entradas=0;
        Mov * aux=NULL;     //buena pp
        aux=nuevoMovDiarios->movimientos;
        for(;aux != NULL; aux=aux->sig){
            if (aux->cod==1) {
                entradas += aux->importe;}
        }
        printf("\nEl total de entradas en el dia es de $%d.", entradas);
    }
}

void imprimirSalidas(MovDiarios *nuevoMovDiarios) {
    if(nuevoMovDiarios->tam == 0) {printf("\nNo hay salidas en el dia."); }
    else {
        int salidas=0;
        Mov * aux=NULL;     //buena pp
        aux=nuevoMovDiarios->movimientos;
        for(;aux != NULL; aux=aux->sig){
            if (aux->cod==2) {
                salidas += aux->importe;}
        }
        printf("\nEl total de salidas en el dia es de $%d.", salidas);
    }
}

void imprimirMayorMovDiario(MovDiarios *nuevoMovDiarios) {
    if(nuevoMovDiarios->tam == 0) { printf("\nNo hubo movimientos en el dia."); }
    else {
        Mov * aux=nuevoMovDiarios->movimientos;
        int mayor=0,cod,nro;
        for(;aux != NULL;aux=aux->sig){
            if (aux->importe > mayor) {
                mayor=aux->importe;
                cod=aux->cod;
                nro=aux->cod;
            }
        }
        if(cod == 1){
            printf("\nEl mayor movimiento del dia fue de la Cta Cte Nro %d, por un importe de $%d correspondiente a un ingreso.",nro, mayor);
        } else { //si es un egreso
            printf("\nEl mayor movimiento del dia fue de la Cta Cte Nro %d, por un importe de $%d correspondiente a un egreso.",nro, mayor);
        }
    }
}


