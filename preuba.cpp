

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <list>
using namespace std;

struct catedratico
{

    string cod_catedratico;
    string nombre_catredratico;


};

struct Nodo
{
    catedratico dato;
    Nodo *derecha;
    Nodo *izquierda;
    Nodo  *padre;

};

//prototipos
Nodo *crearNodo(catedratico,Nodo *);
void insertar(Nodo *&, catedratico,Nodo*);
void mostarArbol(Nodo*,int);
void graficar(string,string);
void mostarArbolDOTDeclarandoNodos(Nodo*);
void mostarArbolDOTUnionDeNodos(Nodo*);
bool busqueda(Nodo* arbol, catedratico n);
string busquedaPorCodigo(Nodo* arbol, string);
void eliminar(Nodo*, catedratico );
void eliminarNodo(Nodo * );
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destuirNodo(Nodo *);

//**************************************************************************************************************

//INICIALIZAR ARBOL
Nodo *arbol =NULL;
string retornar="";



//**************************************************************************************************************

Nodo *crearNodo(catedratico n, Nodo *padre)
{

    Nodo *nuevonodo= new Nodo();

    nuevonodo->dato = n;
    nuevonodo->derecha =NULL;
    nuevonodo->izquierda=NULL;
    nuevonodo->padre = padre;

    return nuevonodo;
}

void insertar(Nodo *&arbol,catedratico n, Nodo *padre)
{

    if(arbol==NULL)
    {
        Nodo*nuevonodo= crearNodo(n,padre);
        arbol=nuevonodo;
        cout<<"raiz creada"<<endl;
    }
    else
    {

        if(!busqueda(arbol,n))
        {

            string valorRaiz= arbol->dato.cod_catedratico;
            //if(n.cod_catedratico<valorRaiz)
            if((n.cod_catedratico)< (valorRaiz))
            {

                insertar(arbol->izquierda, n,arbol);
                cout<<"nodo insertado a la izquieda"<<endl;
            }
            else
            {

                insertar(arbol->derecha,n,arbol);
                cout<<"nodo insertado a la derecha"<<endl;
            }

        }
        else
        {
            cout<<"ya existe este nodo , no se inserto este nodo "<<n.cod_catedratico<<" verificar grafica " <<endl;
        }

    }
}



void mostarArbol(Nodo *arbol, int cont)
{

    if(arbol==NULL)
    {

        return;
    }
    else
    {

        mostarArbol(arbol->derecha, cont+1);
        for(int i=0; i<cont; i++)
        {
            cout<<"  ";
        }
        cout<<arbol->dato.cod_catedratico<< endl;
        mostarArbol(arbol->izquierda, cont+1);
    }
}


void mostarArbolDOTDeclarandoNodos(Nodo *arbol)
{

    if(arbol==NULL)
    {

        return;
    }
    else
    {

        //retornar+= to_string(arbol->dato.cod_catedratico);
        retornar+=arbol->dato.cod_catedratico;
        retornar+="[label= \"ID_catedratico: ";
        retornar+=arbol->dato.cod_catedratico;
        retornar+="\n Nombre Catedratico: ";
        retornar+=arbol->dato.nombre_catredratico;
        retornar+="\"];";
        retornar+="\n";



        if(arbol->izquierda!=NULL)
        {
            retornar+=arbol->dato.cod_catedratico;
            retornar+="[label= \"ID_catedratico: ";
            retornar+=arbol->dato.cod_catedratico;
            retornar+="\n Nombre Catedratico: ";
            retornar+=arbol->dato.nombre_catredratico;
            retornar+="\"];";
            // retornar+="->";
            mostarArbolDOTDeclarandoNodos(arbol->izquierda);

        }

        if(arbol->derecha!=NULL)
        {
            retornar+=arbol->dato.cod_catedratico;
            retornar+="[label= \"ID_catedratico: ";
            retornar+=arbol->dato.cod_catedratico;
            retornar+="\n Nombre Catedratico: ";
            retornar+=arbol->dato.nombre_catredratico;
            retornar+="\"];";
            mostarArbolDOTDeclarandoNodos(arbol->derecha);

        }


        //retornar+="->";




    }
}

