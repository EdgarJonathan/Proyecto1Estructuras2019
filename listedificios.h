#ifndef LISTEDIFICIOS_H
#define LISTEDIFICIOS_H
#include <string>
#include <list>

struct building
{
    int no_salon;
    int capacidad;
    std::string edificio;
};


/*****************************************************************************
*************************** Nodo Salon****************************************
******************************************************************************
******************************************************************************
******************************************************************************/
struct Salon{
  int no_salon;
  int capacidad;
};

class nodoSalon
{

protected:
    Salon salon;
    nodoSalon* sig;
    nodoSalon* ant;


public:
    nodoSalon();
    nodoSalon(Salon salon);
    //operacionde acceso
    Salon   getValor(){ return salon; }
    nodoSalon* getSig(){ return sig; }
    nodoSalon* getAnt(){ return ant; }
    // operaciones de modificación
    void setValor(Salon n){ this->salon = n; }
    void setSig(nodoSalon* n){ this->sig = n; }
    void setAnt(nodoSalon* n){ this->ant = n; }
};



/*****************************************************************************
*************************** listEdificios  ***********************************
******************************************************************************
******************************************************************************
******************************************************************************/
class listSalon
{

private:
    void ordenarLista(nodoSalon* nuevo);
    nodoSalon* buscarId(int d);

public:
    listSalon();
    nodoSalon* primero;
    nodoSalon* ultimo;

    std::string insertar(Salon salon);
    std::list<Salon> linealizar();
    void imprimirLista();
};

/*****************************************************************************
*************************** Nodo Edificios************************************
******************************************************************************
******************************************************************************
******************************************************************************/


class nodoEdificio
{

private:
    std::string edificio;
    listSalon* salones = new listSalon();
    nodoEdificio* sig;
    nodoEdificio* ant;
public:
    nodoEdificio();
    nodoEdificio(std::string edificio);
    void insertarSalon(int salon,int capacidad);
    //operacionde acceso
    std::string  getEdificioString(){ return edificio; }
    listSalon*   getSalones(){return salones;}
    nodoEdificio* getSig(){ return sig; }
    nodoEdificio* getAnt(){ return ant; }
    std::string getValor(){return edificio;}
    // operaciones de modificación
    void setSalones(listSalon* n){this->salones =n;}
    void setValor(std::string n){ this->edificio = n; }
    void setSig(nodoEdificio* n){ this->sig = n; }
    void setAnt(nodoEdificio* n){ this->ant = n; }
};

struct salonEdificio{
    nodoEdificio* edificio;
    nodoSalon* salon;
};

/*****************************************************************************
*************************** listEdificios  ***********************************
******************************************************************************
******************************************************************************
******************************************************************************/
class listEdificios
{

private:
    void ordenarLista(nodoEdificio* nuevo);
    nodoEdificio* buscarId(std::string edificio);

public:
    listEdificios();
    nodoEdificio* primero;
    nodoEdificio* ultimo;

    std::string insertar(building edificio);
    std::list<std::string> linealizar();
    void imprimirLista();
    salonEdificio obtnerSalon(std::string edificio, int no_salon);

};

#endif // LISTEDIFICIOS_H
