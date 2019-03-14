#include <iostream>
#include <bst.h>
#include <csv.h>

//#include <climits>

using namespace std;

int main()
{
  /*  bst miarbol = bst();

    miarbol.insertar({"dario","ing1"});
    miarbol.insertar({"barco","ing1"});
    miarbol.insertar({"cabello","ing1"});
    miarbol.insertar({"far","ing1"});
    miarbol.insertar({"ernesto","ing1"});
    miarbol.insertar({"zoan","ing1"});
    miarbol.insertar({"ana","ing1"});



//    for (int i=0;i<10;i++) {

//        miarbol.insertar({"AX"+std::to_string(i),"ing1"});
//    }

    miarbol.preorden();
    miarbol.inorden();
   // miarbol.graficar();

    bst miarbol = bst();

    std::list<catedratico> lista;
    lista.push_back({"gario","ing1"});
    lista.push_back({"auatemala","ing1"});
    lista.push_back({"caramelo","ing1"});
    lista.push_back({"hacha","ing1"});
    lista.push_back({"zombie","ing1"});
    lista.push_back({"beta","ing1"});
    lista.push_back({"faro","ing1"});
    lista.push_back({"duty","ing1"});


    miarbol.insertarLista(lista);
    miarbol.inorden();*/


   //------------------------------obteniendo el arbol en forma de lista------------------------------
   csv a = csv();
   bst miarbol = bst();
   std::string entrada ="ax10,ing mauricio\nax20,ing angel,\nax95,ing runinn\nax85,ing trueno";

   miarbol.insertarLista(a.obtenerCatedraticos(entrada));


   std::list<catedratico> lista = miarbol.obtenerArbol();

   auto iterador = lista.begin();
   auto fin = lista.end();

   std::cout<<"------------primera llamada---------------"<<std::endl;
   for(iterador ; iterador != fin ; ++iterador){
       catedratico cat = *iterador;
       std::cout<<"id: "<<cat.id<<"nombre:"<<cat.nombre<<std::endl;
   }

   std::list<catedratico> lista1 = miarbol.obtenerArbol();
   auto iterador1 = lista1.begin();
   auto fin1 = lista1.end();

   std::cout<<"------------segunda llamada---------------"<<std::endl;
   for(iterador1 ; iterador1 != fin1 ; ++iterador1){
       catedratico cat = *iterador1;
       std::cout<<"id: "<<cat.id<<"nombre:"<<cat.nombre<<std::endl;
   }

    return 0;


}

