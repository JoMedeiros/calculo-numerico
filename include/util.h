#include <vector>
#include <initializer_list>
#include <cmath>

using namespace std;

struct Point {
  int x, y;
  Point(int _x, int _y) : x(_x), y(_y) {};
};
struct Polynomial {
  std::vector<int> coefs;
  Polynomial(std::initializer_list<int> l){
    coefs.insert(coefs.end(), l.begin(), l.end());
  }
  int operator()(int x) {
    int e = coefs.size()-1;
    int res = 0;
    for (int i=0; i < coefs.size(); ++i) {
      res += coefs[i]*pow(x, e);
      --e;
    }
    return res;
  }
};
std::ostream & operator << (std::ostream &os, const Polynomial &p) {
  int e = p.coefs.size()-1;
  if (p.coefs.front() != 1) os << p.coefs.front() << '*';
  os << "x^"<< e--;
  for ( int i = 1; i < p.coefs.size() - 1; ++i ) {
    if (p.coefs[i] != 0) {
      string sign = p.coefs[i] < 0 ? " - " : " + ";
      os << sign;
      if ( abs(p.coefs[i]) != 1 ) os << abs(p.coefs[i]) << '*';
      if ( e != 1 ) os  << "x^" << e;
      else os << "x"; 
      --e;
    }
  }
  if (p.coefs.back() != 0) {
    string sign = p.coefs.back() < 0 ? " - " : " + ";
    os << sign << abs(p.coefs.back());
  }
  return os;
}

/**
 * Returns a Polynomial object representing the derivative of f
 */
Polynomial derive( Polynomial f ) {
  f.coefs.pop_back();
  int e = f.coefs.size();
  for (int i = 0; i < e; ++i) {
    f.coefs[i] *= e;
    --e;
  }
  return f;
}

Polynomial tan_line( Polynomial f, Point pt ) {
}
