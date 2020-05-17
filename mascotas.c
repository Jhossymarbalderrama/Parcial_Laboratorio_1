#include "mascotas.h"
#include "input.h"
#include "menu.h"


void imprime_mascota(eMascotas listaMascota,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    char nombreCli[51];
    char nombreTipo[31];
    char nombreRaza[31];

    for(int i = 0 ; i < len_cliente; i++)
    {
        if(lista_cliente[i].isEmpty == 0 && lista_cliente[i].id == listaMascota.idCliente)
        {
            for(int j = 0; j< len_Tipo; j++)
            {
                if(lista_Tipo[j].isEmpty == 0 && lista_Tipo[j].id == listaMascota.idtipo)
                {
                    for(int k = 0; k < len_Raza; k++)
                    {
                        if(lista_Raza[k].isEmpty == 0 && lista_Raza[k].id == listaMascota.idraza)
                        {
                            strcpy(nombreCli,lista_cliente[i].nombre);
                            strcpy(nombreTipo,lista_Tipo[j].tipo);
                            strcpy(nombreRaza,lista_Raza[k].raza);
                        }
                    }
                }
            }
        }
    }

    printf("%2d\t  %10s\t %10s\t   %10s\t   %2d\t    %3.2f\t  %c\t  %10s\t \n",
           listaMascota.id,
           listaMascota.nombre,
           nombreTipo,
           nombreRaza,
           listaMascota.edad,
           listaMascota.peso,
           listaMascota.sexo,
           nombreCli);
}

