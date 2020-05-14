#include "input.h"
#include <ctype.h>

/** \brief Retorna un valor entero ya sea negativo o positivo.
 *
 * \param msj[] char
 * \return int
 *
 */
int getInt(char msj[])
{
    int vEntero;

    printf("%s",msj);
    scanf("%d",&vEntero);

    return  vEntero;
}


/** \brief  Get Obtiene un Flotante
 *
 * \param msj[] char
 * \return float
 *
 */
float getFloat(char msj[])
{
    float vFloat;

    printf("%s",msj);
    scanf("%f",&vFloat);

    return vFloat;
}


/** \brief  Obtiene una cadena de caracteres por un Puntero Ingresado por Parametro.
 *
 * \param msj[] char
 * \param tam int
 * \param string char*
 * \return void
 *
 */
void getChar(char msj[],int tam,char* string)
{
    char vChar[tam];

    printf("%s",msj);
    fflush(stdin);
    gets(vChar);

    strcpy(string,vChar);
    return;
}


/** \brief  Obtiene 1 Caracter
 *
 * \param msj[] char
 * \return char
 *
 */
char getCaracter(char msj[]){
    char vChar;

    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&vChar);

    return vChar;
}


