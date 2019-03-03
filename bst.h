#ifndef BST_H
#define BST_H

#include<string>
#include <iostream>

/*****************************************************************************
*************************** Nodo bst       ************************************
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
    void setRaiz( nodoBst *r);
    nodoBst* getRaiz();
    bool estavacio();

    void preorden();
    void inorden();
    void insertar (catedratico valor);
    catedratico buscar(std::string codigo);

    private:
    void preorden(nodoBst *r);
    void inorden(nodoBst *r);
    nodoBst* insertar(nodoBst* raiz, catedratico dato);
    nodoBst* buscar(nodoBst* raiz, std::string codigo);

};



#endif // BST_H
