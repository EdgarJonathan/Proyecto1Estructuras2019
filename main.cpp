#include <iostream>
#include <bst.h>
#include <listcursos.h>
#include <listedificios.h>
#include <matriz.h>
#include <listasemana.h>
#include <sstream>


using namespace std;

int main()
{
    //----------------------------------arbol de catedraticos y lista de cursos---------------
  bst* miarbol = new bst();
  listCursos* misCusros = new listCursos();

  miarbol->insertar({"AX31","ing abastraccion"});
  miarbol->insertar({"AX29","ing asincrono"});
  miarbol->insertar({"AX36","ing asturias"});
  miarbol->insertar({"AX10","ing lorena"});
  miarbol->insertar({"AX28","ing callback"});
  miarbol->insertar({"AX34","ing carlos"});
  miarbol->insertar({"AX26","ing castro"});
  miarbol->insertar({"AX32","ing grafo"});
  miarbol->insertar({"AX25","ing mario"});
  miarbol->insertar({"AX35","ing mauricio"});
  miarbol->insertar({"AX27","ing null"});
  miarbol->insertar({"AX37","ing pablo"});
  miarbol->insertar({"AX33","ing fijo"});

  //miarbol->inorden();

  misCusros->insertar({"BS050","Estructura","AX10"},miarbol);
  misCusros->insertar({"BS030","Estadistica","AX29"},miarbol);
  misCusros->insertar({"BS060","Compiladores","AX28"},miarbol);
  misCusros->insertar({"BS045","Arquitectura","AX26"},miarbol);
  misCusros->insertar({"BS070","Organizacion","AX27"},miarbol);
  misCusros->insertar({"BS012","Topografia","AX35"},miarbol);
  misCusros->insertar({"BS055","Electrica","AX31"},miarbol);

  //misCusros->imprimirLista();
 // miarbol->graficar();
 // misCusros->graficar(miarbol->obtenerdotGrafica());

  //-------------------------------lista edificios--------------------------------------------
    listEdificios* Edificios = new listEdificios();
    Edificios->insertar({5,8,"t-3"});
    Edificios->insertar({9,560,"t-4"});
    Edificios->insertar({6,98,"t-3"});
    Edificios->insertar({1,845,"t-2"});
    Edificios->insertar({3,88,"t-2"});
    Edificios->insertar({78,865,"t-4"});
    Edificios->insertar({3,856,"t-4"});
    Edificios->insertar({8,856,"t-4"});

   // Edificios->imprimirLista();
    ListaSemana* milista = new  ListaSemana();
    stOrtogonal dato;
    dato= {"lunes","7:00","8:30","t-4",3,"BS055"};
    std::cout<<milista->insertar(dato,misCusros,Edificios)<<std::endl;
    dato= {"martes","8:00","8:30","t-4",9,"BS060"};
    std::cout<<milista->insertar(dato,misCusros,Edificios)<<std::endl;
    dato= {"sabado","5:00","6:30","t-3",6,"BS012"};
    std::cout<<milista->insertar(dato,misCusros,Edificios)<<std::endl;
    dato= {"sabado","7:00","7:30","t-2",3,"BS050"};
    std::cout<<milista->insertar(dato,misCusros,Edificios)<<std::endl;
    dato= {"sabado","6:00","7:30","t-4",3,"BS055"};
    std::cout<<milista->insertar(dato,misCusros,Edificios)<<std::endl;

    milista->graficar();

    return 0;


}

