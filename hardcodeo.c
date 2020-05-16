#include "hardcodeo.h"


 void harcodeo_Cliente(eCliente lista_cliente[]){
    eCliente aux[5] = {{1,"pepe","argento","avellaneda",42015222,41,'m',0},
                       {2,"moni","paredes","lanuns",42105255,38,'f',0},
                       {3,"paola","mercedes","ezeiza",42515512,22,'f',0},
                       {4,"coqui","lopez","quilmes",52442111,22,'m',0},
                       {5,"jose","paredes","sarandi",42515511,35,'m',0}};

    for(int i = 0; i< 5;i++){
        lista_cliente[i].id = aux[i].id;
        strcpy(lista_cliente[i].nombre,aux[i].nombre);
        strcpy(lista_cliente[i].apellido,aux[i].apellido);
        strcpy(lista_cliente[i].localidad,aux[i].localidad);
        lista_cliente[i].telefono = aux[i].telefono;
        lista_cliente[i].edad = aux[i].edad;
        lista_cliente[i].sexo = aux[i].sexo;
        lista_cliente[i].isEmpty = aux[i].isEmpty;
    }

 }

 void harcodeo_Mascotas(eMascotas lista_mascotas[]){
    eMascotas aux[11] = {{1,"lolo","perro","pitbull",4,11.50,'m',1,0},
                         {2,"pepe","perro","bulldog",5,12.00,'m',1,0},
                         {3,"maria","gato","siames",3,4.00,'h',2,0},
                         {4,"lola","gato","siames",4,4.30,'h',2,0},
                         {5,"carlos","perro","bulldog",6,10.00,'m',5,0},
                         {6,"pablo","perro","pitbull",5,12.10,'m',3,0},
                         {7,"polo","iguana","iguana",2,2.50,'m',3,0},
                         {8,"jose","perro","labrador",5,12.2,'m',4,0},
                         {9,"pepo","gato","siames",4,3.5,'h',1,0},
                         {10,"carlos","gato","siames",4,4.20,'m',5,0},
                         {11,"ana","gato","siames",5,4.00,'h',5,0}};

    for(int i = 0; i< 11;i++){
        lista_mascotas[i].id = aux[i].id;
        strcpy(lista_mascotas[i].nombre,aux[i].nombre);
        strcpy(lista_mascotas[i].tipo,aux[i].tipo);
        strcpy(lista_mascotas[i].raza,aux[i].raza);
        lista_mascotas[i].edad = aux[i].edad;
        lista_mascotas[i].peso = aux[i].peso;
        lista_mascotas[i].sexo = aux[i].sexo;
        lista_mascotas[i].idCliente = aux[i].idCliente;
        lista_mascotas[i].isEmpty = aux[i].isEmpty;
    }

 }

void harcodeo_Tipo(eTipo lista_Tipo[]){
    eTipo auxTipo[3] = {{1,"Perro",0},
                        {2,"Gato",0},
                        {3,"Iguana",0}};

    for(int i = 0; i < 3;i++){
        lista_Tipo[i].id = auxTipo[i].id;
        strcpy(lista_Tipo[i].tipo,auxTipo[i].tipo);
        lista_Tipo[i].isEmpty = auxTipo[i].isEmpty;
    }

}

void harcodeo_Raza(eRaza lista_Raza[]){
    eRaza auxRaza[5] = {{1,"Pitbull",0},
                        {2,"Bulldog",0},
                        {3,"Siames",0},
                        {4,"Iguana",0},
                        {5,"Labrador",0}};

    for(int i = 0; i < 5;i++){
        lista_Raza[i].id = auxRaza[i].id;
        strcpy(lista_Raza[i].raza,auxRaza[i].raza);
        lista_Raza[i].isEmpty = auxRaza[i].isEmpty;
    }

}