void mostarArbolDOTUnionDeNodos(Nodo *arbol)
{

    if(arbol==NULL)
    {

        return;
    }
    else
    {
        retornar+= arbol->dato.cod_catedratico;
        retornar+="\n";



        if(arbol->izquierda!=NULL)
        {
            retornar+=arbol->dato.cod_catedratico;
            retornar+="->";
            mostarArbolDOTUnionDeNodos(arbol->izquierda);

        }

        if(arbol->derecha!=NULL)
        {
            retornar+=  arbol->dato.cod_catedratico;
            retornar+="->";
            mostarArbolDOTUnionDeNodos(arbol->derecha);

        }


        //retornar+="->";




    }
}

void graficar(string arbol,string circular)
{
    FILE *f;
    char direccion[] = "/home/marcos/grafica2.dot";
    f = fopen(direccion,"w");
    if(f==NULL)
    {
        cout << "no se creó el archivo" << endl;
    }
    else
    {


        ofstream archivo;
        archivo.open(direccion);

        //--------------------Aqui inicia la escritura del archivo-------------------

        archivo << "digraph G{ " << endl;
        archivo<<"node[shape=box];"<<endl;
    //    archivo <<
        archivo<<"subgraph cluster_0{"<<endl;
        archivo<<arbol<<endl;
        archivo<<"label=\"Arbol Binario De Busqueda\""<<endl;
        archivo <<"}"<<endl;

        archivo<<circular<<endl;
        //archivo<<"puta->mierda"<<endl;
        archivo << "}" << endl;

        //---------------------Aqui termina el archivo----------------

        archivo.close();
        system("dot -Tpng /home/marcos/grafica2.dot -O /home/marcos/Documentos/grafica2.png");
        system("xdg-open /home/marcos/grafica2.dot.png");


    }
}

bool busqueda(Nodo* arbol, catedratico n)
{
    if(arbol==NULL)
    {
        cout<<"metodo busqueda lista vacia return false"<<endl;
        return false;
    }
    else if(arbol->dato.cod_catedratico == n.cod_catedratico)
        //else if((arbol->dato.cod_catedratico) == n.cod_catedratico)
    {
        cout<<"metodo busqueda nodo encontrado return true "<< endl;
        return true;
    }
    else if(n.cod_catedratico < arbol->dato.cod_catedratico)
        //else if(n.cod_catedratico < arbol->dato.cod_catedratico)
    {
        return busqueda(arbol->izquierda, n);
    }
    else
    {
        return busqueda(arbol->derecha, n);
    }
}


string busquedaPorCodigo(Nodo* arbol, string n)
{
    if(arbol==NULL)
    {

        cout<<"metodo busqueda lista vacia return false"<<endl;
        return "nada";
    }
    else if((arbol->dato.cod_catedratico) == (n))
        //else if((arbol->dato.cod_catedratico) == n.cod_catedratico)
    {
        cout<<"metodo busqueda nodo encontrado return true "<< endl;
        return arbol->dato.cod_catedratico;
    }
    else if(n < arbol->dato.cod_catedratico)
        //else if(n.cod_catedratico < arbol->dato.cod_catedratico)
    {
        return busquedaPorCodigo(arbol->izquierda, n);
    }
    else
    {
        return busquedaPorCodigo(arbol->derecha, n);
    }
}


