#include "menu.h"

int menu(void){
    int valor;
    printf(" --------   MENU PRINCIPAL   --------  \n\n");
    printf("1- listado de cliente.\n2- listado de mascotas.\n3- listado de clientes con su mascota.\n\n4- alta de mascota.\n5- baja de mascota.\n6- modificacion de mascota.\n\n7- Alta de Duenio.\n8- Borra de Duenio en Cascada.\n9- Ordenar las mascotas por tipo y listarlas con sus duenios.\n\n10- Modificacion de Duenio.\n11- Listar los Clientes con mas de una mascota\n12- Listar las mascotas de mas de tres anios, con respectivos duenios.\n\n13- Listar las mascotas por un tipo en particular.\n14- Ordenar a los duenios por cantidades de mascotas y mostrarlos.\n15- Ordenar a los duenios por cantidades de mascotas y por orden alfabetico de los nombre y mostrarlos.\n16- El promedio de edad entre las mascotas.\n17- El promedio de edad entre las mascotas, por tipo.\n18- El promedio que tengo entre varones y mujeres de mis clientes.\n\n28- Listar Tipos.\n29- Listar Razas.\n\n30- Salir.\n\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&valor);
    return valor;
}

int menu_modificacion_Mascota(void){
    int valor;
    printf("\n-----------------------------------------------------------------\n");
    printf("1- Nombre.\n2- Tipo.\n3- Raza. \n4- Edad.\n5- Peso.\n6- Sexo.\n7- <-- Volver.\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&valor);
    return valor;
}

int menu_modificacion_Cliente(void){
    int valor;
    printf("\n-----------------------------------------------------------------\n");
    printf("1- Nombre.\n2- Apellido.\n3- Localidad.\n4- Telefono.\n5- Edad.\n6- Sexo.\n7- <-- Volver.\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&valor);
    return valor;
}
