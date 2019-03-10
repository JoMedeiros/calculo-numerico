/**
 * @author Josivan Medeiros da Silva Gois
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "util.h"

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
  Polynomial dydx = derive(poly);
  cout << "original function: " << poly << "\n";
  cout << "derivative: " << dydx << "\n";
  //char * reta = reta({1,-2,-1,2});
  ofstream gp_file;
  gp_file.open("ls1ex1.gp");
  std::cout << "xrange[-1.5:2.5]\n"
    << "plot x^3-2*x^2-x+2, title \"funcao cubica\" \\\n"
    << "";
  Polynomial f{1, 0, 0};
  cout << "f(2) = " << f(2) << "\n";
  return 0;
}

