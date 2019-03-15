#ifndef LISTCURSOS_H
#define LISTCURSOS_H
#include<string>
#include<bst.h>
using namespace std;

/*****************************************************************************
***************************     Nodo list ************************************
******************************************************************************
******************************************************************************
******************************************************************************/

struct Curso{
    std::string id;
    std::string nombre;
    std::string idCatedratico;
};

class nodolist
{
    protected:
    Curso curso;
    nodoBst* catedratico;
    nodolist* siguiente;

    public:
    //constructor
    nodolist(Curso curso,bst*arbol);
    // operaciones de acceso
    Curso getValor(){ return curso; }
    nodoBst* getCatedratico(){return catedratico;}
    nodolist* getSig(){ return siguiente; }
    // operaciones de modificación
    void setValor(Curso n){ this->curso = n; }
    void setSig(nodolist* n){ siguiente = n; }
    void setCatedratico(nodoBst* cat){ this->catedratico=cat;}



};


/*****************************************************************************
*************************** lista Enlazada************************************
******************************************************************************
******************************************************************************
******************************************************************************/

class listCursos
{
public:
    listCursos();
    nodolist* primero;
    nodolist* ultimo;
    std::string insertar(Curso curso,bst* arbol);
    void imprimirLista();
    void graficar(std::string dotArbol);

private:
      std::string dotEnlacesListaArbol="";
      void ordenarLista(nodolist* nuevo);
      nodolist* buscarId(std::string d);
      std::string subGrafoArbol(std::string dotArbol);
      std::string subGrafoLista();
      void generarDot(std::string nombre,std::string dotArbol);


};

#endif // LISTCURSOS_H
