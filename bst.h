#ifndef BST_H
#define BST_H
#include<string>

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
    catedratico valorNodo(){ return ing; }
    nodoBst* getizq(){ return izq; }
    nodoBst* getder(){ return der; }
    // operaciones de modificación
    void nuevoValor(catedratico n){ this->ing = n; }
    void setizq(nodoBst* n){ izq = n; }
    void setder(nodoBst* n){ der = n; }


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
    nodoBst raizArbol();
    bool esVacio();
    nodoBst * hijoIzdo();

    nodoBst* hijoDcho();
    nodoBst* nuevoArbol(nodoBst* izq, catedratico ing, nodoBst* der);


    //metodos buscar
    catedratico buscar(catedratico ing);
    nodoBst* buscar(nodoBst* raiz, catedratico ing);




    void insertar (catedratico valor);
    nodoBst* insertar(nodoBst* raiz, catedratico dato);


};



#endif // BST_H
