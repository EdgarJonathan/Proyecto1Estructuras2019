#include "csv.h"

csv::csv()
{

}


std::string csv::limpiarCadena(std::string cadena){

   // cadena = ReplaceAll(cadena," ","");
    cadena = ReplaceAll(cadena,"\t","");
    cadena = ReplaceAll(cadena,"\r","");
    cadena = ReplaceAll(cadena,"\f","");

    return cadena;
}


std::vector<std::string> csv::split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}




std::string csv::ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


std::list<catedratico> csv::obtenerCatedraticos(std::string entrada){

    char salto ='\n';
    char coma  = ',';
    std::list<catedratico> result ;
    catedratico aux ;


    entrada = limpiarCadena(entrada);
    std::vector<std::string> linea = split(entrada, salto);

    int size =0;
    for( auto i = linea.begin(); i != linea.end(); ++i )
    {
           std::vector<std::string> obj = split(*i, coma);
                    auto j =obj.begin();
                    aux.id =*j;
                    j =++j;
                    aux.nombre =*j;
                    result.push_back(aux);


            size++;
    }


    if(size==0){

        aux ={"NULL","NULL"};
        result.push_back(aux);
    }


    return result;


}




int csv:: getnum(std::string hora){

    int number=0;
    std::istringstream iss ( ReplaceAll(hora,":","") );
    iss >> number;

    return number;
}


std::string csv::clean(std::string hora){

    return ReplaceAll(hora,":","");
}


int csv::getNumDia(std::string dia)
{
    int result =0;
    mayuscula(dia);

    if(dia=="LUNES")
    {
        result =1;
    }else if(dia=="MARTES")
    {
        result =2;
    }else if(dia=="MIERCOLES")
    {
        result =3;
    }else if(dia=="JUEVES")
    {
        result =4;
    }else if(dia=="VIERNES")
    {
        result =5;
    }else if(dia=="SABADO")
    {
        result =6;
    }else if(dia=="DOMINGO")
    {
        result =7;
    }




    return result;
}


void csv::mayuscula(std::string &pal)
{
    for (int i =0;i<pal.length();i++) {

        pal[i]=towupper(pal[i]);
    }
}












