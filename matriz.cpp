#include "matriz.h"

//********************************************************************************
//************************CLASE NODO ORTOGONAL************************************
//********************************************************************************
NodoOrtogonal::NodoOrtogonal(index indice,contenido cont)
{
    this->indice = indice;
    this->cont = cont;
    this->up   = nullptr;
    this->down = nullptr;
    this->der  = nullptr;
    this->izq  = nullptr;
}

//********************************************************************************
//************************CLASE LISTA ORTOGONAL***********************************
//********************************************************************************
ListaOrtogonal::ListaOrtogonal()
{
    primerolistaHorizontal = nullptr;
    primerolistaVertical  = nullptr;
    ultimolistaHorizontal  = nullptr;
    ultimolistaVertical   = nullptr;
}

std::string ListaOrtogonal::insertarListaHorizontal(NodoOrtogonal* nuevo)
{

    std::string respuesta="";

     if(primerolistaHorizontal==nullptr)
    {
        primerolistaHorizontal=nuevo;
        primerolistaHorizontal->setder(nullptr);
        primerolistaHorizontal->setizq(nullptr);
        ultimolistaHorizontal=primerolistaHorizontal;

        respuesta="Se ingreso el primer nodo en la lista horizontal";
    }else
    {
        ordenarListaHorizontal(nuevo);

        respuesta="Se ingreso  y se ordeno el  nodo en la lista horizontal ";
    }

    return respuesta;
}

void ListaOrtogonal::ordenarListaHorizontal(NodoOrtogonal*  nuevo)
{
    NodoOrtogonal* actualFila = primerolistaHorizontal;


    //si el nuevo es menor al primero
    if(nuevo->getIndex().horaInicio<= primerolistaHorizontal->getIndex().horaInicio)
    {
        primerolistaHorizontal->setizq(nuevo);
        nuevo->setder(primerolistaHorizontal);
        nuevo->setizq(nullptr);
        primerolistaHorizontal=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo->getIndex().horaInicio >= ultimolistaHorizontal->getIndex().horaInicio)
    {
        ultimolistaHorizontal->setder(nuevo);
        nuevo->setizq(ultimolistaHorizontal);
        nuevo->setder(nullptr);
        ultimolistaHorizontal= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualFila!=ultimolistaHorizontal) {

            if((nuevo->getIndex().horaInicio > actualFila->getIndex().horaInicio)
               &&(nuevo->getIndex().horaInicio< actualFila->getder()->getIndex().horaInicio))
            {
                nuevo->setder(actualFila->getder());
                nuevo->setizq(actualFila);
                actualFila->getder()->setizq(nuevo);
                actualFila->setder(nuevo);
                break;
            }

            actualFila= actualFila->getder();
        }
    }

    /*
    NodoOrtogonal* actualFila = primerolistaHorizontal;
    int nuevo_salon =nuevo->getIndex().salon->getValor().no_salon;

    //si el nuevo es menor al primero
    if(nuevo_salon<= primerolistaHorizontal->getIndex().salon->getValor().no_salon)
    {
        primerolistaHorizontal->setizq(nuevo);
        nuevo->setder(primerolistaHorizontal);
        nuevo->setizq(nullptr);
        primerolistaHorizontal=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo_salon >= ultimolistaHorizontal->getIndex().salon->getValor().no_salon)
    {
        ultimolistaHorizontal->setder(nuevo);
        nuevo->setizq(ultimolistaHorizontal);
        nuevo->setder(nullptr);
        ultimolistaHorizontal= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualFila!=ultimolistaHorizontal) {

            if((nuevo_salon > actualFila->getIndex().salon->getValor().no_salon)
               &&(nuevo_salon< actualFila->getder()->getIndex().salon->getValor().no_salon))
            {
                nuevo->setder(actualFila->getder());
                nuevo->setizq(actualFila);
                actualFila->getder()->setizq(nuevo);
                actualFila->setder(nuevo);
                break;
            }

            actualFila= actualFila->getder();
        }
    }
*/
}

