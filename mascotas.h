#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
typedef struct{
    int id;
    char nombre[51];
    char tipo[31];
    char raza[31];
    int edad;
    float peso;
    char sexo;
    int idCliente;
    int isEmpty;
}eMascotas;


#endif // MASCOTAS_H_INCLUDED

void imprime_mascota(eMascotas listaMascota,eCliente lista_cliente[],int len_cliente);
void imprimir_mascotas(eMascotas listaMascota[],int len,eCliente lista_cliente[],int len_cliente);

int inicializar_mascotas(eMascotas listaMascota[],int len);
int inicializa_all_mascotas(eMascotas listaMascota[],int len);

void imprime_cliente_mascota(eMascotas listaMascota,eCliente listaCliente,int view);
void imprime_all_cliente_mascota(eMascotas lista_mascota[],int len_mascota,eCliente lista_cliente[],int len_cliente);


eMascotas addMascota(int id,char nombre[],char tipo[],char raza[],int edad,float peso,char sexo,int idCliente);
void imprime_duenio(eCliente lista_cliente);
void imprimir_duenios(eCliente lista_cliente[],int len);
int validacion_id_cliente(eCliente lista_cliente[],int len,int id_cliente);

int alta_Mascota(eMascotas lista_mascota[],int len,int id_mascota,eCliente lista_cliente[],int len_cliente);


int buscar_Mascota_por_ID(eMascotas lista_mascota[],int len,int id);
void imprimi_Mascota_por_Indice(eMascotas lista_mascota[],int len,int indice,eCliente lista_cliente[],int len_cliente);
int elimina_Mascota(eMascotas lista_mascota[],int len,int id);
int baja_Mascota(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente);

void modificar_Mascota(eMascotas lista_mascota[],int len,int id,int indice,eCliente lista_cliente[],int len_cliente);
void modificacion_Mascota_por_ID(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente);
