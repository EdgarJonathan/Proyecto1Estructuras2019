#include "listasemana.h"

/*****************************************************************************
**********************   Nodo Lista Semana************************************
******************************************************************************
******************************************************************************
******************************************************************************/

NodoSemana::NodoSemana(stOrtogonal datos)
{

    this->dia = datos.dia;
    this->siguiente = nullptr;
    this->miMatriz = new matriz();
}

/*****************************************************************************
**********************        Lista Semana************************************
******************************************************************************
******************************************************************************
******************************************************************************/
ListaSemana::ListaSemana(){}

std::string ListaSemana::insertar(stOrtogonal datos,listCursos* cursos, listEdificios* edificios)
{
    std::string result;
    NodoSemana* nuevo = new NodoSemana(datos);
    NodoSemana* encontrado = buscarDia(datos.dia);

        if(primero==nullptr)
        {
            result  = "se el primero nodo de la lista dia, ";
            result +=nuevo->miMatriz->insertar(datos,cursos,edificios);
            primero = nuevo;
            ultimo= primero;



        }else  if(encontrado==nullptr)
        {
            result ="se agrega un dia a la lista, ";
            result += nuevo->miMatriz->insertar(datos,cursos,edificios);
            ordenar(nuevo);


        }
        else
        {
            result = "Se ultiliza un dia existente, ";
            result +=encontrado->miMatriz->insertar(datos,cursos,edificios);

        }


    return result;
}

void ListaSemana::ordenar(NodoSemana* nuevo)
{
    NodoSemana* actual = primero;
    int diaActual;
    int diaActualSig;
    int dia = csv::getNumDia(nuevo->dia);

    //el nuevo nodo es menor al primero
    if(dia <= csv::getNumDia(primero->dia))
    {
        nuevo->siguiente = primero;
        primero =nuevo;
    }//si es mayor o igual al ultimo
    else if(dia >=csv::getNumDia(ultimo->dia)){

        ultimo->siguiente =nuevo;
        ultimo = nuevo;
    }//recorriendo la lista comparando:
    //si nuevo es mayor o igual al acutal
    //y si nuevo es menor o igual al siguiente de actual
    else {
        while (actual!=ultimo) {

            diaActual = csv::getNumDia(actual->dia);
            diaActualSig = csv::getNumDia(actual->siguiente->dia);
            if ((dia >=diaActual) &&(dia <= diaActualSig))
            {
                nuevo->siguiente = actual->siguiente;
                actual->siguiente = nuevo;
                break;
            }

            actual = actual->siguiente;
        }
    }


}


NodoSemana* ListaSemana::buscarDia(std::string dia)
{
    NodoSemana* temp = primero;
    NodoSemana* result =nullptr;
    while(temp!= nullptr)
    {
        if(temp->dia == dia)
        {
            result=temp;
            break;

        }

        temp= temp->siguiente;
    }



    return result;
}


void ListaSemana::graficar(){

    std::string nombre = "ListaDias";
    enlaces ="";
    generarDot(nombre);

    //especificar el nomabre en los metodos system
    system("dot -Tsvg -O ListaDias.dot");
    system("xdg-open ListaDias.dot.svg");

}


void ListaSemana::generarDot(std::string nombre){


    std::ofstream archivo;
    archivo.open(nombre+".dot",std::ios::out);//abriendo el archivo
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}


    archivo<<"digraph G \n{\n "<<std::endl;
    archivo<<"\tgraph [fontsize=10 fontname=\"Verdana\" compound=true];\n"<<std::endl;
    archivo<<"\tnode [shape=record fontsize=10 fontname=\"Verdana\"];\n"<<std::endl;


    NodoSemana* actual = primero;
    while(actual!=nullptr)
    {
      archivo<<actual->miMatriz->getDot()<<std::endl;

        actual = actual->siguiente;
    }

    archivo<<subGrafoLista()<<std::endl;
    archivo<<enlaces<<std::endl;

    archivo<<"}\n"<<std::endl;

    archivo.close();//cerrar el archivo

}


std::string ListaSemana::subGrafoLista()
{
    std::string lista="";
    std::string rank="\t\t\t{rank = same;";
    NodoSemana* actual=primero;

    lista+="//--------------------------------------LIsta de Dias-----------------------------------\n";
    lista+="\t\tsubgraph cluster_Dias {\n";
    lista+="\t\t\trankdir=LR;\n";
    lista+="\t\t\tnode[shape=box, color=red, fillcolor=wheat4,style=filled ];\n";
    lista+="\t\t\tedge[color=tomato arrowhead=vee, dir=both,arrowsize=1, arrowtail=dot];\n";

    while(actual!=nullptr){

        if(actual==ultimo)
        {

            lista+="\t\t\tnode"+actual->dia
                    +"[label=\" DIA: "+actual->dia+"\"];\n";

            lista+="\t\t\tnode"+actual->dia;
            lista+=" -> ";
            lista+="NULL;\n";
            lista+="\t\tNULL[label=\" NULL\"];\n";

            rank+="node"+actual->dia+"; NULL;}";

            enlaces+="\tnode"+actual->dia;
            enlaces+=" -> ";
            enlaces+= actual->dia+";\n";


        }else{

            lista+="\t\t\tnode"+actual->dia
                    +"[label=\"DIA: "+actual->dia+"\"];\n";

            lista+="\t\t\tnode"+actual->dia;
            lista+=" -> ";
            lista+="node"+actual->siguiente->dia+";\n";

            rank+="node"+actual->dia+";";

            enlaces+="\tnode"+actual->dia;
            enlaces+=" -> ";
            enlaces+= actual->dia+";\n";

        }


        actual = actual->siguiente;
    }

    lista+=rank+"\n";
    lista+="\t\t\tcolor=blue;\n";
    lista+="\t\t\tlabel=\"Lista de de dias\"\n";
    lista+="\t\t}\n";


    return lista;
}













