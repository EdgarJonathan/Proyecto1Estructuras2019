#ifndef LISTASEMANA_H
#define LISTASEMANA_H
#include "matriz.h"


/*****************************************************************************
**********************   Nodo Lista Semana************************************
******************************************************************************
******************************************************************************
******************************************************************************/
class NodoSemana{

public:
    std::string dia;
    matriz* miMatriz;
    NodoSemana* siguiente;

    //constructor
    NodoSemana(stOrtogonal datos);

};




/*****************************************************************************
**********************   Nodo Lista Semana************************************
******************************************************************************
******************************************************************************
******************************************************************************/


class ListaSemana
{
public:
    std::string enlaces ="";
    ListaSemana();
    NodoSemana* primero;
    NodoSemana* ultimo;

    std::string insertar(stOrtogonal datos,listCursos* cursos, listEdificios* edificios);
    void ordenar(NodoSemana* nuevo);
    NodoSemana* buscarDia(std::string dia);
    void graficar();
    void generarDot(std::string nombre);
    std::string subGrafoLista();
};

#endif // LISTASEMANA_H
