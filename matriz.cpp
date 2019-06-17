#include "matriz.h"
//********************************************************************************
//************************CLASE NODO ORTOGONAL************************************
//********************************************************************************
NodoOrtogonal::NodoOrtogonal(xy indice,contenido cont)
{
    this->indice = indice;
    this->cont = cont;
    this->up   = nullptr;
    this->down = nullptr;
    this->der  = nullptr;
    this->izq  = nullptr;
}

//********************************************************************************
//************************CLASE LISTA ORTOGONAL***********************************
//********************************************************************************
ListaOrtogonal::ListaOrtogonal()
{
    primerolistaHorizontal = nullptr;
    primerolistaVertical  = nullptr;
    ultimolistaHorizontal  = nullptr;
    ultimolistaVertical   = nullptr;
}

std::string ListaOrtogonal::insertarListaHorizontal(NodoOrtogonal* nuevo)
{

    std::string respuesta="";

     if(primerolistaHorizontal==nullptr)
    {
        primerolistaHorizontal=nuevo;
        primerolistaHorizontal->setder(nullptr);
        primerolistaHorizontal->setizq(nullptr);
        ultimolistaHorizontal=primerolistaHorizontal;

        respuesta="Se ingreso el primer nodo en la lista horizontal";
    }else
    {
        ordenarListaHorizontal(nuevo);

        respuesta="Se ingreso  y se ordeno el  nodo en la lista horizontal ";
    }

    return respuesta;
}

void ListaOrtogonal::ordenarListaHorizontal(NodoOrtogonal*  nuevo)
{
    NodoOrtogonal* actualFila = primerolistaHorizontal;
    int Nhorainicio= csv::getnum(nuevo->getIndex().horaInicio);
    int Phorainicio = csv::getnum(primerolistaHorizontal->getIndex().horaInicio);
    int Uhorainicio= csv::getnum(ultimolistaHorizontal->getIndex().horaInicio);

    //si el nuevo es menor al primero
    if(Nhorainicio <= Phorainicio)
    {
        primerolistaHorizontal->setizq(nuevo);
        nuevo->setder(primerolistaHorizontal);
        nuevo->setizq(nullptr);
        primerolistaHorizontal=nuevo;
    }//si  es mayor o igual al ultimo
    else if(Nhorainicio >= Uhorainicio)
    {
        ultimolistaHorizontal->setder(nuevo);
        nuevo->setizq(ultimolistaHorizontal);
        nuevo->setder(nullptr);
        ultimolistaHorizontal= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualFila!=ultimolistaHorizontal) {

            if((Nhorainicio >= csv::getnum(actualFila->getIndex().horaInicio))
               &&(Nhorainicio <= csv::getnum(actualFila->getder()->getIndex().horaInicio)))
            {
                nuevo->setder(actualFila->getder());
                nuevo->setizq(actualFila);
                actualFila->getder()->setizq(nuevo);
                actualFila->setder(nuevo);
                break;
            }

            actualFila= actualFila->getder();
        }
    }

}

std::string ListaOrtogonal::insertarListaVertical(NodoOrtogonal* nuevo)
{


    std::string respuesta="";

    if(primerolistaVertical==nullptr)
    {
        primerolistaVertical= nuevo;
        primerolistaVertical->setDown(nullptr);
        primerolistaVertical->setUp(nullptr);
        ultimolistaVertical = primerolistaVertical;
        respuesta="se ingreso correctamente nodo en la lista vertical";

    }else
    {
        ordenarListaVertical(nuevo);
        respuesta="se ingreso y se ordeno el nodo en la lista vertical";
    }
    return respuesta;

}