void imprimir_mascotas(eMascotas listaMascota[],int len,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    int flag = 0;

    printf("------- Lista de mascotas -------\n\n");

    printf("ID  |         NOMBRE  |        TIPO   |         RAZA  |    EDAD  |   PESO  |    SEXO |   NOMBRE DUENIO\n\n");
    for(int i=0; i < len; i++)
    {
        if(listaMascota[i].isEmpty == 0)
        {
            imprime_mascota(listaMascota[i],lista_cliente,len_cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\n---   No hay MASCOTAS que mostrar   ---\n");
    }
    system("pause");


}

int inicializar_mascotas(eMascotas listaMascota[],int len)
{
    int allOk = -1;

    for(int i = 0; i < len; i++)
    {
        listaMascota[i].isEmpty = 1;
    }

    allOk = inicializa_all_mascotas(listaMascota,len);

    return allOk;
}

int inicializa_all_mascotas(eMascotas listaMascota[],int len)
{
    int allOk = 0;
    for (int i = 0 ; i<len; i++)
    {
        if(listaMascota[i].isEmpty != 1)
        {
            allOk = -1;
            break;
        }
    }
    return allOk;

}

void imprime_cliente_mascota(eMascotas listaMascota,eCliente listaCliente,int view)
{

    if(view == 1)
    {
        printf(" %2d\t          %10s\t     %10s\t     %2d\t  %2d \n",
               listaCliente.id,
               listaCliente.nombre,
               listaMascota.nombre,
               listaMascota.idtipo,
               listaMascota.idraza);
    }
    else
    {
        printf("                     %26s\t     %2d\t  %2d \n",
               listaMascota.nombre,
               listaMascota.idtipo,
               listaMascota.idraza);
    }
}

void imprime_all_cliente_mascota(eMascotas lista_mascota[],int len_mascota,eCliente lista_cliente[],int len_cliente)
{
    int idAnterior = 0;

    printf("\n        [   -----    CLIENTES CON SUS MASCOTAS    -----   ]\n\n");
    printf("ID Cliente |    NOMBRE CLIENTE |     NOMBRE MASCOTA |       TIPO  |     RAZA \n");
    for(int i = 0; i < len_cliente; i++)
    {
        if(lista_cliente[i].isEmpty == 0)
        {
            for(int j = 0; j < len_mascota; j++)
            {
                if(lista_mascota[j].isEmpty == 0 && lista_cliente[i].id == lista_mascota[j].idCliente)
                {
                    if(idAnterior != lista_cliente[i].id)
                    {
                        printf("\n");
                        imprime_cliente_mascota(lista_mascota[j],lista_cliente[i],1);
                        idAnterior = lista_cliente[i].id;
                    }
                    else
                    {
                        imprime_cliente_mascota(lista_mascota[j],lista_cliente[i],0);
                    }
                }
            }
        }
    }
    system("pause");
}


int verificacion_Id(eMascotas lista_mascota[],int len,int id)
{
    int id_retorno = -1;
    id--;

    do
    {
        id++;
        id_retorno = existe_ID(lista_mascota,len,id);

    }
    while(id_retorno == -1);


    return id;
}

int existe_ID(eMascotas lista_mascota[],int len,int id)
{
    int ocupado = 0;

    for(int i = 0; i < len ; i++)
    {
        if(lista_mascota[i].isEmpty == 0 && lista_mascota[i].id == id)
        {
            ocupado = -1;
        }
    }

    return ocupado;
}


int buscarLibre_Mascota(eMascotas lista_mascota[], int len)
{
    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if(lista_mascota[i].isEmpty == 1)
        {
            indice = i;
            break;
        }

    }
    return indice;
}


eMascotas addMascota(int id,char nombre[],int tipo,int raza,int edad,float peso,char sexo,int idCliente)
{
    eMascotas newMascota;

    newMascota.id = id;
    strcpy(newMascota.nombre,nombre);
    //strcpy(newMascota.tipo,tipo);
    newMascota.idtipo = tipo;
    //strcpy(newMascota.raza,raza);
    newMascota.idraza = raza;
    newMascota.edad=edad;
    newMascota.peso=peso;
    newMascota.sexo = sexo;
    newMascota.idCliente = idCliente;
    newMascota.isEmpty = 0;

    return newMascota;
}

void imprime_duenio(eCliente lista_cliente)
{

    printf("%2d\t   %10s\t  %10s\n",lista_cliente.id,lista_cliente.nombre,lista_cliente.apellido);

}

void imprimir_duenios(eCliente lista_cliente[],int len)
{
    printf("ID CLIENTE |    NOMBRE    | APELLIDO\n\n");
    for(int i = 0; i<len; i++)
    {
        if(lista_cliente[i].isEmpty == 0)
        {
            imprime_duenio(lista_cliente[i]);
        }
    }
}

int validacion_id_cliente(eCliente lista_cliente[],int len,int id_cliente)
{
    int allOk = -1;

    for(int i = 0 ; i < len; i++)
    {
        if(lista_cliente[i].isEmpty == 0 && lista_cliente[i].id == id_cliente)
        {
            allOk = 0;
        }
    }
    if(allOk == -1)
    {
        printf("ERROR. Id Incorrecta, reintente\n");
    }

    return allOk;
}


int alta_Mascota(eMascotas lista_mascota[],int len,int id_mascota,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    int allOk = -1;
    int indice;

    char nombre[51];
    //char tipo[51];
    int tipo;
    //char raza[51];
    int raza;
    int edad;
    float peso;
    char sexo;
    int idCliente;

    //int id_Tipo;
    //int seguir_tipo = 0;
    //int id_Raza;
    //int seguir_raza = 0;


    id_mascota = verificacion_Id(lista_mascota,len,id_mascota);

    system("cls");
    printf("\n   -----    Alta de Mascota    -----   \n\n");

    indice = buscarLibre_Mascota(lista_mascota, len);

    if(indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas MASCOTAS\n");
    }
    else
    {
        getChar("Ingrese Nombre: ",51,nombre);
        imprime_all_tipos(lista_Tipo,len_Tipo);
        tipo = getInt("Ingrese ID del Tipo: ");
        imprime_all_razas(lista_Raza,len_Raza);
        raza = getInt("Ingrese la ID de la Raza: ");
        /**TIPO*/
        /**getChar("Ingrese Tipo: ",51,tipo);*/
        /**
        imprime_all_tipos(lista_Tipo,len_Tipo);
        do{
            id_Tipo = getInt("Ingrese ID del Tipo: ");

            for(int i = 0; i < len_Tipo;i++){
                 if(lista_Tipo[i].isEmpty == 0 && lista_Tipo[i].id == id_Tipo){
                    strcpy(tipo,lista_Tipo[i].tipo);
                    seguir_tipo = -1;
                 }
            }
        }while(seguir_tipo == 0);
        */

        /**RAZA*/
        /**getChar("Ingrese Raza: ",51,raza);*/
        /**
        imprime_all_razas(lista_Raza,len_Raza);
        do{
           id_Raza = getInt("Ingrese ID de la Raza: ");

           for(int i = 0;i<len_Raza;i++){
                if(lista_Raza[i].isEmpty == 0 && lista_Raza[i].id == id_Raza){
                    strcpy(raza,lista_Raza[i].raza);
                    seguir_raza = -1;
                }
           }

        }while(seguir_raza == 0);
        */


        edad = getInt("Ingrese Edad: ");
        peso = getFloat("Ingrese Peso: ");
        sexo = getCaracter("Ingrese Sexo [H (hembre) / M (macho)]: ");
        printf("\n");

        imprimir_duenios(lista_cliente,len_cliente);
        do
        {
            idCliente = getInt("Ingrese ID Cliente: ");

        }
        while(validacion_id_cliente(lista_cliente,len_cliente,idCliente) != 0);

        lista_mascota[indice] = addMascota(id_mascota,nombre,tipo,raza,edad,peso,sexo,idCliente);

        allOk = 0;
    }

    return allOk;
}


int buscar_Mascota_por_ID(eMascotas lista_mascota[],int len,int id)
{
    int indice = -1;
    if(lista_mascota == NULL)
    {
        printf("Error.Invalida Longitud o Lista Vacia.\n");
    }
    else
    {
        for(int i=0; i < len; i++)
        {
            if( lista_mascota[i].isEmpty == 0 && lista_mascota[i].id == id)
            {
                indice = i;
            }
        }
    }

    return indice;
}


void imprimi_Mascota_por_Indice(eMascotas lista_mascota[],int len,int indice,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    printf("ID  |         NOMBRE  |        TIPO   |         RAZA  |    EDAD  |   PESO  |    SEXO |   NOMBRE DUENIO\n\n");

    for(int i=0; i < len; i++)
    {
        if(lista_mascota[i].isEmpty == 0 && i == indice)
        {
            imprime_mascota(lista_mascota[i],lista_cliente,len_cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);
        }
    }
}

int elimina_Mascota(eMascotas lista_mascota[],int len,int id)
{
    int allOk = -1;

    for(int i = 0 ; i < len ; i++)
    {
        if(lista_mascota[i].id == id)
        {
            lista_mascota[i].isEmpty = 1;
            allOk = 0;
        }
    }

    return allOk;
}


int baja_Mascota(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    int ollOk = -1;
    int id;
    char seguir = 'n';
    int indice;
    int allOk=-1;

    do
    {
        system("cls");
        printf("-----    Baja de Mascota   -----\n\n");

        id = getInt("Ingrese la ID: ");
        indice = buscar_Mascota_por_ID(lista_mascota,len,id);

        if(indice == -1)
        {
            printf("La Id Ingresada es Incorrecta. Reintente\n");
            seguir = 's';
        }
        else
        {
            imprimi_Mascota_por_Indice(lista_mascota,len,indice,lista_cliente,len_cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);

            printf("Confirma Mascota? [S / N]: ");
            fflush(stdin);
            seguir = getchar();
            if(seguir == 'N')
            {
                seguir = 'n';
            }
        }

    }
    while(seguir == 'n');


    if(indice != -1)
    {
        allOk = elimina_Mascota(lista_mascota,len,id);
        if(allOk == 0)
        {
            printf("-- [La Mascota se dio de Baja Exitosamente.] --\n");
            ollOk = 0;
        }
        else
        {
            printf("Error. Hubo un problema al Dar de Baja la Mascota\n");
        }
        system("pause");
    }

    return ollOk;
}

void modificar_Mascota(eMascotas lista_mascota[],int len,int id,int indice,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{

    char seguir = 'n';

    char nombre[51];
    //char tipo[31];
    int tipo;
    //char raza[31];
    int raza;
    int edad;
    float peso;
    char sexo;

    do
    {
        system("cls");
        printf("           [    -----   Modificacion de Mascota   -----   ]\n\n");
        imprimi_Mascota_por_Indice(lista_mascota,len,indice,lista_cliente,len_cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);

        switch(menu_modificacion_Mascota())
        {
        case 1:
            getChar("Ingrese el nuevo Nombre: ",51,nombre);
            strcpy(lista_mascota[indice].nombre,nombre);
            break;
        case 2:
            imprime_all_tipos(lista_Tipo,len_Tipo);
            tipo = getInt("Ingrese el ID de Tipo: ");
            lista_mascota[indice].idtipo = tipo;
            break;
        case 3:
            imprime_all_razas(lista_Raza,len_Raza);
            raza = getInt("Ingrese la ID de Raza: ");
            lista_mascota[indice].idraza = raza;
            break;
        case 4:
            edad = getInt("Ingrese la nueva Edad: ");
            lista_mascota[indice].edad = edad;
            break;
        case 5:
            peso = getFloat("Ingrese el nuevo Peso: ");
            lista_mascota[indice].peso = peso;
            break;
        case 6:
            sexo = getCaracter("Ingrese el Sexo [M / H]: ");
            lista_mascota[indice].sexo = sexo;
            break;
        case 7:
            printf("\nConfirmar Salida? [S / N]: ");
            fflush(stdin);
            seguir = getchar();
            break;
        default:
            printf("[Opcion invalida]\n");
            fflush(stdin);
            system("pause");
        }
    }
    while(seguir == 'n');

}


void modificacion_Mascota_por_ID(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    int id;
    char seguir = 'n';
    int indice;

    do
    {
        system("cls");
        printf("\n\n-----    Modificacion de Mascota  -----\n\n");
        id = getInt("Ingrese la ID: ");

        indice = buscar_Mascota_por_ID(lista_mascota,len,id);

        if(indice != -1)
        {
            imprimi_Mascota_por_Indice(lista_mascota,len,indice,lista_cliente,len_cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);

            printf("Confirma Mascota? [S / N]: ");
            fflush(stdin);
            seguir = getchar();
            if(seguir == 'N')
            {
                seguir = 'n';
            }
        }
        else
        {
            printf("[Error. La ID No Existe.Reintente.]\n");
            system("pause");
        }
    }
    while(seguir == 'n');

    if(seguir == 's' || seguir == 'S')
    {
        modificar_Mascota(lista_mascota,len,id,indice,lista_cliente,len_cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);
    }
}

/**Cliente - Mascotas*/
/**
int buscar_Cliente_por_ID(eCliente listaCliente[],int len,int id)
{
    int indice = -1;
    if(listaCliente == NULL)
    {
        printf("Error.Invalida Longitud o Lista Vacia.\n");
    }
    else
    {
        for(int i=0; i < len; i++)
        {
            if( listaCliente[i].isEmpty == 0 && listaCliente[i].id == id)
            {
                indice = i;
            }
        }
    }

    return indice;
}
*/
/**
void imprimi_Cliente_por_Indice(eCliente listaCliente[],int len,int indice)
{
    printf("ID  |         NOMBRE   |      APELLIDO  |   LOCALIDAD  |    TELEFONO  |  EDAD |  SEXO \n\n");

    for(int i=0; i < len; i++)
    {
        if(listaCliente[i].isEmpty == 0 && i == indice)
        {
            imprime_cliente(listaCliente[i]);
        }
    }
}
*/
/**
int elimina_Cliente(eCliente listaCliente[],int len,int id)
{
    int allOk = -1;

    for(int i = 0 ; i < len ; i++)
    {
        if(listaCliente[i].id == id)
        {
            listaCliente[i].isEmpty = 1;
            allOk = 0;
        }
    }

    return allOk;
}
*/

int busco_y_elimino_Mascotas_Por_ID_Cliente(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCliente[],int len_Cliente,int id_Cliente)
{
    int allOk = -1;


    for(int i = 0; i < len_Mascota; i++)
    {
        if(lista_Mascota[i].isEmpty == 0 && lista_Mascota[i].idCliente ==  id_Cliente)
        {
            elimina_Mascota(lista_Mascota,len_Mascota,lista_Mascota[i].id);
        }
        allOk = 0;
    }

    return allOk;
}


int baja_Cliente(eCliente listaCliente[],int len,eMascotas lista_Mascota[],int len_Mascota)
{
    int ollOk = -1;
    int id;
    char seguir = 'n';
    int indice;
    int allOk=-1;

    do
    {
        system("cls");
        printf("-----    Baja de Cliente   -----\n\n");

        id = getInt("Ingrese la ID: ");

        indice = buscar_Cliente_por_ID(listaCliente,len,id);

        if(indice == -1)
        {
            printf("La Id Ingresada es Incorrecta. Reintente\n");
            seguir = 's';
        }
        else
        {

            imprimi_Cliente_por_Indice(listaCliente,len,indice);

            printf("Confirma Cliente? [S / N]: ");
            fflush(stdin);
            seguir = getchar();
            if(seguir == 'N')
            {
                seguir = 'n';
            }
        }

    }
    while(seguir == 'n');


    if(indice != -1)
    {

        if(busco_y_elimino_Mascotas_Por_ID_Cliente(lista_Mascota,len_Mascota,listaCliente,len,id) == 0)
        {
            allOk = elimina_Cliente(listaCliente,len,id);
        }
        if(allOk == 0)
        {
            printf("-- [El Cliente se dio de Baja Exitosamente.] --\n");
            ollOk = 0;
        }
        else
        {
            printf("Error. Hubo un problema al Dar de Baja el Cliente\n");
        }
        system("pause");
    }

    return ollOk;
}


void ordena_mascotas_por_tipo(eMascotas lista_Mascotas[],int len_Mascotas,eCliente listaCliente[],int len_Cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    eMascotas auxMascota;

    for(int i = 0 ; i < len_Mascotas-1; i++)
    {
        for(int j = i+1; j<len_Mascotas; j++)
        {
            if(lista_Mascotas[i].isEmpty == 0 && lista_Mascotas[j].isEmpty == 0)
            {
                if(lista_Mascotas[i].idtipo < lista_Mascotas[j].idtipo)
                {
                    auxMascota = lista_Mascotas[i];
                    lista_Mascotas[i] = lista_Mascotas[j];
                    lista_Mascotas[j] = auxMascota;

                }
                /*
                if(strcmp(lista_Mascotas[i].tipo,lista_Mascotas[j].tipo)<0){
                    auxMascota = lista_Mascotas[i];
                    lista_Mascotas[i] = lista_Mascotas[j];
                    lista_Mascotas[j] = auxMascota;
                }
                */
            }
        }
    }

    imprimir_mascotas(lista_Mascotas,len_Mascotas,listaCliente,len_Cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);
}

void listar_Cliente_con_mas_de_una_Mascota(eCliente listaCliente[],int len_Cliente,eMascotas lista_Mascota[],int len_Mascota)
{

    for(int i = 0; i <len_Cliente; i++)
    {
        if(listaCliente[i].isEmpty == 0 && busca_mascotas_por_ID_Cliente(lista_Mascota,len_Mascota,listaCliente[i].id) == 0)
        {
            imprime_cliente(listaCliente[i]);
        }
    }

    system("pause");
}


int busca_mascotas_por_ID_Cliente(eMascotas lista_Mascota[],int len_Mascota,int id_cliente)
{
    int allOk = -1;
    int cont = 0;

    for(int i = 0; i<len_Mascota; i++)
    {
        if(lista_Mascota[i].isEmpty == 0 && lista_Mascota[i].idCliente == id_cliente)
        {
            cont++;

            if(cont == 2)
            {
                allOk = 0;
                break;
            }
        }
    }

    return allOk;
}


void listar_mascotas_mas_de_3_anios(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCliente[],int len_Cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{

    for(int i = 0 ; i < len_Mascota; i++)
    {
        if(lista_Mascota[i].isEmpty == 0 && lista_Mascota[i].edad > 3)
        {
            imprime_mascota(lista_Mascota[i],listaCliente,len_Cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);
        }
    }

    system("pause");
}

/**13*/
void listar_mascotas_por_tipo(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCliente[],int len_Cliente,eTipo lista_Tipo[],int len_Tipo,eRaza lista_Raza[],int len_Raza)
{
    int tipo_Ingresado;
    printf("   [     -----   Lista de Mascotas por Tipo   -----     ]\n\n");
    imprime_all_tipos(lista_Tipo,len_Tipo);
    tipo_Ingresado = getInt("Ingrese la ID de Tipo: ");

    printf("\nID  |         NOMBRE  |        TIPO   |         RAZA  |    EDAD  |   PESO  |    SEXO |   NOMBRE DUENIO\n\n");

    for(int i = 0; i < len_Mascota; i++)
    {
        if(lista_Mascota[i].isEmpty == 0 && lista_Mascota[i].idtipo == tipo_Ingresado)
        {
            imprime_mascota(lista_Mascota[i],listaCliente,len_Cliente,lista_Tipo,len_Tipo,lista_Raza,len_Raza);
        }
    }

    system("pause");
}


/**TIPO*/
int inicializar_tipos(eTipo lista_Tipo[],int len_Tipo)
{
    int allOk = -1;

    for(int i = 0; i < len_Tipo; i++)
    {
        lista_Tipo[i].isEmpty = 1;
    }

    allOk = inicializar_all_tipos(lista_Tipo,len_Tipo);

    return allOk;
}
int inicializar_all_tipos(eTipo lista_Tipo[],int len_Tipo)
{
    int allOk = 0;
    for (int i = 0 ; i<len_Tipo; i++)
    {
        if(lista_Tipo[i].isEmpty != 1)
        {
            allOk = -1;
            break;
        }
    }
    return allOk;
}

void imprime_tipo(eTipo lista_Tipo)
{
    printf("%2d\t %10s\t  \n",lista_Tipo.id,lista_Tipo.tipo);
}

void imprime_all_tipos(eTipo lista_Tipo[],int len_Tipo)
{
    int flag = 0;

    printf("[  ------- Lista de Tipos de Mascotas -------  ]\n\n");

    printf("ID    |       TIPO   \n\n");
    for(int i=0; i < len_Tipo; i++)
    {
        if(lista_Tipo[i].isEmpty == 0)
        {
            imprime_tipo(lista_Tipo[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\n---   No hay Tipos que mostrar   ---\n");
    }
    //system("pause");
}


/**RAZA*/
int inicializar_razas(eRaza lista_Raza[],int len_Raza)
{
    int allOk = -1;

    for(int i = 0; i < len_Raza; i++)
    {
        lista_Raza[i].isEmpty = 1;
    }

    allOk = inicializar_all_razas(lista_Raza,len_Raza);

    return allOk;
}

int inicializar_all_razas(eRaza lista_Raza[],int len_Raza)
{
    int allOk = 0;
    for (int i = 0 ; i<len_Raza; i++)
    {
        if(lista_Raza[i].isEmpty != 1)
        {
            allOk = -1;
            break;
        }
    }
    return allOk;
}

void imprime_raza(eRaza lista_Raza)
{
    printf("%2d\t %10s\t  \n",lista_Raza.id,lista_Raza.raza);
}

void imprime_all_razas(eRaza lista_Raza[],int len_Razas)
{
    int flag = 0;

    printf("[  ------- Lista de Raza de Mascotas -------  ]\n\n");

    printf("ID     |      RAZA   \n\n");
    for(int i=0; i < len_Razas; i++)
    {
        if(lista_Raza[i].isEmpty == 0)
        {
            imprime_raza(lista_Raza[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\n---   No hay Raza que mostrar   ---\n");
    }
    // system("pause");
}

/**14 -ordenar a los dueños por cantidades de mascotas y mostrarlos.*/
void ordena_duenios_por_cantidad_mascotas(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCiente[],int len_Cliente){
    eCliente auxCliente;

    int cant_duenioI;
    int cant_duenioJ;

    for(int i = 0 ;i < len_Cliente-1; i++){
        if(listaCiente[i].isEmpty == 0){
            for(int j = i+1; j < len_Cliente;j ++){
                if(listaCiente[j].isEmpty == 0){
                    cant_duenioI = cantidad_de_mascota_por_cliente(lista_Mascota,len_Mascota,listaCiente[i].id);
                    cant_duenioJ = cantidad_de_mascota_por_cliente(lista_Mascota,len_Mascota,listaCiente[j].id);
                        if(cant_duenioI < cant_duenioJ){
                            auxCliente = listaCiente[i];
                            listaCiente[i] = listaCiente[j];
                            listaCiente[j] = auxCliente;
                        }
                }
            }
        }
    }

    imprimir_clientes(listaCiente,len_Cliente);

}

int cantidad_de_mascota_por_cliente(eMascotas lista_Mascota[],int len_Mascotan,int id_Cliente){
    int contador = 0;

    for(int i = 0;i <len_Mascotan;i++){
        if(lista_Mascota[i].isEmpty == 0 && lista_Mascota[i].idCliente == id_Cliente){
            contador++;
        }
    }

    return contador;
}


/**15 - ordenar a los dueños por cantidades de mascotas y por orden alfabético de los
nombres y mostrarlos.*/
void ordena_duenios_por_cantidad_mascotas_y_nombre(eMascotas lista_Mascota[],int len_Mascota,eCliente listaCiente[],int len_Cliente){
    eCliente auxCliente;

    int cant_duenioI;
    int cant_duenioJ;

    for(int i = 0 ;i < len_Cliente-1; i++){
        if(listaCiente[i].isEmpty == 0){
            for(int j = i+1; j < len_Cliente;j ++){
                if(listaCiente[j].isEmpty == 0){
                    cant_duenioI = cantidad_de_mascota_por_cliente(lista_Mascota,len_Mascota,listaCiente[i].id);
                    cant_duenioJ = cantidad_de_mascota_por_cliente(lista_Mascota,len_Mascota,listaCiente[j].id);
                        if(cant_duenioI < cant_duenioJ){
                            auxCliente = listaCiente[i];
                            listaCiente[i] = listaCiente[j];
                            listaCiente[j] = auxCliente;
                        }else if(cant_duenioI == cant_duenioJ && strcmp(listaCiente[i].nombre,listaCiente[j].nombre)>0){
                                auxCliente = listaCiente[i];
                                listaCiente[i] = listaCiente[j];
                                listaCiente[j] = auxCliente;
                        }
                }
            }
        }
    }

    imprimir_clientes(listaCiente,len_Cliente);

}

/**16 - el promedio de edad entre las mascotas*/
void promedio_Edad_Mascotas(eMascotas lista_Mascota[],int len_Mascota){
    int cantidad_Mascotas = cantidad_de_mascotas(lista_Mascota,len_Mascota);
    int total_Edades = suma_de_Edades_Mascotas(lista_Mascota,len_Mascota);
    float promedio = (float) total_Edades / cantidad_Mascotas;

    //printf("cantidad mascotas: %d\n",cantidad_Mascotas);
    //printf("suma total edades: %d\n",total_Edades);
    printf("\n[ El Promedio de Edades entre las Mascotas es de : %0.2f ]\n",promedio);
    system("pause");
}

int cantidad_de_mascotas(eMascotas lista_Mascota[],int len_Mascota){
    int cantidad = 0;

    for(int i = 0; i < len_Mascota ; i++){
        if(lista_Mascota[i].isEmpty == 0){
            cantidad++;
        }
    }

    return cantidad;
}

int suma_de_Edades_Mascotas(eMascotas lista_Mascota[],int len_Mascota){
    int total = 0;

    for(int i = 0; i < len_Mascota ; i++){
        if(lista_Mascota[i].isEmpty == 0){
            total = total + lista_Mascota[i].edad;
        }
    }

    return total;
}

/**17 - el promedio de edad entre las mascotas, por tipo*/
void promedio_Edad_Mascotas_por_Tipo(eMascotas lista_Mascota[],int len_Mascota,eTipo lista_tipo[],int len_tipo){
    int tipo;
    int cantidad_Mascotas;
    int total_Edades;
    float promedio;
    char nombre_tipo[31];

    imprime_all_tipos(lista_tipo,len_tipo);
    tipo = getInt("Ingrese Tipo: ");

    cantidad_Mascotas = cantidad_de_mascotas_por_tipo(lista_Mascota,len_Mascota,tipo);
    total_Edades = suma_de_Edades_Mascotas_por_tipo(lista_Mascota,len_Mascota,tipo);
    promedio = (float) total_Edades / cantidad_Mascotas;

    for(int i = 0 ; i < len_tipo ; i++){
        if(lista_tipo[i].isEmpty == 0 && lista_tipo[i].id == tipo){
            strcpy(nombre_tipo,lista_tipo[i].tipo);
        }
    }

    printf("\n[ El Promedio de Edades entre las Mascotas del tipo %s es : %0.2f ]\n",nombre_tipo,promedio);
    system("pause");
}

int cantidad_de_mascotas_por_tipo(eMascotas lista_Mascota[],int len_Mascota,int tipo){
    int cantidad = 0;

    for(int i = 0; i < len_Mascota ; i++){
        if(lista_Mascota[i].isEmpty == 0 && lista_Mascota[i].idtipo == tipo){
            cantidad++;
        }
    }

    return cantidad;
}

int suma_de_Edades_Mascotas_por_tipo(eMascotas lista_Mascota[],int len_Mascota,int tipo){
    int total = 0;

    for(int i = 0; i < len_Mascota ; i++){
        if(lista_Mascota[i].isEmpty == 0 && lista_Mascota[i].idtipo == tipo){
            total = total + lista_Mascota[i].edad;
        }
    }

    return total;
}


