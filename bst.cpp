#include "bst.h"

/*****************************************************************************
*************************** Nodo bst      ************************************
******************************************************************************
******************************************************************************
******************************************************************************/

nodoBst::nodoBst(catedratico ing)
{
    this->ing = ing;
    izq = der = nullptr;
}


nodoBst::nodoBst(catedratico ing,nodoBst* izq,nodoBst* der)
{
    this->ing = ing;
    this->izq = izq;
    this->der = der;
}

void nodoBst::imprimir()
{
    std::cout<<"codigo: "<<ing.id<<", Ing: "<<ing.nombre<<std::endl;

}

/*****************************************************************************
*************************** arbol binario ************************************
******************************************************************************
******************************************************************************
******************************************************************************/

bst::bst()
{
    raiz = nullptr;
}

bst::bst(nodoBst* r)
{
    raiz = r;
}


bool bst::estavacio()
{
    return raiz == nullptr;
}


catedratico bst::buscar(std::string codigo)
{
    nodoBst* nodo = buscar(raiz, codigo);

    if(nodo != nullptr)
    {
        return nodo->getValor();
    }else {
        return {"NULL","NULL"};
    }

}

nodoBst* bst::buscar(nodoBst* raiz, std::string codigo)
{
    if (raiz == nullptr)
        return nullptr;
    else if (codigo == raiz->getValor().id)
        return raiz;
    else if (codigo < raiz->getValor().id)
        return buscar(raiz->getizq(), codigo);
    else
        return buscar (raiz->getder(), codigo);
}




void bst::insertar (catedratico valor)
{
    this->raiz = insertar(this->raiz, valor);
}


nodoBst* bst::insertar(nodoBst* raiz, catedratico dato)
{
    if (raiz == nullptr){
        raiz = new nodoBst(dato);

    }else if (dato.id < raiz->getValor().id)
    {
        nodoBst *iz;
        iz = insertar(raiz->getizq(), dato);
        raiz->setizq(iz);
    }
    else if (dato.id > raiz->getValor().id)
    {
        nodoBst *dr;
        dr = insertar(raiz->getder(), dato);
        raiz->setder(dr);
    }
    else{

        std::cout<<"---Nodo Duplicado---"<<std::endl;
        std::cout<<"codigo: "<<raiz->getValor().id;
        std::cout<<"  catedratico: "<<raiz->getValor().nombre<<"\n\n";

    }
    return raiz;
}


void bst::preorden()
{
    std::cout <<"\n";
    std::cout <<"---------preorden----------- \n";

    if(raiz!=nullptr)
    {
        preorden(this->raiz);
    }else
    {
        std::cout <<"arbol vacio\n";
    }

}



void bst::preorden(nodoBst *r)
{
    if (r != nullptr)
    {
        r->imprimir();
        preorden (r->getizq());
        preorden (r->getder());
    }
}

void bst::inorden()
{
    std::cout <<"\n";
    std::cout <<"----------inorden------------ \n";


    if(raiz!=nullptr)
    {
        inorden(this->raiz);
    }else
    {
        std::cout <<"arbol vacio\n";
    }
}

void bst::inorden(nodoBst* r)
{
    if(r!= nullptr)
    {
        inorden(r->getizq());
        r->imprimir();
        inorden(r->getder());
    }
}

void bst::postorden()
{
    std::cout <<"\n";
    std::cout <<"----------postorden------------ \n";
    if(raiz!=nullptr)
    {
        postorden(this->raiz);
    }else
    {
        std::cout <<"arbol vacio\n";
    }

}

void bst::postorden(nodoBst* r)
{

    if(r!= nullptr)
    {
        inorden(r->getizq());
        inorden(r->getder());
        r->imprimir();
    }
}



void bst::graficar()
{
    std::string nombre = "arbolBst";
    textoDot(nombre);

    //especificar el nomabre en los metodos system
    system("dot -Tsvg -O arbolBst.dot");
    system("xdg-open arbolBst.dot.svg");
}

void bst::textoDot(std::string nombre)
{
    std::ofstream archivo;
    archivo.open(nombre+".dot",std::ios::out);//abriendo el archivo
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

    archivo<<"digraph g "<<std::endl;
    archivo<<"{\n"<<std::endl;
    archivo<<"node[shape=record, height=.1, color=turquoise4, fillcolor=green,style=filled ];"<<std::endl;
    archivo<<"edge[color=tomato];"<<std::endl;

    graficarPreorden();
    archivo<<txtgrafica<<std::endl;

    archivo<<"}"<<std::endl;

    archivo.close();//cerrar el archivo

}


