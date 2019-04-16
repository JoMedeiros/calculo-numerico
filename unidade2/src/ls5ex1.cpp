/**
 * @author Josivan Medeiros da Silva Gois
 * @brief Lista 2 - Questão 1 Unidade 1 Cálculo Numérico
 */
#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include "util.h"

using namespace std;

/**
 * @brief Encontra a raiz no intervalo [a, b] se (a * b < 0) pelo método da Bisseção
 * @param f A função polinomial
 * @param e O erro tolerável
 * @param t O número de tentativas máximas
 */
float bissec_root (Polynomial f, float a , float b, float e=0.001, int t=1000) {
  int i = 0;
  float x;
  while ( fabs( f(x) ) > e and i < t )
  {
    x = (a + b) / 2.0;
    if ( f(x) * f(a) < 0 ) 
      b = x;
    else if ( f(x) * f(a) > 0 ) 
      a = x;
    else 
      break;
    ++i;
  }
  return x;
}

/**
 * @brief Encontra a raiz no intervalo [a, b] se (a * b < 0) pelo método da Bisseção
 * @param g A função de iteração
 * @param e O erro tolerável
 * @param t O número máximo de tentativas
 */
float ponto_fixo_root (Polynomial g, float x0, float e=0.001, int t=1000) {
  int i = 0;
  while (x0 != g(x0) and i < t){
    x0 = g(x0);
    ++i;
  }
  return x0;
}

/**
 * @brief Encontra a raiz no intervalo [a, b] se (a * b < 0) pelo método da Bisseção
 * @param g A função de iteração
 * @param e O erro tolerável
 * @param t O número máximo de tentativas
 */
float ponto_fixo_root (float (*g)(float), float x0, float e=0.001, int t=1000) {
  int i = 0;
  while (x0 != g(x0) and i < t){
    x0 = g(x0);
    ++i;
  }
  return x0;
}

float secantes_root(float (*func)(float), float x0, float x1, float e=0.01, int t=30) {
  float x2,f0,f1;
  f0=(*func)(x0);
  for (int j=0; j < t; ++j) {
    f1=(*func)(x1);
    x2=x1-(x1-x0)*f1/(f1-f0);
    if (fabs(x2-x1) < e || f == 0.0) return x2;
    x0=x1;
    x1=x2;
    f0=f1;
  }
  nrerror("Número máximo de iterações excedido!");
  return 0.0; //não é executado
}


int main( int argc, char * argv[] )
{
  cout << "Cálculo Numérico\nLista2 - Questão 01\n";
  Polynomial f{1,-1.7,-12.78,-10.08};
  Polynomial dfdx = derive(f);

  // a) Bissecao
  float a = 0;
  float b = 8;
  float x1, x2, x3;
  x1 = bissec_root(f, a, b, 0.001, 10000);
  cout << "Método da Bisseção\n";
  cout << "Raiz encontrada: " << x1 << "\n";
  a = -5;
  b = -1.5;
  x2 = bissec_root(f, a, b, 0.001, 10000);
  cout << "Raiz encontrada: " << x2 << "\n";
  a = -1.5;
  b = 0;
  x3 = bissec_root(f, a, b, 0.001, 10000);
  cout << "Raiz encontrada: " << x3 << "\n";
  
  // b) Iteração de Ponto Fixo
  x1 = x2 = x3 = 0;
  Polynomial g{(-1)/(-12.78),1.7/(-12.78),0,10.08/(-12.78)};
  float x0 = 0;
  x1 = ponto_fixo_root( g, x0 );
  x0 = 8;
  x2 = ponto_fixo_root( g, x0 );
  x0 = -1.5;
  x3 = ponto_fixo_root( g, x0 );
  cout << "Método do Ponto Fixo\n";
  cout << "Raiz encontrada: " << x1 << "\n";
  cout << "Raiz encontrada: " << x2 << "\n";
  cout << "Raiz encontrada: " << x3 << "\n";
  // c) Método Newton-Raphson
  x1 = x2 = x3 = 0;
  x0 = 8; 
  float e = 0.001;
  x1 = x0 - f(x0)/dfdx(x0);
  while ( fabs(f(x1)) > e) {
    x0 = x1;
    x1 = x0 - f(x0)/dfdx(x0);
  }
  x0 = 0;
  x2 = x0 - f(x0)/dfdx(x0);
  while ( fabs(f(x2)) > e) {
    x0 = x2;
    x2 = x0 - f(x0)/dfdx(x0);
  }
  x0 = -5;
  x3 = x0 - f(x0)/dfdx(x0);
  while ( fabs(f(x3)) > e) {
    x0 = x3;
    x3 = x0 - f(x0)/dfdx(x0);
  }
  cout << "Método de Newton-Raphson\n";
  cout << "Raiz encontrada: " << x1 << "\n";
  cout << "Raiz encontrada: " << x2 << "\n";
  cout << "Raiz encontrada: " << x3 << "\n";

  return 0;
}

