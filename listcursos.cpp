#include "listcursos.h"

/*****************************************************************************
***************************     Nodo list ************************************
******************************************************************************
******************************************************************************
******************************************************************************/
nodoCurso::nodoCurso(Curso curso, bst* arbol)
{
    nodoBst* cat = arbol->buscarId(curso.idCatedratico);

    this->setCatedratico(cat);
    this->curso=curso;
    this->setSig(nullptr);
}


/*****************************************************************************
*************************** lista Enlazada************************************
******************************************************************************
******************************************************************************
******************************************************************************/

listCursos::listCursos()
{
    primero = nullptr;
    ultimo = nullptr;
}


nodoCurso* listCursos::buscarId(std::string d)
{
    nodoCurso* tmp = primero;
    do {

        if(tmp->getValor().id==d){
            return tmp;
        }

        tmp = tmp->getSig();
    }while (tmp!=primero);

    return nullptr;
}


std::string listCursos::insertar(Curso curso,bst* arbol)
{

    nodoCurso* nuevo;
    nuevo = new nodoCurso(curso,arbol);

    //verificamos si existe un catedratico para este curso
    if(nuevo->getCatedratico()!=nullptr)
    {
        if(primero==nullptr)
        {
            primero = nuevo;
            primero->setSig(primero);
            ultimo= primero;

            return "se agrego exitosamente";

        }else  if(buscarId(nuevo->getValor().id)==nullptr)
        {
            ordenarLista(nuevo);

            return "se agrego exitosamente";
        }
        else
        {
            return "id ya existe";
        }

    }else {

        return"no existe un catedratico para el curso de: "+curso.nombre;
    }


}

void listCursos::ordenarLista(nodoCurso* nuevo)
{
    nodoCurso* actual =primero;

    //si el nuevo es menor al primero
    if(nuevo->getValor().id < primero->getValor().id )
    {
        nuevo->setSig(primero);
        ultimo->setSig(nuevo);
        primero = nuevo;

    }//si es mayor o igual ultimo
    else if(nuevo->getValor().id >= ultimo->getValor().id)
    {
        nuevo->setSig(primero);
        ultimo->setSig(nuevo);
        ultimo=nuevo;

    }
    //recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {

        while(actual!=ultimo)
        {
            if((nuevo->getValor().id >= actual->getValor().id)
              &&(nuevo->getValor().id <= actual->getSig()->getValor().id))
            {
                nuevo->setSig(actual->getSig());
                actual->setSig(nuevo);
                break;
            }
            actual=actual->getSig();
        }
    }

}


void listCursos::imprimirLista()
{
    nodoCurso* actual =primero;

    std::cout<<"-----------Mis Cursos---------------"<<std::endl;
    do{
        std::cout <<"<-[ id: "+actual->getValor().id+" nombre: "+actual->getValor().nombre+" catedratico: "+actual->getCatedratico()->getValor().nombre+"]->"<<std::endl;
        actual=actual->getSig();
    }while(actual!=primero);
}


void listCursos::graficar(std::string dotArbol){

    dotEnlacesListaArbol="";
    std::string nombre = "lista";
    generarDot(nombre,dotArbol);

    //especificar el nomabre en los metodos system
    system("dot -Tsvg -O lista.dot");
    system("xdg-open lista.dot.svg");

}


void listCursos::generarDot(std::string nombre, std::string dotArbol){

    std::ofstream archivo;
    archivo.open(nombre+".dot",std::ios::out);//abriendo el archivo
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}


    archivo<<"digraph G \n{\n "<<std::endl;
    archivo<<"\tgraph [fontsize=10 fontname=\"Verdana\" compound=true];\n"<<std::endl;
    archivo<<"\tnode [shape=record fontsize=10 fontname=\"Verdana\"];\n"<<std::endl;


    archivo<<subGrafoArbol(dotArbol)<<std::endl;
    archivo<<subGrafoLista()<<std::endl;
    archivo<<dotEnlacesListaArbol<<std::endl;

    archivo<<"}\n"<<std::endl;

    archivo.close();//cerrar el archivo


}

std::string listCursos::subGrafoArbol(std::string dotArbol){

    std::string arbol ="";
    arbol+="\t\tsubgraph cluster_0 {\n";
    arbol+="\t\t\tnode[shape=record, height=.1, color=turquoise4, fillcolor=green,style=filled ];\n";
    arbol+="\t\t\tedge[color=blue];\n";
    arbol+=dotArbol;
    arbol+="\t\t\tcolor=blue;\n";
    arbol+="\t\t\tlabel=\"Arbol de Catedraticos\"\n";
    arbol+="\t\t}\n";
    return arbol;
}

std::string listCursos::subGrafoLista()
{
    std::string lista="";
    std::string rank="\t\t\t{rank = same;";
    nodoCurso* actual=primero;

    lista+="\t\tsubgraph cluster_1 {\n";
    lista+="\t\t\trankdir=ud;\n";
    lista+="\t\t\tnode[shape=box, color=red, fillcolor=wheat4,style=filled ];\n";
    lista+="\t\t\tedge[color=tomato arrowhead=vee, dir=both,arrowsize=1, arrowtail=dot];\n";

    do{

        if(actual==ultimo)
        {
            /* lista+="\t\t\tnode"+actual->getValor().id
                    +"[label=\" id_Curso: "+actual->getValor().id
                    +"\\nCurso: "+actual->getValor().nombre
                    +"\\nCatedratico: "+actual->getCatedratico()->getValor().nombre+"\"];\n";

            lista+="\t\t\tnode"+actual->getValor().id;
            lista+=" -> ";
            lista+="node"+primero->getValor().id+";\n";

            rank+="node"+actual->getValor().id+";};";*/

            lista+="\t\t\tnode"+actual->getValor().id
                    +"[label=\" id_Curso: "+actual->getValor().id
                    +"\\nCurso: "+actual->getValor().nombre
                    +"\\nCatedratico: "+actual->getCatedratico()->getValor().nombre+"\"];\n";

            lista+="\t\t\tnode"+actual->getValor().id;
            lista+=" -> ";
            lista+="node"+actual->getSig()->getValor().id+";\n";

            rank+="node"+actual->getValor().id+";}";

            dotEnlacesListaArbol+="\tnode"+actual->getValor().id;
            dotEnlacesListaArbol+=" -> ";
            dotEnlacesListaArbol+="node"+actual->getCatedratico()->getValor().id+":f1;\n";


        }else{

            lista+="\t\t\tnode"+actual->getValor().id
                    +"[label=\" id_Curso: "+actual->getValor().id
                    +"\\nCurso: "+actual->getValor().nombre
                    +"\\nCatedratico: "+actual->getCatedratico()->getValor().nombre+"\"];\n";

            lista+="\t\t\tnode"+actual->getValor().id;
            lista+=" -> ";
            lista+="node"+actual->getSig()->getValor().id+";\n";

            rank+="node"+actual->getValor().id+";";

            dotEnlacesListaArbol+="\tnode"+actual->getValor().id;
            dotEnlacesListaArbol+=" -> ";
            dotEnlacesListaArbol+="node"+actual->getCatedratico()->getValor().id+":f1;\n";

        }


        actual = actual->getSig();
    }while(actual!=primero);

    // lista+=rank+"\n";
    lista+="\t\t\tcolor=blue;\n";
    lista+="\t\t\tlabel=\"Lista de Cursos\"\n";
    lista+="\t\t}\n";


    return lista;
}