void eliminar(Nodo * arbol, catedratico n)
{
    if(arbol == NULL)
    {
        return;
    }
    // else if(n.cod_catedratico.compare(arbol->dato.cod_catedratico)<0)
    else if(n.cod_catedratico < arbol->dato.cod_catedratico)
    {
        eliminar(arbol->izquierda,n);
    }
    //  else if(n.cod_catedratico.compare(arbol->dato.cod_catedratico)>0)
    else if(n.cod_catedratico > arbol->dato.cod_catedratico)
    {
        // else if(n.cod_catedratico > arbol->dato.cod_catedratico) {
        eliminar(arbol->derecha, n);
    }
    else
    {
        eliminarNodo(arbol);
    }

}
//funcion para determinar el nodo mas izquierdo posibke
Nodo *minimo(Nodo *arbol)
{
    if(arbol ==NULL)
    {
        return NULL;
    }
    if(arbol->izquierda)
    {
        return minimo(arbol->izquierda);
    }
    else
    {
        return arbol;
    }
}

//funcion para reemplazar nodos
void reemplazar(Nodo *arbol,Nodo*nuevo)
{
    if(arbol->padre)
    {
        if(arbol->dato.cod_catedratico==arbol->padre->izquierda->dato.cod_catedratico)
        {
            //   if(arbol->dato.cod_catedratico == arbol->padre->izquierda->dato.cod_catedratico){
            arbol->padre->izquierda = nuevo;
        }
        else if(arbol->dato.cod_catedratico == arbol->padre->derecha->dato.cod_catedratico)
            // else if(arbol->dato.cod_catedratico.compare(arbol->padre->derecha->dato.cod_catedratico)==0)
        {
            //  else if(arbol->dato.cod_catedratico == arbol->padre->derecha->dato.cod_catedratico){
            arbol->padre->derecha = nuevo;
        }
    }
    if(nuevo)
    {

        nuevo->padre= arbol->padre;
    }

}

void destuirNodo(Nodo *nodo)
{

    nodo->izquierda=NULL;
    nodo->derecha=NULL;

    delete nodo;

}

//ESTE OTRO METODO OBTIENEN EL NODO A ELIMINAR, EL METODO ANTERIOR SOLAMENTE UBICA EL NODO, SE PODRÍA USAR EL METODO DE BUSCAR PERO NO OBSTANTE ES MAS ORDENADO DE ESTE MODO
void eliminarNodo(Nodo* nodoEliminar)
{
    if(nodoEliminar->izquierda && nodoEliminar->derecha)
    {
        Nodo *menor = minimo(nodoEliminar->derecha);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izquierda)  //si tiene un izquirdo un hijo
    {
        reemplazar(nodoEliminar,nodoEliminar->izquierda);
        destuirNodo(nodoEliminar);
    }
    else if(nodoEliminar->derecha)
    {
        reemplazar(nodoEliminar,nodoEliminar->derecha);
        destuirNodo(nodoEliminar);
    }
    else
    {
        //si el nodo no tiene hijos
        reemplazar(nodoEliminar,NULL);
        destuirNodo(nodoEliminar);
    }

}


//*******************************************************///////
//*******************************************************///////
//*******************************************************///////
//*******************************************************///////
//*******************************************************/////////*******************************************************///////

/* Lista de cursos */

//*******************************************************///////

struct curso
{
    std::string id;
    std::string nombre;
    std::string cod_catedratico;


};


class nodousuario
{
public:
    curso dato;// la clase nodousuario tendra como atributos un usuario y dos nodos más, uno que apunte al siguiente nodo y uno al anterior
    nodousuario* siguiente;



public:
    nodousuario(curso us);//constructor de la clase
    nodousuario(curso us, nodousuario*sig);
    curso datonodo();//devolvera el usuario contenido en el nodo
    nodousuario* getsiguiente();//obtener siguiente nodo

    void setdato(curso us);
    void setsiguiente(nodousuario* aux);

};

nodousuario::nodousuario(curso us)
{
    dato=us;
    siguiente=NULL;


}
nodousuario::nodousuario(curso us,nodousuario* sig)
{
    dato=us;
    siguiente=sig;

}

curso nodousuario::datonodo()  //devuelve el dato del nodo
{
    return dato;

}

