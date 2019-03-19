#include "listedificios.h"
#include <iostream>

/*****************************************************************************
*************************** Nodo Salon************************************
******************************************************************************
******************************************************************************
******************************************************************************/

nodoSalon::nodoSalon(Salon salon)
{
    this->salon = salon;
    this->sig = nullptr;
    this->ant = nullptr;
}


/*****************************************************************************
*************************** listEdificios  ***********************************
******************************************************************************
******************************************************************************
******************************************************************************/

listSalon::listSalon(){

    primero = nullptr;
    ultimo  = nullptr;
}

std::string listSalon::insertar(Salon salon){

    nodoSalon* nuevo = new nodoSalon(salon);

    if(primero==nullptr)
    {
        primero = nuevo;
        ultimo = primero;

        return "se agrego exitosamente";

    }else if(buscarId(nuevo->getValor().no_salon)==nullptr)
    {
        ordenarLista(nuevo);
        return "se agrego exitosamente";
    }else{

        return "numero de salon ya existe";
    }

}

void listSalon::ordenarLista(nodoSalon* nuevo){

    nodoSalon* actual = primero;

    //el nuevo nodo es menor al primero
    if(nuevo->getValor().no_salon < primero->getValor().no_salon)
    {
        primero->setAnt(nuevo);
        nuevo->setSig(primero);
        nuevo->setAnt(nullptr);
        primero =nuevo;
    }//si es mayor o igual al ultimo
    else if(nuevo->getValor().no_salon >= ultimo->getValor().no_salon){

        ultimo->setSig(nuevo);
        nuevo->setAnt(ultimo);
        nuevo->setSig(nullptr);
        ultimo = nuevo;
    }//recorriendo la lista comparando:
    //si nuevo es mayor o igual al acutal
    //y si nuevo es menor o igual al siguiente de actual
    else {
        while (actual!=ultimo) {

            if ((nuevo->getValor().no_salon >= actual->getValor().no_salon) &&
               (nuevo->getValor().no_salon <= actual->getSig()->getValor().no_salon))
            {
                nuevo->setSig(actual->getSig());
                nuevo->setAnt(actual);
                actual->getSig()->setAnt(nuevo);
                actual->setSig(nuevo);
                break;
            }

            actual = actual->getSig();
        }
    }

}


nodoSalon* listSalon::buscarId(int d){

    nodoSalon* tmp = primero;
    while (tmp!=nullptr) {
        if(tmp->getValor().no_salon == d)
        {
            return tmp;
        }
       tmp = tmp->getSig();
    }
    return  nullptr;
}

std::list<Salon> listSalon::linealizar(){
    std::list<Salon> lista;
    nodoSalon* tmp = primero;
    while (tmp != nullptr) {
        lista.push_back(tmp->getValor());
        tmp = tmp->getSig();
    }
    return lista;
}

void listSalon::imprimirLista(){

    nodoSalon* actual =primero;
    std::string salon="";
    std::string capacidad="";
    while(actual!=nullptr)
    {
        salon= std::to_string(actual->getValor().no_salon);
        capacidad = std::to_string(actual->getValor().capacidad);
        std::cout <<"<-[salon: "+salon+" capacidad: "+capacidad+"]->"<<std::endl;

        actual=actual->getSig();
    }

}
/*****************************************************************************
*************************** Nodo Edificios************************************
******************************************************************************
******************************************************************************
******************************************************************************/
nodoEdificio::nodoEdificio(std::string edificio)
{
    this->edificio =edificio;
    this->sig = nullptr;
    this->ant = nullptr;
}

void nodoEdificio::insertarSalon(int salon,int capacidad)
{
    this->salones->insertar({salon,capacidad});
}

/*****************************************************************************
*************************** listEdificios  ***********************************
******************************************************************************
******************************************************************************
******************************************************************************/

listEdificios::listEdificios(){
    primero = nullptr;
    ultimo  = nullptr;
}

