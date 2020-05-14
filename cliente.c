#include "cliente.h"
#include "string.h"
#include "input.h"

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

    printf("------- Lista de Clientes -------\n\n");

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
    system("pause");


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
    printf("\n   -----    Alta de Cliente    -----   \n\n");

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
        sexo = getCaracter("Ingrese Sexo [ M / F ]: ");
        printf("\n");


        listaCliente[indice] = addCliente(id_cliente,nombre,apellido,localidad,telefono,edad,sexo);
        allOk = 0;
    }

    return allOk;
}