nodousuario* nodousuario::getsiguiente()
{
    return siguiente;

}



void nodousuario::setsiguiente(nodousuario* aux)
{

    siguiente=aux;
}



void nodousuario::setdato(curso aux)
{
    dato=aux;
}


class listacircularsimple
{

public:
    int size;
    nodousuario* primero;
    nodousuario* ultimo;

    listacircularsimple();
    std::string insertarnodo(curso dato);
    void desplegar();
    bool buscarnodo(std::string id);
    void eliminarnodo();
    void ordenarlista();
    void ordenarlista1();
    std::string eliminarnodo(std::string id);
    std::string modificarnodo(std::string id,std::string nombre,string catedratico);
    nodousuario* retornarnodo(std::string id);
    string retornarDot();
    string retornarEnlacesConCirCular();
    std::list<curso> linealizar();

    std::string convertirbase64listasimple(const std::string name);


};

listacircularsimple::listacircularsimple()
{
    size=0;
    primero=NULL;
    ultimo=NULL;
}
std::string  listacircularsimple::insertarnodo(curso dato)
{

    bool respuesta=buscarnodo(dato.id);
    std::string resultado;


    nodousuario* nuevo=new nodousuario(dato);//se crea una nueva instancia de la estructura nodo
    //Nodousuario* nuevo=new Nodousuario(dato);//se crea una nueva instancia de la estructura nodo
    if (primero==NULL)  //SI LA LISTA ESTA VACIA
    {
        primero=nuevo;
        primero->setsiguiente(primero);

        ultimo=primero;
        size++;
        //   std::cout<< "\n El primero es: " << primero->datonodo().nombre << " y el ultimo: " << ultimo->datonodo().nombre;
//resultado="Usuario agregado correctamente";
        resultado="true";
        return resultado;
    }
    else
    {
        if (respuesta==true)
        {
            //resultado="Ya existe un usuario con ese ID";
            resultado="false";
            return resultado;
            //    cout<<"\n YA EXISTE UN USUARIO CON ESE ID!";
        }
        else
        {

            ultimo->setsiguiente(nuevo);
            nuevo->setsiguiente(primero);

            ultimo=nuevo;
            size++;
            //resultado="Usuario agregado correctamente";
            resultado="true";
            return resultado;
            //std::cout<< "\n El primero es: " << primero->datonodo().nombre << " y el ultimo: " << ultimo->datonodo().nombre;
        }
    }

}


void listacircularsimple::desplegar()  //este es el que sirve
{

    nodousuario* actual;
    actual=primero;
    if(primero!=NULL)
    {


        do
        {
            curso aux=actual->datonodo();
            std::string cadena;
            cout<<"\n";
            cadena+= aux.id+ " " + " " + aux.nombre+"\n"+""+(aux.cod_catedratico);
            cout <<"LA CADENA ES: " << cadena;
            cout<<"\n";
            actual=actual->getsiguiente();
//
        }
        while (actual!=primero);


    }
    else
        cout<<"\n la lista se encuentra vacia!\n";

}



string listacircularsimple::retornarEnlacesConCirCular()  //este es el que sirve
{
    string retornarenlaces="";
    nodousuario* actual;
    actual=primero;
    if(primero!=NULL)
    {


        do
        {
            curso aux=actual->datonodo();
            std::string cadena;
            cout<<"\n";
            cadena+= aux.id+ " " + " " + aux.nombre+"\n"+""+(aux.cod_catedratico);
            cout <<"LA CADENA ES: " << cadena;
            cout<<"\n";
            retornarenlaces += aux.id + "->" + busquedaPorCodigo(arbol,aux.cod_catedratico)+"[color=orange];\n";

            cout<<retornarenlaces<<endl;
            actual=actual->getsiguiente();
//
        }
        while (actual!=primero);



    }
    else
        cout<<"\n la lista se encuentra vacia!\n";

    return retornarenlaces;
}




