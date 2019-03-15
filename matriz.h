#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <listcursos.h>

struct index{

    std::string  horaInicio;
    int no_salon;
};

struct contenido
{
    std::string horaFinal;
    nodolist* curso;
};


//********************************************************************************
//************************CLASE NODO ORTOGONAL************************************
//********************************************************************************
class NodoOrtogonal
{
private:
    index indice;
    contenido cont;

    NodoOrtogonal* up;
    NodoOrtogonal* down;
    NodoOrtogonal* izq;
    NodoOrtogonal* der;
public:
    NodoOrtogonal(index indice,contenido cont);

    index      getIndex(){return indice;}
    contenido  getContenido(){return cont;}

    void setIndex(index indice){this->indice=indice;}
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
    NodoOrtogonal* primeroFila;
    NodoOrtogonal* ultimoFila;
    NodoOrtogonal* primeroCol;
    NodoOrtogonal* ultimoCol;


    ListaOrtogonal();
    std::string insertarFila(NodoOrtogonal* nuevo);
    bool buscarCursoFila(std::string curso);
    void ordenarFila(NodoOrtogonal* nuevo);


    std::string insertarCol(NodoOrtogonal* nuevo);
    bool buscarCursoCol(std::string nuevo);
    void ordenarCol(NodoOrtogonal* nuevo);

};


class matriz
{

public:
    matriz();
};

#endif // MATRIZ_H