void ListaOrtogonal::ordenarListaVertical(NodoOrtogonal* nuevo)
{

    NodoOrtogonal* actualCol = primerolistaVertical;
    int nuevo_salon =nuevo->getIndex().salon->getValor().no_salon;

    //si el nuevo es menor al primero
    if(nuevo_salon <= primerolistaVertical->getIndex().salon->getValor().no_salon)
    {
        primerolistaVertical->setUp(nuevo);
        nuevo->setDown(primerolistaVertical);
        nuevo->setUp(nullptr);
        primerolistaVertical=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo_salon >= ultimolistaVertical->getIndex().salon->getValor().no_salon)
    {
        ultimolistaVertical->setDown(nuevo);
        nuevo->setUp(ultimolistaVertical);
        nuevo->setDown(nullptr);
        ultimolistaVertical= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualCol!=ultimolistaVertical) {

            if((nuevo_salon >= actualCol->getIndex().salon->getValor().no_salon)
                    &&(nuevo_salon <= actualCol->getDown()->getIndex().salon->getValor().no_salon))
            {
                nuevo->setDown(actualCol->getDown());
                nuevo->setUp(actualCol);
                actualCol->getDown()->setUp(nuevo);
                actualCol->setDown(nuevo);
                break;
            }

            actualCol= actualCol->getDown();
        }
    }

}

//********************************************************************************
//***********************CLASE NODO FILA******************************************
//********************************************************************************
NodoCabeceraFila::NodoCabeceraFila(NodoOrtogonal* nuevo)
{
    this->salon = nuevo->getIndex().salon;
    this->edificio=nuevo->getIndex().edificio;
    this->abajo =nullptr;
    this->arriba=nullptr;
    this->listHorizontal = new ListaOrtogonal();

}

//********************************************************************************
//************************CLASE LISTA FILA ***************************************
//********************************************************************************
ListaCabeceraFila::ListaCabeceraFila()
{
    this->primero=nullptr;
    this->ultimo =nullptr;

}

std::string ListaCabeceraFila::insertar(NodoOrtogonal *nuevo)
{

    std::string respuesta="";
    int no_salon = nuevo->getIndex().salon->getValor().no_salon;
    nodoEdificio* edificio = nuevo->getIndex().edificio;

    if(primero==nullptr)
    {
        NodoCabeceraFila* nuevoFila = new NodoCabeceraFila(nuevo);
        respuesta =  nuevoFila->listHorizontal->insertarListaHorizontal(nuevo);
        primero=nuevoFila;
        primero->abajo =nullptr;
        primero->arriba = nullptr;
        ultimo=primero;

        respuesta ="Se ingreso la primera Fila y "+respuesta;

    }//si no existe el nodo se deberar crear y ordenar en la lista
    else if(buscarFila(edificio,no_salon)==nullptr)
    {
        NodoCabeceraFila* nuevoFila = new NodoCabeceraFila(nuevo);
        respuesta =  nuevoFila->listHorizontal->insertarListaHorizontal(nuevo);


        ordenar(nuevoFila);
        respuesta ="Se agrego la Fila se ordeno y "+respuesta;

    }//si el nodo existe solo se utliza y se envia el nodoortogonal
    else
    {
        NodoCabeceraFila* aux = buscarFila(edificio,no_salon);
        respuesta= aux->listHorizontal->insertarListaHorizontal(nuevo);
        respuesta ="se utilizo la fila ya creada y "+respuesta;

    }
    return respuesta;
}

NodoCabeceraFila* ListaCabeceraFila::buscarFila(nodoEdificio* edificio,int salon)
{
    NodoCabeceraFila* tmp = primero;

    while (tmp!=nullptr) {
        if((tmp->edificio->getValor()== edificio->getValor())&&
           (tmp->salon->getValor().no_salon==salon))
        {
            return tmp;
        }
        tmp = tmp->abajo;
    }
    return nullptr;
}