std::string ListaOrtogonal::insertarListaVertical(NodoOrtogonal* nuevo)
{


    std::string respuesta="";

    if(primerolistaVertical==nullptr)
    {
        primerolistaVertical= nuevo;
        primerolistaVertical->setDown(nullptr);
        primerolistaVertical->setUp(nullptr);
        ultimolistaVertical = primerolistaVertical;
        respuesta="se ingreso correctamente nodo en la lista vertical";

    }else
    {
        ordenarListaVertical(nuevo);
        respuesta="se ingreso y se ordeno el nodo en la lista vertical";
    }
    return respuesta;

}

void ListaOrtogonal::ordenarListaVertical(NodoOrtogonal* nuevo)
{

    NodoOrtogonal* actualCol = primerolistaVertical;
    int nuevo_salon =nuevo->getIndex().salon->getValor().no_salon;

    //si el nuevo es menor al primero
    if(nuevo_salon <= primerolistaVertical->getIndex().salon->getValor().no_salon)
    {
        primerolistaVertical->setUp(nuevo);
        nuevo->setDown(primerolistaVertical);
        nuevo->setUp(nullptr);
        primerolistaVertical=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo_salon >= ultimolistaVertical->getIndex().salon->getValor().no_salon)
    {
        ultimolistaVertical->setDown(nuevo);
        nuevo->setUp(ultimolistaVertical);
        nuevo->setDown(nullptr);
        ultimolistaVertical= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualCol!=ultimolistaVertical) {

            if((nuevo_salon >= actualCol->getIndex().salon->getValor().no_salon)
                    &&(nuevo_salon <= actualCol->getDown()->getIndex().salon->getValor().no_salon))
            {
                nuevo->setDown(actualCol->getDown());
                nuevo->setUp(actualCol);
                actualCol->getDown()->setUp(nuevo);
                actualCol->setDown(nuevo);
                break;
            }

            actualCol= actualCol->getDown();
        }
    }



/*
    NodoOrtogonal* actualCol = primerolistaVertical;

    //si el nuevo es menor al primero
    if(nuevo->getIndex().horaInicio <= primerolistaVertical->getIndex().horaInicio)
    {
        primerolistaVertical->setUp(nuevo);
        nuevo->setDown(primerolistaVertical);
        nuevo->setUp(nullptr);
        primerolistaVertical=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo->getIndex().horaInicio>= ultimolistaVertical->getIndex().horaInicio)
    {
        ultimolistaVertical->setDown(nuevo);
        nuevo->setUp(ultimolistaVertical);
        nuevo->setDown(nullptr);
        ultimolistaVertical= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualCol!=ultimolistaVertical) {

            if((nuevo->getIndex().horaInicio >= actualCol->getIndex().horaInicio)
                    &&(nuevo->getIndex().horaInicio<= actualCol->getDown()->getIndex().horaInicio))
            {
                nuevo->setDown(actualCol->getDown());
                nuevo->setUp(actualCol);
                actualCol->getDown()->setUp(nuevo);
                actualCol->setDown(nuevo);
                break;
            }

            actualCol= actualCol->getDown();
        }
    }
*/
}

//********************************************************************************
//***********************CLASE NODO FILA******************************************
//********************************************************************************
NodoCabeceraFila::NodoCabeceraFila(NodoOrtogonal* nuevo)
{
    this->salon = nuevo->getIndex().salon;
    this->edificio=nuevo->getIndex().edificio;
    this->abajo =nullptr;
    this->arriba=nullptr;
    this->listHorizontal = new ListaOrtogonal();

}

//********************************************************************************
//************************CLASE LISTA FILA ***************************************
//********************************************************************************
ListaCabeceraFila::ListaCabeceraFila()
{
    this->primero=nullptr;
    this->ultimo =nullptr;

}

