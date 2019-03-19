#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <listcursos.h>
#include <listedificios.h>
#include <csv.h>




struct stOrtogonal{

    std::string  horaInicio;
    std::string horaFinal;
    std::string edificio;
    int no_salon;
    std::string idCurso;

};

struct xy{

    std::string  horaInicio;
    nodoSalon* salon;
    std::string edificio;
};



struct contenido
{
    std::string horaFinal;
    nodoCurso* curso;
};




//********************************************************************************
//************************CLASE NODO ORTOGONAL************************************
//********************************************************************************
class NodoOrtogonal
{
private:
    xy indice;
    contenido cont;

    NodoOrtogonal* up;
    NodoOrtogonal* down;
    NodoOrtogonal* izq;
    NodoOrtogonal* der;
public:
    NodoOrtogonal(xy indice,contenido cont);

    xy      getIndex(){return indice;}
    contenido  getContenido(){return cont;}

    void setIndex(xy indice){this->indice=indice;}
    void setContenido(contenido cont){this->cont=cont;}

    NodoOrtogonal* getUp(){return up;}
    NodoOrtogonal* getDown(){return down;}
    NodoOrtogonal* getder(){return der;}
    NodoOrtogonal* getizq(){return izq;}

    void setUp(NodoOrtogonal* up){this->up=up;}
    void setDown(NodoOrtogonal* down){this->down=down;}
    void setder(NodoOrtogonal* der){this->der=der;}
    void setizq(NodoOrtogonal* izq){this->izq=izq;}

};
//********************************************************************************
//************************CLASE LISTA ORTOGONAL***********************************
//********************************************************************************
class ListaOrtogonal
{

public:
    NodoOrtogonal* primerolistaHorizontal;
    NodoOrtogonal* ultimolistaHorizontal;
    NodoOrtogonal* primerolistaVertical;
    NodoOrtogonal* ultimolistaVertical;

    ListaOrtogonal();
    std::string insertarListaHorizontal(NodoOrtogonal* nuevo);
    std::string insertarListaVertical(NodoOrtogonal* nuevo);

private:
    void ordenarListaHorizontal(NodoOrtogonal* nuevo);
    void ordenarListaVertical(NodoOrtogonal* nuevo);

};


//********************************************************************************
//***********************CLASE NODO FILA******************************************
//********************************************************************************
class NodoCabeceraFila
{

public:

    NodoCabeceraFila(NodoOrtogonal* nuevo);
    nodoSalon* salon;
    std::string edificio;
    NodoCabeceraFila* arriba;
    NodoCabeceraFila*  abajo;
    ListaOrtogonal* listHorizontal;

};


//********************************************************************************
//************************CLASE LISTA FILA ***************************************
//********************************************************************************
class ListaCabeceraFila
{

public:
    NodoCabeceraFila* primero;
    NodoCabeceraFila* ultimo;

    ListaCabeceraFila();

    std::string insertar(NodoOrtogonal* nuevo);
private:
    NodoCabeceraFila* buscarFila(std::string edificio,int salon);
    void ordenar(NodoCabeceraFila* nuevo);
};

//********************************************************************************
//************************CLASE NODO COLUMNA *************************************
//********************************************************************************
class NodoCabeceraColumna
{

public:
    NodoCabeceraColumna(NodoOrtogonal *nuevo);
    std::string horaInicio;
    NodoCabeceraColumna* sig;
    NodoCabeceraColumna*  ant;
    ListaOrtogonal* listVertical;


};
//********************************************************************************
//************************CLASE LISTA COLUMNA ************************************
//********************************************************************************
class ListaCabeceraColumna
{

public:
    NodoCabeceraColumna* primero;
    NodoCabeceraColumna* ultimo;

    ListaCabeceraColumna();
    std::string insertar(NodoOrtogonal* nuevo);
 private:
    NodoCabeceraColumna* buscarCol(std::string horaInicio);
    void ordenar(NodoCabeceraColumna* nuevo);
};

//********************************************************************************
//************************CLASE matriz ************************************
//********************************************************************************

class matriz
{

public:

    matriz();
    ListaCabeceraFila* fila;
    ListaCabeceraColumna* col;
    std::string insertar(stOrtogonal datos,listCursos* cursos, listEdificios* edificios );
    void graficar();
    void generarDot(std::string nombre);
    std::string txtCabeceraCol();
    std::string txtCabeceraFila();

    std::string txtFilas();
    std::string txtColumnas();
};

#endif // MATRIZ_H
