#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <list>



/*****************************************************************************
***************************      Nodo bst ************************************
******************************************************************************
******************************************************************************
******************************************************************************/

struct catedratico{
    std::string id;
    std::string nombre;
};



class nodoBst
{
    protected:
        catedratico  ing;
        nodoBst *izq;
        nodoBst *der;

    public:
    nodoBst(catedratico ing);
    nodoBst(catedratico ing,nodoBst* izq,nodoBst* der);


    // operaciones de acceso
    catedratico getValor(){ return ing; }
    nodoBst* getizq(){ return izq; }
    nodoBst* getder(){ return der; }
    // operaciones de modificación
    void setValor(catedratico n){ this->ing = n; }
    void setizq(nodoBst* n){ izq = n; }
    void setder(nodoBst* n){ der = n; }

    void imprimir();

};

/*****************************************************************************
*************************** arbol binario ************************************
******************************************************************************
******************************************************************************
******************************************************************************/


class bst
{
    protected:
     nodoBst* raiz;
    public:
    bst();
    bst(nodoBst *r);
    bool estavacio();
    void preorden();
    void inorden();
    void postorden();
    void insertar (catedratico valor);
    catedratico buscar(std::string codigo);
    void graficar();
    void graficarPreorden();
    void insertarLista(std::list<catedratico> lista);
    std::list<catedratico> obtenerArbol();


private:
    std::string txtgrafica = "";
    std::list<catedratico> listarbol;

    void obtenerArbol(nodoBst* r);
    void insertarTexto(std::string texto);
    void preorden(nodoBst *r);
    void inorden(nodoBst *r);
    void postorden(nodoBst *r);
    nodoBst* insertar(nodoBst* raiz, catedratico dato);
    nodoBst* buscar(nodoBst* raiz, std::string codigo);
    void textoDot(std::string nombre);
    void graficarPreorden(nodoBst* raiz);



};



#endif // BST_H
