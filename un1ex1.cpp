/**
 * @author Josivan Medeiros da Silva Gois
 *
 * Lista 1
 * 1. Considere a função f(x) = x³-2*x²-x+2. Plote em um
 * mesmo gráfico:
 * [x] f(x) com a legenda "função cúbica" no intervalo de x [-1.5, 2.5]
 * [ ] a reta tangente no ponto (1, f(1)) com a legenda 
 * "reta tangente em x = 1"
 * [ ] 4 pontos: (1, f(1)), a interseção entre a reta tangente e o eixo x,
 * os dois pontos críticos (e as respectivas retas tangentes)
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "include/util.h"

using namespace std;

int f( int x ){
  return x*x*x-2*x*x-x+2;
}

int f_( int x ){
  return 3*x*x-4*x-1;
}
/**
 * Retorna a reta em forma de string:
 * "a*x + b"
 * onde a e b são respectivamente os coeficientes
 */
char * tan_line(int * pol_coefs, int * point){
  char * r = "a*x+b";
  int i = sizeof(pol_coefs)/sizeof(int*) - 1;

  return r;
}


int main( int argc, char * argv[] )
{
  // x³-2x²-x+2
  Polynomial poly{1,-2,-1,2};
  std::cout << poly;
  //char * reta = reta({1,-2,-1,2});
  Polynomial dydx = derive(poly);
  std::ofstream gp_file;
  gp_file.open("ls1ex1.gp");
  std::cout << "xrange[-1.5:2.5]\n"
    << "plot x^3-2*x^2-x+2, title \"funcao cubica\" \\\n"
    << "";
  return 0;
}

