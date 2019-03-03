#include "bst.h"

/*****************************************************************************
*************************** Nodo bst      ************************************
******************************************************************************
******************************************************************************
******************************************************************************/

nodoBst::nodoBst(catedratico ing)
{
    this->ing = ing;
    izq = der = nullptr;
}


nodoBst::nodoBst(catedratico ing,nodoBst* izq,nodoBst* der)
{
    this->ing = ing;
    this->izq = izq;
    this->der = der;
}


/*****************************************************************************
*************************** arbol binario ************************************
******************************************************************************
******************************************************************************
******************************************************************************/

bst::bst()
{
    raiz = nullptr;
}


bst::bst(nodoBst* r)
{
    raiz = r;
}

void bst::setRaiz( nodoBst *r)
{
    raiz = r;
}

nodoBst * bst::getRaiz()
{
    return raiz;
}

nodoBst bst::raizArbol()
{
    if(raiz)
    return *raiz;
    else
    throw " arbol vacio";
}

bool bst::esVacio()
{
    return raiz == nullptr;
}


nodoBst * bst::hijoIzdo()
{
    if(raiz)
    return raiz->getder();
    else
    throw " arbol vacio";
}


nodoBst *bst::hijoDcho()
{
    if(raiz)
    return raiz->getder();
    else
    throw " arbol vacio";
}

nodoBst* bst::nuevoArbol(nodoBst* izq, catedratico dato, nodoBst* der)
{
    return new nodoBst( dato,izq, der);
}


catedratico bst::buscar(catedratico ing)
{
    return buscar(raiz, ing)->valorNodo();
}

 nodoBst* bst::buscar(nodoBst* raiz, catedratico ing)
{
    if (raiz == nullptr)
    return nullptr;
    else if (ing.id == raiz->valorNodo().id)
    return raiz;
    else if (ing.id < raiz->valorNodo().id)
    return buscar(raiz->getizq(), ing);
    else
    return buscar (raiz->getder(), ing);
}




 void bst::insertar (catedratico valor)
 {
    raiz = insertar(raiz, valor);
 }


 nodoBst* bst::insertar(nodoBst* raiz, catedratico dato)
 {
    if (raiz == nullptr)
     raiz = new nodoBst(dato);
     else if (dato.id < raiz->valorNodo().id)
    {
      nodoBst *iz;

      iz = insertar(raiz->getizq(), dato);
      raiz->setizq(iz);
    }
    else if (dato.id > raiz->valorNodo().id)

 {
 nodoBst *dr;
 dr = insertar(raiz->getder(), dato);
 raiz->setder(dr);
 }
 else
 throw "Nodo duplicado"; // tratamiento de repetición
 return raiz;
 }