void bst::graficarPreorden()
{
    txtgrafica="";
    if(this->raiz!=nullptr)
    {
        graficarPreorden(this->raiz);
    }else {
        txtgrafica = "node20[label = \"<f0> | <f1> Arbol Vacio | <f2>\"]";
    }
}

void bst::graficarPreorden(nodoBst* raiz)
{
    if(raiz != nullptr)
    {
        txtgrafica +="\t\t\tnode"+raiz->getValor().id+"[label =\"<f0> | <f1> cod: "+raiz->getValor().id+"\\nnombre: "+raiz->getValor().nombre+" | <f2>\"]\n";
        graficarPreorden(raiz->getizq());
        if(raiz->getizq()!=nullptr)
        {
            txtgrafica += "\t\t\t\"node"+raiz->getValor().id+"\":f0-> \"node"+raiz->getizq()->getValor().id+"\":f1\n\n";
        }

        graficarPreorden(raiz->getder());
        if(raiz->getder()!=nullptr)
        {
            txtgrafica += "\t\t\t\"node"+raiz->getValor().id+"\":f2-> \"node"+raiz->getder()->getValor().id+"\":f1\n\n";
        }
    }



}

void bst::insertarLista(std::list<catedratico> lista){

    for( auto it = lista.begin(); it != lista.end(); ++it )
    {
        catedratico aux = *it;
        insertar(aux);
    }

}

std::list<catedratico> bst::obtenerArbol(){


    if(this->raiz!= nullptr)
    {
        listarbol.clear();
        obtenerArbol(this->raiz);

    }else{
        listarbol.clear();
        listarbol.push_back({"NULL","NULL"});
    }

    return listarbol;
}



void bst::obtenerArbol(nodoBst* r){

    if(r!= nullptr)
    {
        obtenerArbol(r->getizq());
        listarbol.push_back(r->getValor());
        obtenerArbol(r->getder());
    }

}

std::string bst::editarCatedratico(catedratico cat){

    nodoBst* nodoEncontrado;
    nodoEncontrado = buscar(this->raiz, cat.id);

    if(nodoEncontrado!=nullptr){
        nodoEncontrado->setNombre(cat.nombre);

        return "true";
    }else{
        return "false";
    }

}


void bst::eliminar(catedratico valor){

      this->raiz = eliminar(this->raiz, valor);
}

nodoBst* bst::eliminar(nodoBst *r, catedratico dato){

    if (r == nullptr)
        std::cout<<"No se ha encontrado el nodo con la clave"<<std::endl;
    else if (dato.id < r->getValor().id)
    {
        nodoBst* iz;
        iz = eliminar(r->getizq(), dato);
        r->setizq(iz);
    }
    else if (dato.id > r->getValor().id)
    {
        nodoBst *dr;
        dr = eliminar(r->getder(), dato);
        r->setder(dr);
    }
    else
        // Nodo encontrado
    {
        nodoBst *q;
        q = r;
        if (q->getizq() == nullptr)
            r = q->getder();
        else if (q->getder() == nullptr)
            r = q->getizq();
        else
        {
            // tiene rama izquierda y derecha
            q = reemplazar(q);
            //figura 16.32
        }
        q = nullptr;
    }

    return r;

}

nodoBst* bst::reemplazar(nodoBst* act)
{
    nodoBst *a, *p;
    p = act;
    a = act->getizq();
    // rama de nodos menores
    while (a->getder() != nullptr)
    {
        p = a;
        a = a->getder();
    }
    // copia en act el valor del nodo apuntado por a
    act->setValor(a->getValor());
    if (p == act) // a es el hijo izquierdo de act
        p->setizq(a->getizq());// enlaza subarbol izquierdo. Fig. 16.32b
    else
        p->setder(a->getizq()); // se enlaza subarbol derecho. Fig. 16.32a
    return a;
}

nodoBst* bst::buscarId(std::string codigo){

    return  buscar(raiz, codigo);
}


std::string bst::obtenerdotGrafica(){

    txtgrafica="";
    std::string nombre = "arbolBst";
    textoDot(nombre);

    return txtgrafica;
}
