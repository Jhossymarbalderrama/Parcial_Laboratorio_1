#include <ctype.h>
#include "cliente.h"
#include "string.h"
#include "input.h"
#include "mascotas.h"
#include "menu.h"

void imprime_cliente(eCliente listaCliente){
    printf("%2d\t  %10s\t   %10s\t   %10s\t     %8d    %2d      %c \n",
           listaCliente.id,
           listaCliente.nombre,
           listaCliente.apellido,
           listaCliente.localidad,
           listaCliente.telefono,
           listaCliente.edad,
           listaCliente.sexo);

}

void imprimir_clientes(eCliente listaCliente[],int len){
    int flag = 0;

    printf("     [     -------    LISTA DE CLIENTES     -------     ]\n\n");

    printf("ID    |       NOMBRE  |      APELLIDO |      LOCALIDAD  |   TELEFONO  | EDAD |  SEXO \n\n");
    for(int i=0; i < len; i++)
    {
        if(listaCliente[i].isEmpty == 0){
            imprime_cliente(listaCliente[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\n---   No hay CLIENTES que mostrar   ---\n");
    }
}

int inicializar_clientes(eCliente listaCliente[],int len)
{
    int allOk = -1;

    for(int i = 0; i < len; i++)
    {
        listaCliente[i].isEmpty = 1;
    }

    allOk = inicializa_all_cliente(listaCliente,len);

    return allOk;
}

int inicializa_all_cliente(eCliente listaCliente[],int len){
    int allOk = 0;
    for (int i = 0 ; i<len;i++){
           if(listaCliente[i].isEmpty != 1){
                allOk = -1;
                break;
           }
    }
    return allOk;
}

int buscarLibre_Cliente(eCliente listaCliente[], int len){
    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if(listaCliente[i].isEmpty == 1)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

eCliente addCliente(int id,char nombre[],char apellido[],char localidad[],int telefono,int edad,char sexo)
{
    eCliente newCliente;

    newCliente.id = id;
    strcpy(newCliente.nombre,nombre);
    strcpy(newCliente.apellido,apellido);
    strcpy(newCliente.localidad,localidad);
    newCliente.telefono = telefono;
    newCliente.edad = edad;
    newCliente.sexo = sexo;
    newCliente.isEmpty = 0;

    return newCliente;
}


int alta_Cliente(eCliente listaCliente[],int len,int id_cliente){
    int allOk = -1;
    int indice;

    char nombre[51];
    char apellido[51];
    char localidad[51];
    int telefono;
    int edad;
    char sexo;

    system("cls");
    printf("[     ------------    ALTA DE CLIENTE    ------------     ]\n\n");
    indice = buscarLibre_Cliente(listaCliente,len);

    if(indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas Clientes\n");
    }
    else
    {
        getChar("Ingrese Nombre: ",51,nombre);
        getChar("Ingrese Apellido: ",51,apellido);
        getChar("Ingrese Localidad: ",51,localidad);
        telefono = getInt("Ingrese Telefono: ");
        edad = getInt("Ingrese Edad: ");
        sexo = getCaracter("Ingrese Sexo [ M (Masculino) / F (Femenido)]: ");
        sexo = toupper(sexo);
        printf("\n");


        listaCliente[indice] = addCliente(id_cliente,nombre,apellido,localidad,telefono,edad,sexo);
        allOk = 0;
    }

    return allOk;
}

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

void imprimi_Cliente_por_Indice(eCliente listaCliente[],int len,int indice)
{
    printf("ID    |       NOMBRE  |      APELLIDO |      LOCALIDAD  |   TELEFONO  | EDAD |  SEXO \n\n");

    for(int i=0; i < len; i++)
    {
        if(listaCliente[i].isEmpty == 0 && i == indice)
        {
            imprime_cliente(listaCliente[i]);
        }
    }
}


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




void modificacion_Cliente(eCliente listaCliente[],int len,int indice){
    char seguir = 'n';

    char nombre[51];
    char apellido[51];
    char localidad[51];
    int telefono;
    int edad;
    char sexo;

    do
    {
        system("cls");
        printf("           [    -----   Modificacion de Cliente   -----   ]\n\n");

        imprimi_Cliente_por_Indice(listaCliente,len,indice);

        switch(menu_modificacion_Cliente())
        {
        case 1:
            getChar("Ingrese el Nuevo Nombre: ",51,nombre);
            strcpy(listaCliente[indice].nombre,nombre);
            break;
        case 2:
            getChar("Ingrese el Nuevo Apellido: ",51,apellido);
            strcpy(listaCliente[indice].apellido,apellido);
            break;
        case 3:
            getChar("Ingrese la Nueva Localidada: ",51,localidad);
            strcpy(listaCliente[indice].localidad,localidad);
            break;
        case 4:
            telefono = getInt("Ingrese el Nuevo Telefono: ");
            listaCliente[indice].telefono = telefono;
            break;
        case 5:
            edad = getInt("Ingrese la Nueva Edad: ");
            listaCliente[indice].edad = edad;
            break;
        case 6:
            sexo = getCaracter("Ingrese el Sexo [F (femenino) / M (masculino)]: ");
            listaCliente[indice].sexo = sexo;
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

void modificacion_Cliente_por_ID(eCliente listaCliente[],int len){
    int id;
    char seguir = 'n';
    int indice;

    do
    {
        system("cls");
        printf("[     ------------    MODIFICACION DE CLIENTE    ------------     ]\n\n");

        imprimir_clientes(listaCliente,len);

        id = getInt("\nIngrese la ID del Cliente: ");
        indice = buscar_Cliente_por_ID(listaCliente,len,id);

        if(indice != -1)
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
        else
        {
            printf("[Error. La ID No Existe.Reintente.]\n");
            system("pause");
        }
    }
    while(seguir == 'n');

    if(seguir == 's' || seguir == 'S')
    {
        modificacion_Cliente(listaCliente,len,indice);
    }

}

/**18 -el promedio que tengo entre varones y mujeres de mis clientes*/
void promedio_de_varones_y_mujeres_Clientes(eCliente listaCliente[],int len_Cliente){
    int total_Clientes = cantidad_total_clientes(listaCliente,len_Cliente);
    int varones = cantidad_cliente_por_sexo(listaCliente,len_Cliente,0);
    int mujeres = cantidad_cliente_por_sexo(listaCliente,len_Cliente,1);

    float promedio_Hombres = (float) total_Clientes / varones;
    float promedio_Mujeres = (float) total_Clientes / mujeres;


    printf("\nEl Promedio de Varones es : %0.2f \nEl Promedio de Mujeres es: %0.2f\n",promedio_Hombres,promedio_Mujeres);
    system("pause");
}



/** \brief
 *
 * \param listaCliente[] eCliente
 * \param len_Cliente int
 * \param sexo int (0 para Hombres, 1 para Mujeres)
 * \return int
 *
 */
int cantidad_cliente_por_sexo(eCliente listaCliente[],int len_Cliente,int sexo){
    int cant_cliente = 0;
    for(int i = 0;i <len_Cliente ; i++){
        if(listaCliente[i].isEmpty == 0){
                if(sexo == 0){
                        if(listaCliente[i].sexo == 'M' || listaCliente[i].sexo == 'm'){
                            cant_cliente++;
                        }
                }else{
                        if(listaCliente[i].sexo == 'F' || listaCliente[i].sexo == 'f'){
                            cant_cliente++;
                        }
                }
        }

    }

    return cant_cliente;
}

int cantidad_total_clientes(eCliente listaCliente[],int len_Cliente){
    int total = 0;

    for(int i = 0; i < len_Cliente; i++){
        if(listaCliente[i].isEmpty == 0){
            total++;
        }
    }

    return total;
}

/** 19- El porcentaje que tengo entre varones y mujeres de mis clientes.*/
void porcentaje_Varones_Mujeres(eCliente lista_Cliente[],int len_Cliente){
    int total_Clientes = cantidad_total_clientes(lista_Cliente,len_Cliente);
    int masculino = cantidad_cliente_por_sexo(lista_Cliente,len_Cliente,0);
    int femeninos = cantidad_cliente_por_sexo(lista_Cliente,len_Cliente,1);

    float  porcentaje_Masculino =  (float) (masculino *  100) / total_Clientes;
    float porcentaje_Femenino =  (float) (femeninos * 100) / total_Clientes;

    printf("[   ------------    EL PORCENTAJE DE CLIENTES MASCULINOS Y FEMENINOS    ------------   ]\n\n");
    printf("\nEl Porcentaje de Clientes Masculinos es : %0.2f% \nEl Porcentaje Clientas Femeninas es: %0.2f%\n",porcentaje_Masculino,porcentaje_Femenino);
}




