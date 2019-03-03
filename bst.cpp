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

void nodoBst::imprimir()
{
    std::cout<<"codigo: "<<ing.id<<", Ing: "<<ing.nombre<<std::endl;

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


bool bst::estavacio()
{
    return raiz == nullptr;
}


catedratico bst::buscar(std::string codigo)
{
    nodoBst* nodo = buscar(raiz, codigo);

   if(nodo == nullptr)
   {
    return nodo->getValor();
   }else {
       return {"NULL","NULL"};
   }

}

 nodoBst* bst::buscar(nodoBst* raiz, std::string codigo)
{
    if (raiz == nullptr)
    return nullptr;
    else if (codigo == raiz->getValor().id)
    return raiz;
    else if (codigo < raiz->getValor().id)
    return buscar(raiz->getizq(), codigo);
    else
    return buscar (raiz->getder(), codigo);
}




 void bst::insertar (catedratico valor)
 {
    this->raiz = insertar(this->raiz, valor);
 }


 nodoBst* bst::insertar(nodoBst* raiz, catedratico dato)
 {
    if (raiz == nullptr){

        raiz = new nodoBst(dato);

    }else if (dato.id < raiz->getValor().id)
    {
      nodoBst *iz;
      iz = insertar(raiz->getizq(), dato);
      raiz->setizq(iz);
    }
    else if (dato.id > raiz->getValor().id)
    {
        nodoBst *dr;
        dr = insertar(raiz->getder(), dato);
        raiz->setder(dr);
     }
    else{

        std::cout<<"---Nodo Duplicado---"<<std::endl;
        std::cout<<"codigo: "<<raiz->getValor().id;
        std::cout<<"  catedratico: "<<raiz->getValor().nombre<<"\n\n";

    }
   return raiz;
 }


 void bst::preorden()
 {
    std::cout <<"\n";
    std::cout <<"---------preorden----------- \n";
    preorden(this->raiz);
 }



 void bst::preorden(nodoBst *r)
 {
     if (r != nullptr)
    {
        r->imprimir();
        preorden (r->getizq());
        preorden (r->getder());
     }
 }

 void bst::inorden()
 {
     std::cout <<"\n";
     std::cout <<"----------inorden------------ \n";
     inorden(this->raiz);
 }

 void bst::inorden(nodoBst* r)
 {
     if(r!= nullptr)
     {
        inorden(r->getizq());
        r->imprimir();
        inorden(r->getder());
     }
 }















