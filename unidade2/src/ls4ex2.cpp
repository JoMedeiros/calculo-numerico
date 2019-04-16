/**
 * @author Josivan Medeiros da Silva Gois
 * @brief Lista 1 - Questão 2 Unidade 1 Cálculo Numérico
 */
#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <list>
//#include "util.h"

using namespace std;

float f_linha(float x) {
  return cos(x) - x * sin(x);
}

int main( int argc, char * argv[] )
{
  //cout << "Cálculo Numérico\nLista1 - Questão 02\n";
  list<float> xs, ys;
  float h=0.05;
  float x = 0, y = 1;
  while (x <= 6) {
    xs.push_back(x);
    ys.push_back(y);
    //cout << x << ", " << y << "\n";
    y += h * f_linha(x);
    x += h;
  }
  x = 0; y = 1;
  while (x >= -6) {
    xs.push_front(x);
    ys.push_front(y);
    //cout << x << ", " << y << "\n";
    y -= h * f_linha(x);
    x -= h;
  }
  ofstream gp_file;
  gp_file.open("files/ls1ex2.pts", ofstream::out);
  for (auto it1=xs.begin(), it2=ys.begin(); it1 != xs.end(); ++it1) {
    gp_file << *it1 << ", " << *it2 << "\n";
    ++it2;
  }

  return 0;
}
