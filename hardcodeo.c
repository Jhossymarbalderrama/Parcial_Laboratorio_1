#include "hardcodeo.h"


 void harcodeo_Cliente(eCliente lista_cliente[]){
    eCliente aux[5] = {{1,"pepe","argento","avellaneda",42015222,41,'M',0},
                       {2,"moni","paredes","lanuns",42105255,38,'F',0},
                       {3,"paola","mercedes","ezeiza",42515512,22,'F',0},
                       {4,"coqui","lopez","quilmes",52442111,22,'M',0},
                       {5,"jose","paredes","sarandi",42515511,35,'M',0}};

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
    eMascotas aux[11] = {{1,"lolo",1,1,4,11.50,'M',1,0},
                         {2,"pepe",1,2,5,12.00,'M',1,0},
                         {3,"maria",2,3,3,4.00,'H',2,0},
                         {4,"lola",2,3,4,4.30,'H',2,0},
                         {5,"carlos",1,2,6,10.00,'M',5,0},
                         {6,"pablo",1,1,5,12.10,'M',3,0},
                         {7,"polo",3,4,2,2.50,'M',3,0},
                         {8,"jose",1,5,5,12.2,'M',4,0},
                         {9,"pepo",2,3,4,3.5,'H',1,0},
                         {10,"carlos",2,3,4,4.20,'M',5,0},
                         {11,"ana",2,3,5,4.00,'H',5,0}};

    for(int i = 0; i< 11;i++){
        lista_mascotas[i].id = aux[i].id;
        strcpy(lista_mascotas[i].nombre,aux[i].nombre);
        /**strcpy(lista_mascotas[i].tipo,aux[i].tipo);*/
        lista_mascotas[i].idtipo = aux[i].idtipo;
        /**strcpy(lista_mascotas[i].raza,aux[i].raza);*/
        lista_mascotas[i].idraza = aux[i].idraza;
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
    eRaza auxRaza[8] = {{1,"Pitbull","Aleman",0},
                        {2,"Bulldog","Frances",0},
                        {3,"Siames","Persa",0},
                        {4,"Iguana Overo","Argentina",0},
                        {5,"Pastor","Alemna",0},
                        {6,"Labrador","Argentina",0},
                        {7,"Iguana crestada","Egipto",0},
                        {8,"Abisinio","Aleman",0}};

    for(int i = 0; i < 8;i++){
        lista_Raza[i].id = auxRaza[i].id;
        strcpy(lista_Raza[i].raza,auxRaza[i].raza);
        strcpy(lista_Raza[i].pais,auxRaza[i].pais);
        lista_Raza[i].isEmpty = auxRaza[i].isEmpty;

    }

}