std::string ListaCabeceraFila::insertar(NodoOrtogonal *nuevo)
{

    std::string respuesta="";
    int no_salon = nuevo->getIndex().salon->getValor().no_salon;
    std::string edificio = nuevo->getIndex().edificio;
    if(primero==nullptr)
    {
        NodoCabeceraFila* nuevoFila = new NodoCabeceraFila(nuevo);
        respuesta =  nuevoFila->listHorizontal->insertarListaHorizontal(nuevo);
        primero=nuevoFila;
        primero->abajo =nullptr;
        primero->arriba = nullptr;
        ultimo=primero;

        respuesta ="Se ingreso la primera Fila y "+respuesta;

    }//si no existe el nodo se deberar crear y ordenar en la lista
    else if(buscarFila(edificio,no_salon)==nullptr)
    {
        NodoCabeceraFila* nuevoFila = new NodoCabeceraFila(nuevo);
        respuesta =  nuevoFila->listHorizontal->insertarListaHorizontal(nuevo);


        ordenar(nuevoFila);
        respuesta ="Se agrego la Fila se ordeno y "+respuesta;

    }//si el nodo existe solo se utliza y se envia el nodoortogonal
    else
    {
        NodoCabeceraFila* aux = buscarFila(edificio,no_salon);
        respuesta= aux->listHorizontal->insertarListaHorizontal(nuevo);
        respuesta ="se utilizo la fila ya creada y "+respuesta;

    }
    return respuesta;
}

NodoCabeceraFila* ListaCabeceraFila::buscarFila(std::string edificio,int salon)
{
    NodoCabeceraFila* tmp = primero;

    while (tmp!=nullptr) {
        if((tmp->edificio==edificio)&&
                (tmp->salon->getValor().no_salon==salon)){
            return tmp;
        }
        tmp = tmp->abajo;
    }
    return nullptr;
}

void ListaCabeceraFila::ordenar(NodoCabeceraFila* nuevo)
{
    NodoCabeceraFila* actual = primero;
    int nuevo_salon = nuevo->salon->getValor().no_salon;

    //si el nuevo es menor al primero
    if(nuevo_salon < primero->salon->getValor().no_salon)
    {
        primero->arriba=nuevo;
        nuevo->abajo = primero;
        nuevo->arriba= nullptr;
        primero=nuevo;


    }//si  es mayor o igual al ultimo
    else if(nuevo_salon >= ultimo->salon->getValor().no_salon)
    {
        ultimo->abajo = nuevo;
        nuevo->arriba = ultimo;
        nuevo->abajo  = nullptr;
        ultimo = nuevo;

    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while(actual!=ultimo)
        {
            if((nuevo_salon >= actual->salon->getValor().no_salon)
               &&(nuevo_salon <= actual->abajo->salon->getValor().no_salon))
            {
                nuevo->abajo =actual->abajo;
                nuevo->arriba =  actual;
                nuevo->abajo->arriba =nuevo;
                actual->abajo = nuevo;
                break;
            }

            actual = actual->abajo;
        }

    }
}
//********************************************************************************
//************************CLASE NODO COLUMNA *************************************
//********************************************************************************
NodoCabeceraColumna::NodoCabeceraColumna(NodoOrtogonal* nuevo)
{
    this->horaInicio = nuevo->getIndex().horaInicio;
    this->sig=nullptr;
    this->ant =nullptr;
    this->listVertical=new ListaOrtogonal();

}
//********************************************************************************
//************************CLASE LISTA COLUMNA ************************************
//********************************************************************************
ListaCabeceraColumna::ListaCabeceraColumna()
{
    this->primero=nullptr;
    this->ultimo=nullptr;
}

