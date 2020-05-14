#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "hardcodeo.h"
#include "input.h"

#define CLI 10 //5 solo cargados
#define MAS 20

#include "cliente.h"
#include "mascotas.h"

int main()
{
    eCliente lista_cliente[CLI];
    eMascotas lista_mascotas[MAS];
    char seguir = 'n';
    int id_Mascota = 12;
    int id_Cliente = 6;


    if(inicializar_clientes(lista_cliente,CLI) == 0)
    {
        if(inicializar_mascotas(lista_mascotas,MAS)== 0)
        {
            do
            {

                harcodeo_Cliente(lista_cliente);
                harcodeo_Mascotas(lista_mascotas);
                switch(menu())
                {
                case 1:
                    imprimir_clientes(lista_cliente,CLI);
                    break;
                case 2:
                    imprimir_mascotas(lista_mascotas,MAS,lista_cliente,CLI);
                    break;
                case 3:
                    imprime_all_cliente_mascota(lista_mascotas,MAS,lista_cliente,CLI);
                    break;
                case 4:
                    if(alta_Mascota(lista_mascotas,MAS, id_Mascota,lista_cliente,CLI) == 0)
                    {
                        printf("\n [ - La Mascota se dio de alta Exitosamente - ]\n\n");
                        system("pause");
                        id_Mascota++;
                    }
                    break;
                case 5:
                    if(baja_Mascota(lista_mascotas,MAS,lista_cliente,CLI) == 0){
                        id_Mascota--;
                    }
                    break;
                case 6:
                    modificacion_Mascota_por_ID(lista_mascotas,MAS,lista_cliente,CLI);
                    break;
                case 7:
                    if(alta_Cliente(lista_cliente,CLI,id_Cliente) == 0){
                        printf("\n [ - El Cliente se dio de alta Exitosamente - ]\n\n");
                        system("pause");
                        id_Cliente++;
                    }
                    break;
                case 8:

                    break;
                case 9:

                    break;
                case 10:

                    break;
                case 11:

                    break;
                case 12:

                    break;
                case 13:

                    break;
                case 14:

                    break;
                case 15:

                    break;
                case 16:

                    break;
                case 17:

                    break;
                case 18:

                    break;
                case 20:
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
            printf("NO SE PUDO INICIALIZAR MASCOTAS\n");
        }
    }
    else
    {
        printf("NO SE PUDO INICIALIZAR CLIENTES\n");
    };

    return 0;
}
