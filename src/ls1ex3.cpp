/**
 * @author Josivan Medeiros da Silva Gois
 * @brief Lista 1 - Questão 2 Unidade 1 Cálculo Numérico
 */
#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include "util.h"

using namespace std;

float f_k(int k, float x) {
  if ( k%2 ) {
    return pow( -1, (k-1)/2 )*k*cos(x)+pow( -1,(k+1)/2 )*x*sin(x);
  }
  else {
    return pow( -1, (k)/2 )*k*sin(x)+pow( -1,(k)/2 )*x*cos(x);
  }
}
int fat(int n){
  int f = 1;
  for (int i=2; i <= n;++i)
    f *= i;
  return f;
}
int main( int argc, char * argv[] )
{
  cout << "Cálculo Numérico\nLista1 - Questão 02\n";
  ofstream gp_file;
  gp_file.open("files/ls1ex3.gp", ofstream::out);
  int g = 12;//grau do polinômio
  cout << "Aproximação com n = " << g << ":\n";
  float a = 0;
  gp_file << "set yrange[-10:10]\n";
  gp_file << "plot x*cos(x), ";
  for (int n=0; n < g; ++n) {
    cout << f_k(n, a)/ fat(n) << "*(x-"<<a<<")**" << n << " + ";
    gp_file << f_k(n, a)/ fat(n) << "*(x-"<<a<<")**" << n << " + ";
  }
  cout << f_k(g, a)/ fat(g) << "*(x-"<<a<<")**" << g << "\n";
  gp_file << f_k(g, a)/ fat(g) << "*(x-"<<a<<")**" << g
    << " title \"Serie de Taylor grau "<<g<<"\"";
  return 0;
}