std::string ListaCabeceraColumna::insertar(NodoOrtogonal* nuevo){

    std::string respuesta="";

    if(primero==nullptr)
    {
        NodoCabeceraColumna* nuevoCol = new NodoCabeceraColumna(nuevo);
        respuesta =  nuevoCol->listVertical->insertarListaVertical(nuevo);
        primero=nuevoCol;
        primero->sig =nullptr;
        primero->ant = nullptr;
        ultimo=primero;

        respuesta ="Se ingreso la primera Columna y "+respuesta;

    }//si no existe el nodo se deberar crear y ordenar en la lista
    else if(buscarCol(nuevo->getIndex().horaInicio)==nullptr)
    {
        NodoCabeceraColumna* nuevoCol = new NodoCabeceraColumna(nuevo);
        respuesta = nuevoCol->listVertical->insertarListaVertical(nuevo);

        ordenar(nuevoCol);
        respuesta ="Se agrego la Columna se ordeno y "+respuesta;

    }//si el nodo existe solo se utliza y se envia el nodoortogonal
    else
    {
        NodoCabeceraColumna* aux = buscarCol(nuevo->getIndex().horaInicio);
        respuesta=aux->listVertical->insertarListaVertical(nuevo);
        respuesta ="se utilizo la Columna ya creada y "+respuesta;
    }
    return respuesta;


}


NodoCabeceraColumna* ListaCabeceraColumna::buscarCol(std::string horaInicio){

    NodoCabeceraColumna* tmp = primero;

    while (tmp!=nullptr) {
        if(tmp->horaInicio == horaInicio){
            return tmp;
        }
        tmp = tmp->sig;
    }
    return nullptr;

}


void ListaCabeceraColumna::ordenar(NodoCabeceraColumna* nuevo){

    NodoCabeceraColumna* actual = primero;

    //si el nuevo es menor al primero
    if(nuevo->horaInicio< primero->horaInicio)
    {
        primero->ant=nuevo;
        nuevo->sig = primero;
        nuevo->ant= nullptr;
        primero=nuevo;


    }//si  es mayor o igual al ultimo
    else if(nuevo->horaInicio >= ultimo->horaInicio)
    {
        ultimo->sig = nuevo;
        nuevo->ant = ultimo;
        nuevo->sig  = nullptr;
        ultimo = nuevo;

    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while(actual!=ultimo)
        {
            if((nuevo->horaInicio >= actual->horaInicio)
               &&(nuevo->horaInicio<= actual->sig->horaInicio))
            {
                nuevo->sig =actual->sig;
                nuevo->ant =  actual;
                actual->sig->ant =nuevo;
                actual->sig = nuevo;
                break;
            }
            actual = actual->sig;
        }

    }

}

//********************************************************************************
//************************CLASE matriz        ************************************
//********************************************************************************

matriz::matriz()
{
    this->fila = new ListaCabeceraFila();
    this->col = new ListaCabeceraColumna();

}

std::string  matriz::insertar(stOrtogonal datos,listCursos* cursos, listEdificios* edificios ){

    std::string respuesta="";
    salonEdificio EdificioEncontrado = edificios->obtnerSalon(datos.edificio,datos.no_salon);
    nodoCurso* cursoEncontrado = cursos->buscarId(datos.idCurso);

    if((EdificioEncontrado.salon!=nullptr)&&(cursoEncontrado!= nullptr))
    {
        index indice;
        indice.horaInicio=datos.horaInicio;
        indice.salon = EdificioEncontrado.salon;
        indice.edificio= EdificioEncontrado.edificio;
        contenido cont ;
        cont.horaFinal = datos.horaFinal;
        cont.curso = cursoEncontrado;
        NodoOrtogonal* nuevo = new NodoOrtogonal(indice,cont);

        respuesta +="{"+fila->insertar(nuevo)+"}";
        respuesta +="{"+col->insertar(nuevo)+"}";

    }else{


        respuesta ="no se encontro el salon o el edificio enviado o el curso";
    }


    return  respuesta;

}



void matriz::graficar(){}
void matriz::generarDot(){}









