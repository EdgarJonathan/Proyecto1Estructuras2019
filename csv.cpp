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





















