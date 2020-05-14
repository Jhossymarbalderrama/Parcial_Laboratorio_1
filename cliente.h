#include <stdio.h>
#include <stdlib.h>
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    int id;

    char nombre[51];
    char apellido[51];
    char localidad[51];
    int telefono;
    int edad;
    char sexo;

    int isEmpty;
}eCliente;
#endif // CLIENTE_H_INCLUDED

void imprime_cliente(eCliente listaCliente);
void imprimir_clientes(eCliente listaCliente[],int len);

int inicializar_clientes(eCliente listaCliente[],int len);
int inicializa_all_cliente(eCliente listaCliente[],int len);

int buscarLibre_Cliente(eCliente listaCliente[], int len);
eCliente addCliente(int id,char nombre[],char apellido[],char localidad[],int telefono,int edad,char sexo);
int alta_Cliente(eCliente listaCliente[],int len,int id_cliente);

