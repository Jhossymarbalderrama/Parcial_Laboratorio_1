#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
typedef struct{
    int id;
    char nombre[51];
    //char tipo[31];
    int idtipo;
    //char raza[31];
    int idraza;
    int edad;
    float peso;
    char sexo;
    int idCliente;
    int isEmpty;
}eMascotas;

typedef struct{
   int id;
   char tipo[31];
   int isEmpty;
}eTipo;

typedef struct{
    int id;
    char raza[31];
    int isEmpty;
}eRaza;

#endif // MASCOTAS_H_INCLUDED

void imprime_mascota(eMascotas listaMascota,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);
void imprimir_mascotas(eMascotas listaMascota[],int len,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);

int inicializar_mascotas(eMascotas listaMascota[],int len);
int inicializa_all_mascotas(eMascotas listaMascota[],int len);

void imprime_cliente_mascota(eMascotas listaMascota,eCliente listaCliente,int view);
void imprime_all_cliente_mascota(eMascotas lista_mascota[],int len_mascota,eCliente lista_cliente[],int len_cliente);


eMascotas addMascota(int id,char nombre[],int tipo,int raza,int edad,float peso,char sexo,int idCliente);
void imprime_duenio(eCliente lista_cliente);
void imprimir_duenios(eCliente lista_cliente[],int len);
int validacion_id_cliente(eCliente lista_cliente[],int len,int id_cliente);

int alta_Mascota(eMascotas lista_mascota[],int len,int id_mascota,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);

int verificacion_Id(eMascotas lista_mascota[],int len,int id);
int existe_ID(eMascotas lista_mascota[],int len,int id);
int buscar_Mascota_por_ID(eMascotas lista_mascota[],int len,int id);
void imprimi_Mascota_por_Indice(eMascotas lista_mascota[],int len,int indice,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);
int elimina_Mascota(eMascotas lista_mascota[],int len,int id);
int baja_Mascota(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);

void modificar_Mascota(eMascotas lista_mascota[],int len,int id,int indice,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);
void modificacion_Mascota_por_ID(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);

/**Cliente - Mascotas*/
/**int buscar_Cliente_por_ID(eCliente listaCliente[],int len,int id);*/
/**void imprimi_Cliente_por_Indice(eCliente listaCliente[],int len,int indice);*/
/**int elimina_Cliente(eCliente listaCliente[],int len,int id);*/
int baja_Cliente(eCliente listaCliente[],int len,eMascotas lista_Mascota[],int len_Mascota);
int busco_y_elimino_Mascotas_Por_ID_Cliente(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCliente[],int len_Cliente,int id_Cliente);

void ordena_mascotas_por_tipo(eMascotas lista_Mascotas[],int len_Mascotas,eCliente listaCliente[],int len_Cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);

/**11*/void listar_Cliente_con_mas_de_una_Mascota(eCliente listaCliente[],int len_Cliente,eMascotas lista_Mascota[],int len_Mascota);
int busca_mascotas_por_ID_Cliente(eMascotas lista_Mascota[],int len_Mascota,int id_cliente);

/**12*/void listar_mascotas_mas_de_3_anios(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCliente[],int len_Cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);

/**13*/void listar_mascotas_por_tipo(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCliente[],int len_Cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza);

/**14*/void ordena_duenios_por_cantidad_mascotas(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCiente[],int len_Cliente);
int cantidad_de_mascota_por_cliente(eMascotas lista_Mascota[],int len_Mascotan,int id_Cliente);

/**15*/void ordena_duenios_por_cantidad_mascotas_y_nombre(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCiente[],int len_Cliente);

/**16*/void promedio_Edad_Mascotas(eMascotas lista_Mascota[],int len_Mascota);
int cantidad_de_mascotas(eMascotas lista_Mascota[],int len_Mascota);
int suma_de_Edades_Mascotas(eMascotas lista_Mascota[],int len_Mascota);

/**17*/void promedio_Edad_Mascotas_por_Tipo(eMascotas lista_Mascota[],int len_Mascota,eTipo lista_tipo[],int len_tipo);
int cantidad_de_mascotas_por_tipo(eMascotas lista_Mascota[],int len_Mascota,int tipo);
int suma_de_Edades_Mascotas_por_tipo(eMascotas lista_Mascota[],int len_Mascota,int tipo);

/**Otras Estructuras TIPO Y RAZA*/
/**TIPO*/
int inicializar_tipos(eTipo lista_Tipo[],int len_Tipo);
int inicializar_all_tipos(eTipo lista_Tipo[],int len_Tipo);

void imprime_tipo(eTipo lista_Tipo);
void imprime_all_tipos(eTipo lista_Tipo[],int len_Tipo);

/**RAZA*/
int inicializar_razas(eRaza lista_Raza[],int len_Raza);
int inicializar_all_razas(eRaza lista_Raza[],int len_Raza);

void imprime_raza(eRaza lista_Raza);
void imprime_all_razas(eRaza lista_Raza[],int len_Razas);


