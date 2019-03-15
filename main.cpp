#include <iostream>
#include <bst.h>
#include <listcursos.h>


using namespace std;

int main()
{
  bst* miarbol = new bst();
  listCursos* misCusros = new listCursos();

  miarbol->insertar({"AX31","ing abastraccion"});
  miarbol->insertar({"AX29","ing asincrono"});
  miarbol->insertar({"AX36","ing asturias"});
  miarbol->insertar({"AX30","ing blatbox"});
  miarbol->insertar({"AX28","ing callback"});
  miarbol->insertar({"AX34","ing carlos"});
  miarbol->insertar({"AX26","ing castro"});
  miarbol->insertar({"AX32","ing grafo"});
  miarbol->insertar({"AX25","ing mario"});
  miarbol->insertar({"AX35","ing mauricio"});
  miarbol->insertar({"AX27","ing null"});
  miarbol->insertar({"AX37","ing pablo"});
  miarbol->insertar({"AX33","ing fijo"});

  miarbol->inorden();

  misCusros->insertar({"BS050","Estructura","AX31"},miarbol);
  misCusros->insertar({"BS030","Estadistica","AX29"},miarbol);
  misCusros->insertar({"BS060","Compiladores","AX28"},miarbol);
  misCusros->insertar({"BS045","Arquitectura","AX26"},miarbol);
  misCusros->insertar({"BS070","Organizacion","AX30"},miarbol);
  misCusros->insertar({"BS012","Topografia","AX35"},miarbol);
  misCusros->insertar({"BS055","Electrica","AX31"},miarbol);

  misCusros->imprimirLista();
  //miarbol->graficar();

  misCusros->graficar(miarbol->obtenerdotGrafica());


    return 0;


}

