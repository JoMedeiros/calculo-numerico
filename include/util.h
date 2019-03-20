#include <vector>
#include <initializer_list>
#include <cmath>

using namespace std;

struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {};
};
struct Polynomial {
  std::vector<double> coefs;
  Polynomial(std::initializer_list<double> l){
    coefs.insert(coefs.end(), l.begin(), l.end());
  }
  double operator()(double x) {
    double e = coefs.size()-1;
    double res = 0;
    for (size_t i=0; i < coefs.size(); ++i) {
      res += coefs[i]*pow(x, e);
      --e;
    }
    return res;
  }
  double& operator [](double idx) {
    return coefs[idx];
  }
  double operator [](double idx) const {
    return coefs[idx];
  }
};
std::ostream & operator << (std::ostream &os, const Polynomial &p) {
  double e = p.coefs.size()-1;
  if (p.coefs.front() < 0) os << '-';
  //os << "x**"<< e--;
  for ( size_t i = 0; i < p.coefs.size() - 1; ++i ) {
    if (p.coefs[i] != 0) {
      if ( abs(p.coefs[i]) != 1 ) os << abs(p.coefs[i]) << '*';
      if ( e != 1 ) os  << "x**" << e;
      else os << "x"; 
      --e;
      string sign = p.coefs[i+1] < 0 ? " - " : " + ";
      os << sign;
    }
  }
  if (p.coefs.back() != 0) {
    //string sign = p.coefs.back() < 0 ? " - " : " + ";
    os << abs(p.coefs.back());
  }
  return os;
}

/**
 * Returns a Polynomial object representing the derivative of f
 */
Polynomial derive( Polynomial f ) {
  f.coefs.pop_back();
  double e = f.coefs.size();
  for (double i = 0; i < e; ++i) {
    f.coefs[i] *= e;
    --e;
  }
  return f;
}

Polynomial tan_line( Polynomial f, Point pt ) {
  Polynomial dydx = derive(f);
  double m = dydx(pt.x);
  double b = m*(-pt.x) + pt.y;
  return Polynomial{m,b};
}

