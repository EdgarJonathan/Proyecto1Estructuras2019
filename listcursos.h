#ifndef LISTCURSOS_H
#define LISTCURSOS_H
#include<string>
#include<bst.h>
#include <variables.h>


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

class nodoCurso
{
    protected:
    Curso curso;
    nodoBst* catedratico;
    nodoCurso* siguiente;

    public:
    //constructor
    nodoCurso(Curso curso,bst*arbol);
    // operaciones de acceso
    Curso getValor(){ return curso; }
    nodoBst* getCatedratico(){return catedratico;}
    nodoCurso* getSig(){ return siguiente; }
    // operaciones de modificación
    void setValor(Curso n){ this->curso = n; }
    void setSig(nodoCurso* n){ siguiente = n; }
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
    nodoCurso* primero;
    nodoCurso* ultimo;
    std::string insertar(Curso curso,bst* arbol);
    std::string insertarLista(std::list<Curso> ListaCurso, bst* arbol);
    void imprimirLista();
    void graficar(std::string dotArbol);
    nodoCurso* buscarId(std::string d);
    void editarCurso(editCurso curso);
    std::list<Curso> getCursos();

private:
      std::string dotEnlacesListaArbol="";
      void ordenarLista(nodoCurso* nuevo);

      std::string subGrafoArbol(std::string dotArbol);
      std::string subGrafoLista();
      void generarDot(std::string nombre,std::string dotArbol);


};

#endif // LISTCURSOS_H