bool listacircularsimple::buscarnodo(std::string id)
{
    nodousuario* actual;
    bool encontrado=false;

    actual=primero;
    if(primero!=NULL)
    {
        curso aux=actual->datonodo();

        do
        {

            aux=actual->datonodo();
            if (aux.id==id)
            {
                //       cout<< "\n"<< "Nodo encontrado!!";
                //       cout<< "\n"<< aux.id;
                //  cout<< "\n"<< aux.nombre;
                //  cout<< "\n";
                encontrado=true;
                //cout<<"\n"<<"Encontrado:"<<encontrado;
                return encontrado;

            }



            actual=actual->getsiguiente();
//
        }
        while (actual!=primero);
        return encontrado;

    }//else
    // cout<<"\n la lista se encuentra vacia!\n";


}

void listacircularsimple::ordenarlista()
{
    //std::cout<<"\nENTRA A ORDENAR";
    nodousuario* aux=primero;
    nodousuario* aux2;
    curso us;
    //std::cout<<"\nENTRA A ORDENAR 2 \n";
    //while(aux != NULL)
    do
    {
        aux2=aux->getsiguiente();
        //  while(aux2 != NULL)
        do
        {
            if((aux->dato.nombre) > (aux2->dato.nombre))
            {
                //  usuario dato=aux2->dato;
                us=aux2->datonodo();
                aux2->setdato(aux->dato);
                aux->setdato(us);
            }
            aux2 = aux2->getsiguiente();
        }
        while(aux2!=primero);
        aux = aux->getsiguiente();
    }
    while(aux->getsiguiente()!=primero);
    //std::cout<<"\nENTRA A ORDENAR 3 \n";
}
void listacircularsimple::ordenarlista1()
{
    // std::cout<<"\nENTRA A ORDENAR";
    nodousuario* aux=primero;
    //  std::cout<<"\nENTRA A ORDENAR 2 \n";
    while(aux!=NULL)
    {
        nodousuario* aux2=aux->getsiguiente();

        while (aux2!=NULL)
        {
            if(aux->datonodo().nombre>aux2->datonodo().nombre)
            {
                curso dato=aux2->datonodo();
                aux2->setdato(aux->datonodo());
                aux->setdato(dato);
            }
            aux=aux->getsiguiente();
        }

    }
}

