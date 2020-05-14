#include "mascotas.h"
#include "input.h"
#include "menu.h"


void imprime_mascota(eMascotas listaMascota,eCliente lista_cliente[],int len_cliente)
{
    char nombreCli[51];

    for(int i = 0 ; i < len_cliente;i++){
        if(lista_cliente[i].isEmpty == 0 && lista_cliente[i].id == listaMascota.idCliente){
            strcpy(nombreCli,lista_cliente[i].nombre);
        }
    }

    printf("%2d\t  %10s\t %10s\t   %10s\t   %2d\t    %3.2f\t  %c\t  %10s\t \n",
           listaMascota.id,
           listaMascota.nombre,
           listaMascota.tipo,
           listaMascota.raza,
           listaMascota.edad,
           listaMascota.peso,
           listaMascota.sexo,
           nombreCli);
}

void imprimir_mascotas(eMascotas listaMascota[],int len,eCliente lista_cliente[],int len_cliente)
{
    int flag = 0;

    printf("------- Lista de mascotas -------\n\n");

    printf("ID  |         NOMBRE  |        TIPO   |         RAZA  |    EDAD  |   PESO  |    SEXO |   NOMBRE DUENIO\n\n");
    for(int i=0; i < len; i++)
    {
        if(listaMascota[i].isEmpty == 0)
        {
            imprime_mascota(listaMascota[i],lista_cliente,len_cliente);
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

    if(view == 1){
        printf(" %2d\t          %10s\t     %10s\t     %10s\t  %10s \n",
           listaCliente.id,
           listaCliente.nombre,
           listaMascota.nombre,
           listaMascota.tipo,
           listaMascota.raza);
    }else{
        printf("                     %26s\t     %10s\t  %10s \n",
               listaMascota.nombre,
               listaMascota.tipo,
               listaMascota.raza);
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
                if(lista_mascota[j].isEmpty == 0 && lista_cliente[i].id == lista_mascota[j].idCliente){
                    if(idAnterior != lista_cliente[i].id){
                        printf("\n");
                        imprime_cliente_mascota(lista_mascota[j],lista_cliente[i],1);
                        idAnterior = lista_cliente[i].id;
                    }else{
                        imprime_cliente_mascota(lista_mascota[j],lista_cliente[i],0);
                    }
                }
            }
        }
    }
    system("pause");
}


int buscarLibre_Mascota(eMascotas lista_mascota[], int len){
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


eMascotas addMascota(int id,char nombre[],char tipo[],char raza[],int edad,float peso,char sexo,int idCliente)
{
    eMascotas newMascota;

    newMascota.id = id;
    strcpy(newMascota.nombre,nombre);
    strcpy(newMascota.tipo,tipo);
    strcpy(newMascota.raza,raza);
    newMascota.edad=edad;
    newMascota.peso=peso;
    newMascota.sexo = sexo;
    newMascota.idCliente = idCliente;
    newMascota.isEmpty = 0;

    return newMascota;
}

void imprime_duenio(eCliente lista_cliente){

    printf("%2d\t   %10s\t  %10s\n",lista_cliente.id,lista_cliente.nombre,lista_cliente.apellido);

}

void imprimir_duenios(eCliente lista_cliente[],int len){
    printf("ID CLIENTE |    NOMBRE    | APELLIDO\n\n");
    for(int i = 0; i<len;i++){
        if(lista_cliente[i].isEmpty == 0){
            imprime_duenio(lista_cliente[i]);
        }
    }
}

int validacion_id_cliente(eCliente lista_cliente[],int len,int id_cliente){
    int allOk = -1;

    for(int i = 0 ; i < len;i++){
        if(lista_cliente[i].isEmpty == 0 && lista_cliente[i].id == id_cliente){
            allOk = 0;
        }
    }
    if(allOk == -1){
        printf("ERROR. Id Incorrecta, reintente\n");
    }

    return allOk;
}


int alta_Mascota(eMascotas lista_mascota[],int len,int id_mascota,eCliente lista_cliente[],int len_cliente){
    int allOk = -1;
    int indice;

    char nombre[51];
    char tipo[51];
    char raza[51];
    int edad;
    float peso;
    char sexo;
    int idCliente;

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
        getChar("Ingrese Tipo: ",51,tipo);
        getChar("Ingrese Raza: ",51,raza);
        edad = getInt("Ingrese Edad: ");
        peso = getFloat("Ingrese Peso: ");
        sexo = getCaracter("Ingrese Sexo: ");
        printf("\n");

        imprimir_duenios(lista_cliente,len_cliente);
        do{
            idCliente = getInt("Ingrese ID Cliente: ");

        }while(validacion_id_cliente(lista_cliente,len_cliente,idCliente) != 0);

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


void imprimi_Mascota_por_Indice(eMascotas lista_mascota[],int len,int indice,eCliente lista_cliente[],int len_cliente)
{
    printf("ID  |         NOMBRE  |        TIPO   |         RAZA  |    EDAD  |   PESO  |    SEXO |   NOMBRE DUENIO\n\n");

    for(int i=0; i < len; i++)
    {
        if(lista_mascota[i].isEmpty == 0 && i == indice)
        {
            imprime_mascota(lista_mascota[i],lista_cliente,len_cliente);
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


int baja_Mascota(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente){
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

        if(indice == -1){
            printf("La Id Ingresada es Incorrecta. Reintente\n");
            seguir = 's';
        }else{
                imprimi_Mascota_por_Indice(lista_mascota,len,indice,lista_cliente,len_cliente);

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


    if(indice != -1){
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

void modificar_Mascota(eMascotas lista_mascota[],int len,int id,int indice,eCliente lista_cliente[],int len_cliente){
    char seguir = 'n';

    char nombre[51];
    char tipo[31];
    char raza[31];
    int edad;
    float peso;
    char sexo;

    do
    {
        system("cls");
        printf("           [    -----   Modificacion de Mascota   -----   ]\n\n");
        imprimi_Mascota_por_Indice(lista_mascota,len,indice,lista_cliente,len_cliente);

        switch(menu_modificacion_Mascota())
        {
        case 1:
            getChar("Ingrese el nuevo Nombre: ",51,nombre);
            strcpy(lista_mascota[indice].nombre,nombre);
            break;
        case 2:
            getChar("Ingrese el nuevo Tipo: ",31,tipo);
            strcpy(lista_mascota[indice].tipo,tipo);
            break;
        case 3:
            getChar("Ingrese el nuevo Raza: ",31,raza);
            strcpy(lista_mascota[indice].raza,raza);
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


void modificacion_Mascota_por_ID(eMascotas lista_mascota[],int len,eCliente lista_cliente[],int len_cliente){
    int id;
    char seguir = 'n';
    int indice;

    do
    {
        system("cls");
        printf("\n\n-----    Modificacion de Mascota  -----\n\n");
        id = getInt("Ingrese la ID: ");

        indice = buscar_Mascota_por_ID(lista_mascota,len,id);

        if(indice != -1){
            imprimi_Mascota_por_Indice(lista_mascota,len,indice,lista_cliente,len_cliente);

            printf("Confirma Mascota? [S / N]: ");
            fflush(stdin);
            seguir = getchar();
            if(seguir == 'N')
            {
                seguir = 'n';
            }
        }else{
            printf("[Error. La ID No Existe.Reintente.]\n");
            system("pause");
        }
    }
    while(seguir == 'n');

    if(seguir == 's' || seguir == 'S'){
        modificar_Mascota(lista_mascota,len,id,indice,lista_cliente,len_cliente);
    }
}
