#include "matriz.h"

//********************************************************************************
//************************CLASE NODO ORTOGONAL************************************
//********************************************************************************
NodoOrtogonal::NodoOrtogonal(index indice,contenido cont))
{
    this->cita = cita;
    this->fila = fila;
    this->col  = col ;

    this->arriba    = NULL;
    this->abajo     = NULL;
    this->anterior  = NULL;
    this->siguiente = NULL;
}

//********************************************************************************
//************************CLASE LISTA ORTOGONAL***********************************
//********************************************************************************
ListaOrtogonal::ListaOrtogonal()
{
    primeroFila = NULL;
    primeroCol  = NULL;
    ultimoFila  = NULL;
    ultimoCol   = NULL;
}

std::string ListaOrtogonal::insertarFila(NodoOrtogonal* nuevo)
{

    std::string respuesta="";

     if(primeroFila==NULL)
    {
        primeroFila=nuevo;
        primeroFila->setSig(NULL);
        primeroFila->setAnt(NULL);
        ultimoFila=primeroFila;

        respuesta="Se ingreso el primer nodo fila";
    }else if(!(buscarTransaccionFila(nuevo->getCita().transaccion)))
    {
        ordenarFila(nuevo);

        respuesta="Se ingreso correctamente nodo fila";
    }else
    {
        respuesta="Id existe nodo fila ";
    }

    return respuesta;
}

bool ListaOrtogonal::buscarTransaccionFila(std::string transaccion)
{
    NodoOrtogonal* tmp = primeroFila;
    while (tmp!=NULL) {
        if(tmp->getCita().transaccion ==transaccion){
            return true;
        }
        tmp = tmp->getSig();
    }
    return false;

}

void ListaOrtogonal::ordenarFila(NodoOrtogonal*  nuevo)
{

    NodoOrtogonal* actualFila = primeroFila;

    //si el nuevo es menor al primero
    if(nuevo->getCol().diaEntero < primeroFila->getCol().diaEntero)
    {
        primeroFila->setAnt(nuevo);
        nuevo->setSig(primeroFila);
        nuevo->setAnt(NULL);
        primeroFila=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo->getCol().diaEntero > ultimoFila->getCol().diaEntero)
    {
        ultimoFila->setSig(nuevo);
        nuevo->setAnt(ultimoFila);
        nuevo->setSig(NULL);
        ultimoFila= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualFila!=ultimoFila) {

            if((nuevo->getCol().diaEntero > actualFila->getCol().diaEntero)
                    &&(nuevo->getCol().diaEntero < actualFila->getSig()->getCol().diaEntero)  )
            {
                nuevo->setSig(actualFila->getSig());
                nuevo->setAnt(actualFila);
                actualFila->getSig()->setAnt(nuevo);
                actualFila->setSig(nuevo);
                break;
            }

            actualFila= actualFila->getSig();
        }
    }

}

std::string ListaOrtogonal::insertarCol(NodoOrtogonal* nuevo)
{


    std::string respuesta="";

    if(primeroCol==NULL)
    {
        primeroCol= nuevo;
        primeroCol->setAbajo(NULL);
        primeroCol->setArriba(NULL);
        ultimoCol = primeroCol;
        respuesta="se ingreso correctamente nodo col";

    }else if(!(buscarTransaccionCol(nuevo->getCita().transaccion)))
    {
        ordenarCol(nuevo);
        respuesta="se ingreso correctamente nodo col";
    }else
    {
        respuesta="Id existe ";
    }

    return respuesta;

}

bool ListaOrtogonal::buscarTransaccionCol(std::string transaccion)
{

    NodoOrtogonal* tmp = primeroCol;
    while (tmp!=NULL) {
        if(tmp->getCita().transaccion ==transaccion){
            return true;
        }
        tmp = tmp->getAbajo();
    }
    return false;
}

void ListaOrtogonal::ordenarCol(NodoOrtogonal* nuevo)
{

    NodoOrtogonal* actualCol = primeroCol;

    //si el nuevo es menor al primero
    if(nuevo->getFila().horaInicio <= primeroCol->getFila().horaInicio)
    {
        primeroCol->setArriba(nuevo);
        nuevo->setAbajo(primeroCol);
        nuevo->setArriba(NULL);
        primeroCol=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo->getFila().horaInicio >= ultimoCol->getFila().horaInicio)
    {
        ultimoCol->setAbajo(nuevo);
        nuevo->setArriba(ultimoCol);
        nuevo->setAbajo(NULL);
        ultimoCol= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualCol!=ultimoCol) {

            if((nuevo->getFila().horaInicio>= actualCol->getFila().horaInicio)
                    &&(nuevo->getFila().horaInicio<= actualCol->getAbajo()->getFila().horaInicio))
            {
                nuevo->setAbajo(actualCol->getAbajo());
                nuevo->setArriba(actualCol);
                actualCol->getAbajo()->setArriba(nuevo);
                actualCol->setAbajo(nuevo);
                break;
            }

            actualCol= actualCol->getAbajo();
        }
    }


}

matriz::matriz()
{

}