void ListaCabeceraFila::ordenar(NodoCabeceraFila* nuevo)
{
    NodoCabeceraFila* actual = primero;
    int nuevo_salon = nuevo->salon->getValor().no_salon;

    //si el nuevo es menor al primero
    if(nuevo_salon <= primero->salon->getValor().no_salon)
    {
        primero->arriba=nuevo;
        nuevo->abajo = primero;
        nuevo->arriba= nullptr;
        primero=nuevo;


    }//si  es mayor o igual al ultimo
    else if(nuevo_salon >= ultimo->salon->getValor().no_salon)
    {
        ultimo->abajo = nuevo;
        nuevo->arriba = ultimo;
        nuevo->abajo  = nullptr;
        ultimo = nuevo;

    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while(actual!=ultimo)
        {
            if((nuevo_salon >= actual->salon->getValor().no_salon)
               &&(nuevo_salon <= actual->abajo->salon->getValor().no_salon))
            {
                nuevo->abajo =actual->abajo;
                nuevo->arriba =  actual;
                nuevo->abajo->arriba =nuevo;
                actual->abajo = nuevo;
                break;
            }

            actual = actual->abajo;
        }

    }
}
//********************************************************************************
//************************CLASE NODO COLUMNA *************************************
//********************************************************************************
NodoCabeceraColumna::NodoCabeceraColumna(NodoOrtogonal* nuevo)
{
    this->horaInicio = nuevo->getIndex().horaInicio;
    this->sig=nullptr;
    this->ant =nullptr;
    this->listVertical=new ListaOrtogonal();

}
//********************************************************************************
//************************CLASE LISTA COLUMNA ************************************
//********************************************************************************
ListaCabeceraColumna::ListaCabeceraColumna()
{
    this->primero=nullptr;
    this->ultimo=nullptr;
}

std::string ListaCabeceraColumna::insertar(NodoOrtogonal* nuevo){

    std::string respuesta="";

    if(primero==nullptr)
    {
        NodoCabeceraColumna* nuevoCol = new NodoCabeceraColumna(nuevo);
        respuesta =  nuevoCol->listVertical->insertarListaVertical(nuevo);
        primero=nuevoCol;
        primero->sig =nullptr;
        primero->ant = nullptr;
        ultimo=primero;

        respuesta ="Se ingreso la primera Columna y "+respuesta;

    }//si no existe el nodo se deberar crear y ordenar en la lista
    else if(buscarCol(nuevo->getIndex().horaInicio)==nullptr)
    {
        NodoCabeceraColumna* nuevoCol = new NodoCabeceraColumna(nuevo);
        respuesta = nuevoCol->listVertical->insertarListaVertical(nuevo);

        ordenar(nuevoCol);
        respuesta ="Se agrego la Columna se ordeno y "+respuesta;

    }//si el nodo existe solo se utliza y se envia el nodoortogonal
    else
    {
        NodoCabeceraColumna* aux = buscarCol(nuevo->getIndex().horaInicio);
        respuesta=aux->listVertical->insertarListaVertical(nuevo);
        respuesta ="se utilizo la Columna ya creada y "+respuesta;
    }
    return respuesta;


}

NodoCabeceraColumna* ListaCabeceraColumna::buscarCol(std::string horaInicio){

    NodoCabeceraColumna* tmp = primero;

    while (tmp!=nullptr) {
        if(tmp->horaInicio == horaInicio){
            return tmp;
        }
        tmp = tmp->sig;
    }
    return nullptr;

}

void ListaCabeceraColumna::ordenar(NodoCabeceraColumna* nuevo){

    NodoCabeceraColumna* actual = primero;

    csv::getnum(nuevo->horaInicio);
    //si el nuevo es menor al primero
    if( csv::getnum(nuevo->horaInicio)<= csv::getnum(primero->horaInicio) )
    {
        primero->ant=nuevo;
        nuevo->sig = primero;
        nuevo->ant= nullptr;
        primero=nuevo;


    }//si  es mayor o igual al ultimo
    else if(csv::getnum(nuevo->horaInicio)>= csv::getnum(ultimo->horaInicio))
    {
        ultimo->sig = nuevo;
        nuevo->ant = ultimo;
        nuevo->sig  = nullptr;
        ultimo = nuevo;

    }//recoriendo la lista si nuevo es mayor o igual actual
    //y si nuevo es menor o igual siguiente de actual
    else
    {
        while(actual!=ultimo)
        {
            if((csv::getnum(nuevo->horaInicio)>= csv::getnum(actual->horaInicio) )
               &&(csv::getnum(nuevo->horaInicio)<= csv::getnum(actual->sig->horaInicio) ) )
            {
                nuevo->sig =actual->sig;
                nuevo->ant =  actual;
                actual->sig->ant =nuevo;
                actual->sig = nuevo;
                break;
            }
            actual = actual->sig;
        }

    }

}

