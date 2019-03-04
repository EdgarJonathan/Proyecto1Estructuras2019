#include <iostream>
#include <bst.h>

using namespace std;


int main()
{
    bst miarbol = bst();

    miarbol.insertar({"dario","ing1"});
    miarbol.insertar({"barco","ing1"});
    miarbol.insertar({"cabello","ing1"});
    miarbol.insertar({"far","ing1"});
    miarbol.insertar({"ernesto","ing1"});
    miarbol.insertar({"zoan","ing1"});
    miarbol.insertar({"ana","ing1"});

    for (int i=0;i<10;i++) {

        miarbol.insertar({"AX"+std::to_string(i),"ing1"});
    }

    miarbol.preorden();
    miarbol.inorden();
    miarbol.graficar();



    return 0;

}