string listacircularsimple::retornarDot()
{
    nodousuario* actual;
    nodousuario* actual2;
    nodousuario* actual3;
    actual=primero;
    actual2=primero;
    actual3=primero;
    string retorno="";
//std::remove("/home/marcos/Documentos/imagenlistausuarios.dot");



//std::remove("/home/marcos/Documentos/imagenlistausuarios.jpg");





    // std::ofstream fileOut ( fichero.c_str());
    retorno+= "subgraph cluster_1 {" ;
    retorno+= "fontname = \"Arial\";";
    //retorno+= std::string("rankdir=\"LR\"") +";";
    //fileOut <<  std::string("fontname=\"Arial\"") +";"<< endl;
    retorno+=  std::string("shape=\"record\"") +";";
    // retorno+=  std::string("dir=\"both\"") +";";
    // retorno+= "node[fontname = \"Arial\" fontsize = 7  height=0.1 widht=0.2 shape = \"record\" rankdir=\"LR\" ];";
    // fileOut <<   "edge [dir=both, tailclip=false, arrowtail=dot, arrowhead=empty]"<< endl;
    //    fileOut << std::string("Alan") + "[label =  \"{" + "MAYA" + "|" + "serio"+ " " +"cantante"+ "}\"" +"]" << endl;

    //fileOut << std::string ("node1") + "[label = \"{" + " <n>" +  "|" + " 1 " + "|" + "<p>" + "}\"" + "]"+ ";" <<endl;
    if(primero!=NULL)
    {

        string auxrank="";
        auxrank+="{rank=same ";
        do
        {


            curso aux=actual3->datonodo();
            //   string cadena;

            //     cadena+= aux.id + "\n" + "\n" + aux.nombre + "\n" + aux.direccion + "\n" + aux.telefono +"\n";
            auxrank+=aux.cod_catedratico;
            auxrank+= " ";
//fileOut << std::string (aux.id) + "[label = \" <n>  |"+aux.id + "\\n"  + aux.nombre +  "\\n" + aux.direccion+ "\\n"+ aux.telefono+ "  |<p>  \"]" + ";" <<endl;
            actual3=actual3->getsiguiente();
//
            // cout<< cadena;
        }
        while (actual3!=primero);
        retorno+= auxrank + " };";


    }

    if(primero!=NULL)
    {


        do
        {
            curso aux=actual->datonodo();
            //   string cadena;

            //     cadena+= aux.id + "\n" + "\n" + aux.nombre + "\n" + aux.direccion + "\n" + aux.telefono +"\n";
            retorno+= std::string (aux.id) + "[label = \" "  +aux.id + "   \n  "  + aux.nombre + "\"" + "]"+ ";";
//fileOut << std::string (aux.id) + "[label = \" <n>  |"+aux.id + "\\n"  + aux.nombre +  "\\n" + aux.direccion+ "\\n"+ aux.telefono+ "  |<p>  \"]" + ";" <<endl;
            actual=actual->getsiguiente();
//
            // cout<< cadena;
        }
        while (actual!=primero);


    }// aqui termino de imprimir los nodos


    if(primero!=NULL)
    {


        do
        {
            curso aux=actual2->datonodo();
            // usuario aux2=actual2->getsiguiente()->datonodo();
            retorno+=  std::string (aux.id) + "-> " + actual2->getsiguiente()->datonodo().id +"[color=green]; ";
            // fileOut <<  std::string (actual2->getsiguiente()->datonodo().id) + ":n -> " + aux.id +":p;"<<endl;


            actual2=actual2->getsiguiente();
//
            // cout<< cadena;
        }
        while (actual2!=primero);


    }




    // fileOut << std::string ("node2") + "[label = \"<n>   |2 |<p>  \"]" + ";" <<endl;
    //  fileOut << std::string ("node3") + "[label = \" <n>  | 3 |<p>  \"]" + ";" <<endl;
    //fileOut << std::string ("node4") + "[label = \"<n>   |4 |<p>  \"]" + ";" <<endl;
    // fileOut << std::string ("node5") + "[label = \" <n>  | 5 |<p>  \"]" + ";" <<endl;

//fileOut <<  std::string ("node1") + ":n -> node2:p;"<<endl;

//fileOut <<  std::string ("node2") + ":p -> node1:p;"<<endl;
//fileOut <<  std::string ("node2") + ":p -> node3:n;"<<endl;
//fileOut <<  std::string ("node3") + ":n -> node2:p;"<<endl;
//fileOut <<  std::string ("node3") + ":p -> node4:n;"<<endl;
//fileOut <<  std::string ("node4") + ":p -> node5:n;"<<endl;
    retorno+="\n label=\"Lista Circular ordenada por Orden Alfabetico\" \n";
    retorno+= "}";
    //fileOut.close();
    //system("dot -Tpng /home/marcos/imagenlistacursos.dot -O  /home/marcos/imagenlistacursos.png");
    //system("nohup display /home/marcos/imagenlistausuarios.ṕng &" );
    return retorno;
}







static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'
                               };
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};

void build_decoding_table()
{

    decoding_table = (char*)malloc(256);

    for (int i = 0; i < 64; i++)
        decoding_table[(unsigned char) encoding_table[i]] = i;
}

char *base64_encode(const unsigned char *data,
                    size_t input_length,
                    size_t *output_length)
{

    *output_length = 4 * ((input_length + 2) / 3);

    char *encoded_data =(char*) malloc(*output_length);
    if (encoded_data == NULL) return NULL;

    for (int i = 0, j = 0; i < input_length;)
    {

        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
    }

    for (int i = 0; i < mod_table[input_length % 3]; i++)
        encoded_data[*output_length - 1 - i] = '=';

    return encoded_data;
}