//********************************************************************************
//************************CLASE matriz        ************************************
//********************************************************************************

matriz::matriz()
{
    this->fila = new ListaCabeceraFila();
    this->col = new ListaCabeceraColumna();

}

std::string  matriz::insertar(stOrtogonal datos,listCursos* cursos, listEdificios* edificios ){

    std::string respuesta="";
    salonEdificio EdificioEncontrado = edificios->obtnerSalon(datos.edificio,datos.no_salon);
    nodoCurso* cursoEncontrado = cursos->buscarId(datos.idCurso);

    if((EdificioEncontrado.salon!=nullptr)&&(cursoEncontrado!= nullptr)&&(EdificioEncontrado.edificio!=nullptr))
    {
        xy indice;
        indice.horaInicio=datos.horaInicio;
        indice.salon = EdificioEncontrado.salon;
        indice.edificio= EdificioEncontrado.edificio;
        contenido cont ;
        cont.horaFinal = datos.horaFinal;
        cont.curso = cursoEncontrado;
        NodoOrtogonal* nuevo = new NodoOrtogonal(indice,cont);

        this->dia = datos.dia;
        respuesta +="{"+fila->insertar(nuevo)+"}";
        respuesta +="{"+col->insertar(nuevo)+"}";

    }else{


        respuesta ="no se encontro el salon o el edificio enviado o el curso";
    }


    return  respuesta;

}

void matriz::graficar(){
    std::string nombre = "matriz";
    generarDot(nombre);

    //especificar el nomabre en los metodos system
    system("dot -Tsvg -O matriz.dot");
    system("xdg-open matriz.dot.svg");

}

void matriz::generarDot(std::string nombre){

    std::ofstream archivo;
    archivo.open(nombre+".dot",std::ios::out);//abriendo el archivo
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

    archivo<<"digraph g "<<std::endl;
    archivo<<"{\n"<<std::endl;
    archivo<<"\tnodesep = 0.5;\n"<<std::endl;
    archivo<<"\tnode[shape=box, color=turquoise4, fillcolor=green,style=filled ];\n"<<std::endl;
    archivo<<"\tedge[color=tomato];\n"<<std::endl;
    archivo<<"\trankdir=UD;\n"<<std::endl;

    archivo<<txtCabeceraCol()<<std::endl;
    archivo<<txtCabeceraFila()<<std::endl;
    archivo<<txtFilas()<<std::endl;
    archivo<<txtColumnas()<<std::endl;

    archivo<<"}"<<std::endl;
    archivo.close();//cerrar el archivo


}

std::string matriz::txtCabeceraCol()
{
    std::string result = "";
    std::string rank ="\t{ rank = same ;";


    NodoCabeceraColumna* actual = col->primero;
    std::string Aclean="";
    std::string Acleansig="";
    std::string Ahora="";

    result+="\t//----------------------cabecera columnas-----------------------\n";
    while(actual != nullptr){

        Aclean = dia+csv::clean(actual->horaInicio);
        Ahora = actual->horaInicio;

        if(actual->sig==nullptr){

            if(actual==col->primero){


                result+="\t"+dia+" -> nd"+Aclean+"[constraint=false];\n";
                result+="\tnd"+Aclean;
                result+="[label =\""+Ahora+"\"];\n";
                rank+= dia+"; nd"+Aclean+";}\n";

            }else{


                result+="\tnd"+Aclean;
                result+="[label =\""+Ahora+"\"];\n";

                rank+=" nd"+Aclean+";}\n";

            }

        }else{

            Acleansig = dia+csv::clean(actual->sig->horaInicio);
            if(actual==col->primero){

                result+="\t"+dia+" -> nd"+Aclean+"[constraint=false];\n";

                result+="\tnd"+Aclean;
                result+="[label =\""+Ahora+"\"];\n";

                result+="\tnd"+Aclean;
                result+=" -> ";
                result+= "nd"+Acleansig;
                result+=" -> ";
                result+="nd"+Aclean+"[constraint=false];\n";

                rank+= dia+"; nd"+Aclean+";";

            }else{

                result+="\tnd"+Aclean;
                result+="[label =\""+Ahora+"\"];\n";

                result+="\tnd"+Aclean;
                result+=" -> ";
                result+= "nd"+Acleansig;
                result+=" -> ";
                result+="nd"+Aclean+"[constraint=false];\n";

                rank+=" nd"+Aclean+";";

            }

        }

        actual =actual->sig;
    }


     result+=rank;
     return result;
}

