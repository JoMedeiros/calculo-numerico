/**
 * @author Josivan Medeiros da Silva Gois
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "util.h"

using namespace std;

int main( int argc, char * argv[] )
{
  // x³-2x²-x+2
  Polynomial poly{1,-2,-1,2};
  Polynomial dydx = derive(poly);
  Polynomial tan = tan_line(poly, Point(1, poly(1)));
  cout << "original function: " << poly << "\n";
  cout << "derivative in (1,1): " << dydx << "\n";
  cout << "tangent line in (1,1): " << tan << "\n";

  ofstream gp_file;
  gp_file.open("ls1ex1.gp");
  gp_file << "set xrange[-1.5:2.5]\nset yrange[-5:5]\n"
    << "plot " << poly << "title \"funcao cubica\", "
    << tan << " title \"reta tangente em x = 1\"\n";
  return 0;
}

