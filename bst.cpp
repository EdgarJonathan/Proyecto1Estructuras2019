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

void bst::setRaiz( nodoBst *r)
{
    raiz = r;
}

nodoBst * bst::getRaiz()
{
    return raiz;
}


bool bst::estavacio()
{
    return raiz == nullptr;
}


catedratico bst::buscar(std::string codigo)
{
    nodoBst* nodo = buscar(raiz, codigo);

   if(nodo == nullptr)
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
     std::cout <<"----------postrden------------ \n";
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
     encabezado(nombre);
     cuerpo(nombre);
     pie(nombre);

     //especificar el nomabre en los metodos system
     system("dot -Tsvg -O arbolBst.dot");
     system("xdg-open arbolBst.dot.svg");
 }

 void bst::encabezado(std::string nombre)
 {
     std::ofstream archivo;
     archivo.open(nombre+".dot",std::ios::out);//abriendo el archivo
     if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

         archivo<<"digraph g "<<std::endl;
         archivo<<"{\n"<<std::endl;
         archivo<<"node[shape=record, height=.1, color=turquoise4, fillcolor=green,style=filled ];"<<std::endl;
         archivo<<"edge[color=tomato];"<<std::endl;

     archivo.close();//cerrar el archivo

 }
 void bst::cuerpo(std::string nombre)
 {
     std::ofstream archivo;
     archivo.open(nombre+".dot",std::ios::app);//abrimos el archivo en modo anadir
     if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

       std::string cuerpo = graficarPreorden();
        archivo<<cuerpo<<std::endl;

      archivo.close();//cerrar el archivo

 }
 void bst::pie(std::string nombre)
 {
     std::ofstream archivo;
     archivo.open(nombre+".dot",std::ios::app);//abrimos el archivo en modo anadir
     if(archivo.fail()){std::cout<<"No se pudo crear el archivo"; exit(1);}

         archivo<<"}"<<std::endl;
         archivo.close();//cerrar el archivo
 }


 std::string bst::graficarPreorden()
 {
     std::string result = "node20[label = \"<f0> | <f1> Arbol Vacio | <f2>\"]";
     if(this->raiz!=nullptr)
     {
        result = graficarPreorden(this->raiz);
     }

    return result;
 }
 std::string bst::graficarPreorden(nodoBst* raiz)
 {
    std::string result = "";
    if(raiz != nullptr)
    {
        std::string temp = "";
        std::string puntero="";
        std::string cod = raiz->getValor().id;
        std::string nom = raiz->getValor().nombre;

        if((raiz->getder()==nullptr)&&(raiz->getizq() ==nullptr))
        {
           result ="node"+cod+"[label =\"<f0> | <f1> cod: "+cod+"\\nnombre: "+nom+" | <f2>\"]\n";
        }


        if(raiz->getizq()!=nullptr)
        {

            temp =graficarPreorden(raiz->getizq());
            result = temp+"node"+cod+"[label =\"<f0> | <f1> cod: "+cod+"\\nnombre: "+nom+" | <f2>\"]\n\n";
            puntero = "\"node"+cod+"\":f0-> \"node"+raiz->getizq()->getValor().id+"\":f1\n";
            result = result+puntero;

        }

        if(raiz->getder()!=nullptr)
        {

             temp =graficarPreorden(raiz->getder());
             result = result+temp+"node"+cod+"[label =\"<f0> | <f1> cod: "+cod+"\\nnombre: "+nom+" | <f2>\"]\n\n";
             puntero = "\"node"+cod+"\":f2-> \"node"+raiz->getder()->getValor().id+"\":f1\n";
             result = result+puntero;

        }
    }


    return result;
 }













