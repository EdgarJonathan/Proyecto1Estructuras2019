#ifndef CSV_H
#define CSV_H
#include <list>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <bst.h>
#include <sstream>


class csv
{

public:
    csv();

   static std::list<catedratico> obtenerCatedraticos(std::string entrada);
   static  std::vector<std::string> split(const std::string& s, char delimiter);
   static   std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
   static  std::string limpiarCadena(std::string cadena);
   static  int getnum(std::string hora);
   static  std::string clean(std::string hora);
   static  int getNumDia(std::string dia);
   static  void mayuscula(std::string &pal);
   static  int to_int(const std::string &cadena);

};

#endif // CSV_H