std::string listacircularsimple::convertirbase64listasimple(const std::string name)
{
    const char* auxiliar =name.c_str();//castear string a char
    FILE *file;
    unsigned char *buffer;
    char *lobi;

    //Open file
    file = fopen(auxiliar, "rb");
    if (!file)
    {
        fprintf(stderr, "Unable to open file %s", name);
        return "";
    }

    //Get file length
    fseek(file, 0, SEEK_END);
    long int fileLen=ftell(file);
    fseek(file, 0, SEEK_SET);

    //Allocate memory
    buffer=(unsigned char*)malloc(fileLen+1);
    if (!buffer)
    {
        fprintf(stderr, "Memory error!");
        fclose(file);
        return "";
    }

    //Read file contents into buffer
    fread(buffer, fileLen, 1, file);
    size_t output_length = 0;
    lobi = base64_encode(buffer, fileLen, &output_length);
    std::string cadena(lobi);
    //printf("%s\n", lobi);
    FILE *fp;
    fp = fopen ( "salida.txt", "w+" );
    //if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fputs(lobi,fp);
    fclose ( fp );
    fclose(file);
    //insert_blob(buffer);
    free(buffer);
    return cadena;
}


//metodos extra
std::string listacircularsimple::eliminarnodo(std::string id)
{
    std::string cadena;
    if(buscarnodo(id))
    {
        nodousuario *eliminar = retornarnodo(id);
        if(eliminar == primero && eliminar == ultimo)
        {
            primero = NULL;
            ultimo  = NULL;
            size--;
            //cadena="Usuario eliminado correctamente";
            cadena="true";
            return cadena;
        }
        else if(eliminar == primero)
        {
            ultimo->setsiguiente(primero->getsiguiente());
            primero = primero->getsiguiente();
            size--;
            //cadena="Usuario eliminado correctamente";
            cadena="true";
            return cadena;
        }
        else if(eliminar == ultimo)
        {
            nodousuario *aux;
            aux = primero;

            do
            {
                aux = aux->getsiguiente();
            }
            while(aux->getsiguiente()!= ultimo);

            aux->setsiguiente(primero);
            ultimo = aux;
            size--;
            //cadena="Usuario eliminado correctamente";
            cadena="true";
            return cadena;
        }
        else
        {
            nodousuario *aux;
            aux = primero;

            while(aux->getsiguiente()->dato.nombre < eliminar->dato.nombre)
            {
                aux = aux->getsiguiente();
            }
            aux->setsiguiente(aux->getsiguiente()->getsiguiente());
            size--;
//cadena="Usuario eliminado correctamente";
            cadena="true";
            return cadena;
        }

    } // cadena="No existe un usuario con ese ID";
    cadena="false";
    return cadena;
}


nodousuario* listacircularsimple::retornarnodo(std::string id)
{
    nodousuario* actual;
    bool encontrado=false;
    nodousuario* retorno;
    actual=primero;
    if(primero!=NULL)
    {
        nodousuario aux=actual->datonodo();

        do
        {

            curso  aux=actual->datonodo();
            if (aux.id==id)
            {
                //   cout<< "\n"<< "Nodo encontrado!!";
                //   cout<< "\n"<< aux.id;
                //cout<< "\n"<< aux.nombre;
                // cout<< "\n";
                retorno=actual;
                // encontrado=true;
                // cout<<"\n"<<"Encontrado:"<<encontrado;
                return actual;

            }



            actual=actual->getsiguiente();
//
        }
        while (actual!=primero);
        return retorno=NULL;

    }//else
    // cout<<"\n la lista se encuentra vacia!\n";


}











