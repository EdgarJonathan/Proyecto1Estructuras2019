#ifndef CSV_H
#define CSV_H
#include <list>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <bst.h>


class csv
{

public:
    csv();

   static std::list<catedratico> obtenerCatedraticos(std::string entrada);

private:
   static  std::vector<std::string> split(const std::string& s, char delimiter);
   static   std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
   static  std::string limpiarCadena(std::string cadena);
};

#endif // CSV_H
