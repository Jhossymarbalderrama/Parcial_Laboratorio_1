#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "hardcodeo.h"
#include "input.h"

#define CLI 10 /**Clientes 5 solo cargados*/
#define MAS 20 /**Mascotas*/
#define TIP 5 /**Tipo de Mascotas*/
#define RAZ 10 /**Raza de Mascotas*/

#include "cliente.h"
#include "mascotas.h"

int main()
{
    eCliente lista_cliente[CLI];
    eMascotas lista_mascotas[MAS];
    eTipo lista_tipo[TIP];
    eRaza lista_raza[RAZ];
    char seguir = 'n';
    int id_Mascota = 12;
    int id_Cliente = 6;
    int flag = 0;


    if(inicializar_clientes(lista_cliente,CLI) == 0)
    {
        if(inicializar_mascotas(lista_mascotas,MAS)== 0)
        {
            if(inicializar_tipos(lista_tipo,TIP) == 0)
            {
                if(inicializar_razas(lista_raza,RAZ) == 0)
                {
                    do
                    {
                        if(flag == 0){
                            harcodeo_Cliente(lista_cliente);
                            harcodeo_Mascotas(lista_mascotas);
                            harcodeo_Tipo(lista_tipo);
                            harcodeo_Raza(lista_raza);
                            flag = 1;
                        }
                        switch(menu())
                        {
                        case 1:
                            system("cls");
                            imprimir_clientes(lista_cliente,CLI);
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            imprimir_mascotas(lista_mascotas,MAS,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ);
                            system("pause");
                            break;
                        case 3:
                            imprime_all_cliente_mascota(lista_mascotas,MAS,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ);
                            break;
                        case 4:
                            if(alta_Mascota(lista_mascotas,MAS, id_Mascota,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ) == 0)
                            {
                                printf("\n [ - La Mascota se dio de alta Exitosamente - ]\n\n");
                                system("pause");
                                id_Mascota++;
                            }
                            break;
                        case 5:
                            if(baja_Mascota(lista_mascotas,MAS,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ) == 0)
                            {
                                id_Mascota--;
                            }
                            break;
                        case 6:
                            modificacion_Mascota_por_ID(lista_mascotas,MAS,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ);
                            break;
                        case 7:
                            if(alta_Cliente(lista_cliente,CLI,id_Cliente) == 0)
                            {
                                printf("\n [ - El Cliente se dio de alta Exitosamente - ]\n\n");
                                system("pause");
                                id_Cliente++;
                            }
                            break;
                        case 8:
                            if(baja_Cliente(lista_cliente,CLI,lista_mascotas,MAS)== 0)
                            {
                                id_Cliente--;
                            }
                            break;
                        case 9:
                            ordena_mascotas_por_tipo(lista_mascotas,MAS,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ);
                            system("pause");
                            break;
                        case 10:
                            modificacion_Cliente_por_ID(lista_cliente,CLI);
                            break;
                        case 11:
                            system("cls");
                            listar_Cliente_con_mas_de_una_Mascota(lista_cliente,CLI,lista_mascotas,MAS);
                            break;
                        case 12:
                            system("cls");
                            listar_mascotas_mas_de_3_anios(lista_mascotas,MAS,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ);
                            break;
                        case 13:
                            system("cls");
                            listar_mascotas_por_tipo(lista_mascotas,MAS,lista_cliente,CLI,lista_tipo,TIP,lista_raza,RAZ);
                            break;
                        case 14:
                            system("cls");
                            ordena_duenios_por_cantidad_mascotas(lista_mascotas,MAS,lista_cliente,CLI);
                            system("pause");
                            break;
                        case 15:
                            system("cls");
                            ordena_duenios_por_cantidad_mascotas_y_nombre(lista_mascotas,MAS,lista_cliente,CLI);
                            system("pause");
                            break;
                        case 16:
                            promedio_Edad_Mascotas(lista_mascotas,MAS);
                            break;
                        case 17:
                            system("cls");
                            promedio_Edad_Mascotas_por_Tipo(lista_mascotas,MAS,lista_tipo,TIP);
                            break;
                        case 18:
                            porcentaje_de_Mujeres_sobre_clientes(lista_cliente,CLI);
                            system("pause");
                            break;
                        case 19:
                            system("cls");
                            porcentaje_Varones_Mujeres(lista_cliente,CLI);
                            system("pause");
                            break;
                        case 20:
                            promedio_de_varones_y_mujeres_Clientes(lista_cliente,CLI);
                            break;
                        case 28:
                            system("cls");
                            imprime_all_tipos(lista_tipo,TIP);
                            system("pause");
                            break;
                        case 29:
                            system("cls");
                            imprime_all_razas(lista_raza,RAZ);
                            system("pause");
                            break;
                        case 30:
                            printf("\nConfirmar Salida? [S / N]: ");
                            fflush(stdin);
                            seguir = getchar();
                            break;
                        default:
                            printf("[Opcion Incorrecta].Reintente.\n");
                            fflush(stdin);
                        }
                        system("cls");
                    }
                    while(seguir == 'n');
                }
                else
                {
                    printf("NO SE PUDO INICIALIZAR LAS RAZAS\n");
                }
            }
            else
            {
                printf("NO SE PUDO INICIALIZAR LOS TIPOS\n");
            }
        }
        else
        {
            printf("NO SE PUDO INICIALIZAR MASCOTAS\n");
        }
    }
    else
    {
        printf("NO SE PUDO INICIALIZAR CLIENTES\n");
    }

    return 0;
}