std::string matriz::txtCabeceraFila(){

    std::string result="\n\n";
    std::string edificio="";
    std::string edificiosig="";
    std::string no_salon ="";
    std::string no_salonsig="";
    std::string edificioClean ="";
    std::string edificioCleanSig ="";

    NodoCabeceraFila* actual = fila->primero;

    result+="\t//----------------------cabecera filas-----------------------\n";
    while(actual != nullptr){

        edificioClean =actual->edificio->getValor();
        edificio = dia+csv::ReplaceAll(edificioClean,"-","") ;
        no_salon = std::to_string(actual->salon->getValor().no_salon);

        if(actual->abajo==nullptr){

            if(actual==fila->primero){

                result+="\t"+dia+" -> nd"+edificio+no_salon+"[constraint=true];\n";
                result+="\tnd"+edificio+no_salon;
                result+="[label =\""+edificioClean+"\\n"+no_salon+"\"];\n";


            }else{

                result+="\tnd"+edificio+no_salon;
                result+="[label =\""+edificioClean+"\\n"+no_salon+"\"];\n";

            }

        }else{
            edificioCleanSig = actual->abajo->edificio->getValor();
            edificiosig =dia+csv::ReplaceAll(edificioCleanSig,"-","") ;
            no_salonsig = std::to_string(actual->abajo->salon->getValor().no_salon);

            if(actual==fila->primero){

                result+="\t"+dia+" -> nd"+edificio+no_salon+"[constraint=true];\n";

                result+="\tnd"+edificio+no_salon;
                result+="[label =\""+edificioClean+"\\n"+no_salon+"\"];\n";

                result+="\t nd"+edificio+no_salon;
                result+=" -> ";
                result+= "nd"+edificiosig+no_salonsig;
                result+=" -> ";
                result+="nd"+edificio+no_salon+"[constraint=true];\n";

            }else{

                result+="\tnd"+edificio+no_salon;
                result+="[label =\""+edificioClean+"\\n"+no_salon+"\"];\n";

                result+="\t nd"+edificio+no_salon;
                result+=" -> ";
                result+= "nd"+edificiosig+no_salonsig;
                result+=" -> ";
                result+="nd"+edificio+no_salon+"[constraint=true];\n";

            }

        }

        actual =actual->abajo;
    }



    return result;
}

std::string matriz::txtFilas(){
    std::string result = "";
    std::string cabecera ="";
    std::string nodo="";
    std::string nodosig ="";
    std::string horafinal="";
    std::string cat ="";
    std::string curso="";
    std::string rank ="\t{ rank = same ;";



    NodoCabeceraFila* actual = fila->primero;
    NodoOrtogonal* aux ;

    while(actual != nullptr){
        rank ="\t{ rank = same ;";
        cabecera ="nd";
        cabecera +=dia+csv::ReplaceAll(actual->edificio->getValor(),"-","") ;
        cabecera += std::to_string(actual->salon->getValor().no_salon);

         result +="\t//---------------- FIla:"+cabecera+"--------------------------\n";

        aux = actual->listHorizontal->primerolistaHorizontal;
        while(aux!=nullptr)
        {

             nodo = "";
             nodo += cabecera;
             nodo += csv::clean(aux->getIndex().horaInicio);
             horafinal = aux->getContenido().horaFinal;
             cat = aux->getContenido().curso->getCatedratico()->getValor().nombre;
             curso =aux->getContenido().curso->getValor().nombre;


            if(aux->getder()==nullptr)
            {
                if(aux == actual->listHorizontal->primerolistaHorizontal){

                    result+="\t"+cabecera+" -> "+nodo+"[constraint=false];\n";
                    result+="\t"+nodo;
                    result+="[label =\""+cat+"\\n"+curso+"\\n"+horafinal+"\"];\n";
                    rank+= cabecera+"; "+nodo+";}\n";

                }else{

                    result+="\t"+nodo;
                    result+="[label =\""+cat+"\\n"+curso+"\\n"+horafinal+"\"];\n";
                    rank+= nodo+";}\n";

                }


            }else{

                nodosig ="";
                nodosig += cabecera;
                nodosig += csv::clean(aux->getder()->getIndex().horaInicio);

                if(aux == actual->listHorizontal->primerolistaHorizontal){


                    result+="\t"+cabecera+" -> "+nodo+";\n";
                    result+="\t"+nodo;
                    result+="[label =\""+cat+"\\n"+curso+"\\n"+horafinal+"\"];\n";
                    result+="\t"+nodo;
                    result+=" -> ";
                    result+= nodosig;
                    result+=" -> ";
                    result+=nodo+"[constraint=false];\n";

                    rank+= cabecera+"; "+nodo+";";


                }else{

                    result+="\t"+nodo;
                    result+="[label =\""+cat+"\\n"+curso+"\\n"+horafinal+"\"];\n";

                    result+="\t"+nodo;
                    result+=" -> ";
                    result+= nodosig;
                    result+=" -> ";
                    result+=nodo+";\n";

                    rank+= nodo+";";


                }

            }


            aux= aux->getder();
        }

        result+= rank+"";
        actual =actual->abajo;
    }



    return result;
}

