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

   csv a = csv();
   bst miarbol = bst();
   std::string entrada ="ax10,ing mauricio\nax20,ing angel,\nax95,ing runinn\nax85,ing trueno";

   miarbol.insertarLista(a.obtenerCatedraticos(entrada));
   miarbol.inorden();






    return 0;

}