std::string listEdificios::insertar(building edificio){

    nodoEdificio* nuevo = new nodoEdificio(edificio.edificio);

    if(primero==nullptr)
    {
        nuevo->insertarSalon(edificio.no_salon,edificio.capacidad);
        primero = nuevo;
        ultimo = primero;

        return "se agrego exitosamente";

    }else if(buscarId(nuevo->getEdificioString())==nullptr)
    {
        nuevo->insertarSalon(edificio.no_salon,edificio.capacidad);
        ordenarLista(nuevo);
        return "se agrego exitosamente";
    }else{

        nodoEdificio* encontrado = buscarId(nuevo->getEdificioString());
        encontrado->insertarSalon(edificio.no_salon,edificio.capacidad);
        return "se agrego exitosamente";
    }

}

void listEdificios::ordenarLista(nodoEdificio* nuevo){

    nodoEdificio* actual = primero;

    //el nuevo nodo es menor al primero
    if(nuevo->getEdificioString() <= primero->getEdificioString())
    {
        primero->setAnt(nuevo);
        nuevo->setSig(primero);
        nuevo->setAnt(nullptr);
        primero =nuevo;
    }//si es mayor o igual al ultimo
    else if(nuevo->getEdificioString() >= ultimo->getEdificioString()){

        ultimo->setSig(nuevo);
        nuevo->setAnt(ultimo);
        nuevo->setSig(nullptr);
        ultimo = nuevo;
    }//recorriendo la lista comparando:
    //si nuevo es mayor o igual al acutal
    //y si nuevo es menor o igual al siguiente de actual
    else {
        while (actual!=ultimo) {

            if ((nuevo->getEdificioString() >= actual->getEdificioString()) &&
               (nuevo->getEdificioString() <= actual->getSig()->getEdificioString()))
            {
                nuevo->setSig(actual->getSig());
                nuevo->setAnt(actual);
                actual->getSig()->setAnt(nuevo);
                actual->setSig(nuevo);
                break;
            }

            actual = actual->getSig();
        }
    }

}


nodoEdificio* listEdificios::buscarId(std::string edificio){

    nodoEdificio* tmp = primero;
    while (tmp!=nullptr) {
        if(tmp->getEdificioString() == edificio)
        {
            return tmp;
        }
       tmp = tmp->getSig();
    }
    return  nullptr;
}

std::list<std::string> listEdificios::linealizar(){

    std::list<std::string> lista;
    nodoEdificio* tmp = primero;
    while (tmp != nullptr) {
        lista.push_back(tmp->getEdificioString());
        tmp = tmp->getSig();
    }
    return lista;
}


void listEdificios::imprimirLista(){

    nodoEdificio* actual =primero;
    std::string salon="";
    std::string capacidad="";
    while(actual!=nullptr)
    {
        std::cout<<"Edificio-> "<<actual->getEdificioString()<<": "<<std::endl;
        nodoSalon* actualSalon = actual->getSalones()->primero;

        while (actualSalon!=nullptr) {
            salon= std::to_string(actualSalon->getValor().no_salon);
            capacidad = std::to_string(actualSalon->getValor().capacidad);
            std::cout <<"\tsalon: "+salon+" capacidad: "+capacidad<<std::endl;
            actualSalon = actualSalon->getSig();
        }

        actual=actual->getSig();
    }

}

salonEdificio listEdificios::obtnerSalon(std::string edificio, int no_salon){


    nodoEdificio* actual =primero;

    salonEdificio result = {nullptr,nullptr};

    while(actual!=nullptr)
    {
        if(actual->getEdificioString()==edificio)
        {

            nodoSalon* actualSalon = actual->getSalones()->primero;
            while (actualSalon!=nullptr) {

                if(actualSalon->getValor().no_salon == no_salon)
                {
                    result = {actual,actualSalon};
                    break;
                }

                actualSalon = actualSalon->getSig();
            }
                break;

        }

        actual = actual->getSig();
    }


      return result;

}














