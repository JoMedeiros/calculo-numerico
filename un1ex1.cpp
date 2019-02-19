#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

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
  vector poly = {1,-2,-1,2};
  char * reta = reta({1,-2,-1,2});
  std::ofstream gp_file;
  gp_file.open("ls1ex1.gp");
  std::cout << "xrange[-1.5:2.5]\n"
    << "plot x*x*x-2*x*x-x+2, title \"funcao cubica\" \\\n"
    << ""
  return 0;
}