std::string matriz::txtColumnas(){
    std::string result = "";

    std::string cabecera ="";
    std::string nodo="";
    std::string nodosig ="";




    NodoCabeceraColumna* actual = col->primero;
    NodoOrtogonal* aux ;

    while(actual != nullptr){

        cabecera ="";
        cabecera +=csv::clean(actual->horaInicio);

        aux = actual->listVertical->primerolistaVertical;
         result +="\n\t//---------------- Col:"+dia+cabecera+"--------------------------\n";
        while(aux!=nullptr)
        {
             nodo = "";
             nodo += dia+csv::ReplaceAll(aux->getIndex().edificio->getValor(),"-","");
             nodo +=std::to_string(aux->getIndex().salon->getValor().no_salon);
             nodo += cabecera;



            if(aux->getDown()==nullptr)
            {
                if(aux == actual->listVertical->primerolistaVertical){

                    result+="\tnd"+dia+cabecera+" -> nd"+nodo+"[constraint=true];\n";

                }


            }else{

                nodosig ="";
                nodosig +=dia+csv::ReplaceAll(aux->getDown()->getIndex().edificio->getValor(),"-","");
                nodosig +=std::to_string(aux->getDown()->getIndex().salon->getValor().no_salon);
                nodosig += cabecera;

                if(aux == actual->listVertical->primerolistaVertical){


                    result+="\t nd"+dia+cabecera+" -> nd"+nodo+"[constraint=true];\n";
                    result+="\tnd"+nodo;
                    result+=" -> ";
                    result+="nd"+nodosig;
                    result+=" -> ";
                    result+="nd"+nodo+"[constraint=true];\n";

                }else{

                    result+="\tnd"+nodo;
                    result+=" -> ";
                    result+="nd"+nodosig;
                    result+=" -> ";
                    result+="nd"+nodo+"[constraint=true];\n";



                }

            }


            aux= aux->getDown();
        }


        actual =actual->sig;
    }

    return result;
}

std::string matriz::getDot()
{
    std::string result ="";

    result += "//------------------------------------"+this->dia+"------------------------\n";
    result += "subgraph cluster_"+this->dia+"\n";
    result += "{\n";
    result += "\tnodesep = 0.5;\n";
    result += "\tnode[shape=box, color=turquoise4, fillcolor=green,style=filled ];\n";
    result += "\tedge[color=tomato];\n";
    result += "\trankdir=UD;\n";
    result += txtCabeceraCol();
    result += txtCabeceraFila();
    result += txtFilas();
    result += txtColumnas();
    result += "\tcolor=blue;\t";
    result += "\tlabel=\"Matriz del dia "+this->dia+"\"\n";
    result += "\t}\n";

    return result;
}







