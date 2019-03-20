/**
 * @author Josivan Medeiros da Silva Gois
 * @brief Lista 1 - Questão 1 Unidade 1 Cálculo Numérico
 */
#include <iostream>
#include <fstream>
#include <utility>
#include "util.h"

using namespace std;

int main( int argc, char * argv[] )
{
  Polynomial poly{1,-2,-1,2};
  Polynomial dydx = derive(poly);
  Polynomial tan = tan_line(poly, Point(1, poly(1)));
  cout << "Cálculo Numérico\nLista1 - Questão 01\n";
  // a interseção entre a reta tangente e o eixo x
  // tan(x) = ax + b -> x = (b - tan(x)) / a --- a = tan[0]; b = tan[1]
  double x, y=0, a = tan[0], b = tan[1], c;
  x = (y - b) / a;
  // os dois pontos crı́ticos (e as respectivas retas tangentes)
  // dydx(x) = 0 -> dydx[2] * x² + dydx[1] * x + dydx[2]
  a=dydx[0]; b=dydx[1]; c=dydx[2];
  cout << "a = " << a << " b = " << b << " c =" << c << "\n";
  double Delta = b*b - 4*a*c;
  cout << "Delta = " << sqrt(Delta) << "\n";
  double x1 = (-b + sqrt(Delta)) / (2*a);
  cout << "x1 = " << x1 << "\n";
  double x2 = (-b - sqrt(Delta)) / (2*a);
  cout << x2 << "\n";

  ofstream gp_file;
  gp_file.open("files/ls1ex1.gp", ofstream::out);
  gp_file << "set xrange[-1.5:2.5]\nset yrange[-5:5]\n"
    << "plot " << poly << " title \"funcao cubica\", "
    << tan << " title \"reta tangente em x = 1\", "
    <<  poly(x1) << " title \"reta ponto critico 1\", "
    <<  poly(x2) << " title \"reta ponto critico 2\"\n"
    << "set label \"(1, f(x))\" at " << 1 << "," << poly(1) << " point pt 7\n"
    << "set label \"tan(x) = 0\" at " << x << "," << y << " point pt 7"
    << " offset -8,-1\n"
    << "set label \"ponto critico 1\" at " << x1 << "," << poly(x1) << " point pt 7\n"
    << "set label \"ponto critico 2\" at " << x2 << "," << poly(x2) << " point pt 7\n";
  return 0;
}

