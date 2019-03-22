#ifndef VARIABLES_H
#define VARIABLES_H
#include <iostream>
#include <list>

struct Salon{
  int no_salon;
  int capacidad;
};

struct building
{
    int no_salon;
    int capacidad;
    std::string edificio;
};

struct stOrtogonal{

    std::string dia;
    std::string  horaInicio;
    std::string horaFinal;
    std::string edificio;
    int no_salon;
    std::string idCurso;

};

struct editCurso
{
  std::string id;
  std::string nombre;
};

struct EdificioString
{
    std::string edificio;
    std::string no_salon;
    std::string capacidad;

};

struct Edificio
{
    std::string nombre;

    std::list<Salon> salones;
};


#endif // VARIABLES_H