std::string listacircularsimple::modificarnodo(std::string id,std::string nombre,string catedratico)
{
    std::string cadena;
    nodousuario* mod=retornarnodo(id);
    if (mod==NULL)
    {
        //  cout<<"el tratamiento no existe";
//cadena="No existe el usuario";
        cadena="false";
        return cadena;

    }
    else
    {
        mod->dato.id=id;
        mod->dato.nombre=nombre;
        mod->dato.cod_catedratico;


        // cadena="Usuario modificado correctamente";
        cadena="true";
        return cadena;
        //cout<< "TRATAMIENTO MODIFICADO";
        //cout<< "NUEVO NOMBRE: " <<mod->dato.nombre;
        //     cout<< "NUEVO direccion: " <<mod->dato.direccion;


    }
}


std::list<curso> listacircularsimple::linealizar()
{
    std::list<curso> lista;
    nodousuario *tmp = primero;
    if (primero!=NULL)
    {
        do
        {
            lista.push_back(tmp->datonodo());
            tmp = tmp->getsiguiente();
        }
        while (tmp!=primero);
        return lista;

    }
}




int main()
{



    int contador=0;
//   catedratico nuevo= {75,"Pedro"};

    catedratico nuevo1= {"A20","Raul"};
    catedratico nuevo2= {"A80","Maria"};
    catedratico nuevo3= {"A15","Angelica"};
    catedratico nuevo4= {"A18","Roma"};
    catedratico nuevo5= {"A72","Neto"};
    catedratico nuevo6= {"A76","Grecia"};
    catedratico nuevo7= {"A79","Ana"};
    catedratico nuevo8= {"A38","Ana"};
    catedratico nuevo9= {"A75","Ana"};
    catedratico nuevo10= {"A95","Ana"};
    catedratico nuevo11= {"A77","Ana"};

    catedratico nuevo12= {"A92","Ana"};

    catedratico nuevo13= {"A100","Karla"};
    catedratico nuevo14= {"A78","Ana"};

    insertar(arbol,nuevo1,NULL);
    insertar(arbol,nuevo2,NULL);
    insertar(arbol,nuevo3,NULL);
    insertar(arbol,nuevo4,NULL);
    insertar(arbol,nuevo5,NULL);
    insertar(arbol,nuevo6,NULL);
    insertar(arbol,nuevo7,NULL);
    insertar(arbol,nuevo8,NULL);
    insertar(arbol,nuevo9,NULL);
    insertar(arbol,nuevo10,NULL);
    insertar(arbol,nuevo11,NULL);
    insertar(arbol,nuevo12,NULL);
    insertar(arbol,nuevo13,NULL);
    insertar(arbol,nuevo14,NULL);
  //  insertar(arbol,nuevo15,NULL);
   // insertar(arbol,nuevo16,NULL);
    //insertar(arbol,nuevo17,NULL);
   /* eliminar(arbol,nuevo6);
    eliminar(arbol,nuevo12);*/

    busquedaPorCodigo(arbol,"A80");




    mostarArbol(arbol,contador);
    mostarArbolDOTDeclarandoNodos(arbol);
    mostarArbolDOTUnionDeNodos(arbol);


    listacircularsimple *nueva = new listacircularsimple();

    curso curso1= {"X001","Investigacion de operaciones","A20"};
  curso curso2= {"X001","Matematica basica 1","A72"};
    curso curso3= {"X002","Organizacion computacional","A18"};
    curso curso4= {"X005","Analisis Probabilistico","A100"};
    nueva->insertarnodo(curso1);
    nueva->insertarnodo(curso2);
    nueva->insertarnodo(curso3);
    nueva->insertarnodo(curso4);
    nueva->ordenarlista();
    //nueva->ordenarlista1();
    nueva->desplegar();
    //nueva->retornarEnlacesConCirCular();
    cout<<"\n"<<endl;

    graficar(retornar,nueva->retornarDot()+nueva->retornarEnlacesConCirCular());





//   busqueda(arbol,nuevo10);

    return 0;
}
