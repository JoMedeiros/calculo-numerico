#include <vector>
#include <initializer_list>

struct Point
{
  int x, y;
  Point(int _x, int _y) : x(_x), y(_y) {};
};

struct Polynomial
{
  std::vector<int> coefs;
  Polynomial(std::initializer_list<int> l){
    coefs.insert(coefs.end(), l.begin(), l.end());
  }
/*  std::ostream operator<<( std::ostream& os )
  {
    int e = this->coefs.size() - 1;
    for ( int i = 0; i < e; ++i ) {
      if (this->coefs[i] != 0) {
        char sign = this->coefs[i] < 0 ? '-' : '+';
        os << sign << abs(this->coefs[i]) << "^" << e;
      }
    }
    if (this->coefs.back() != 0) {
      char sign = this->coefs.back() < 0 ? '-' : '+';
      os << sign << abs(this->coefs.back());
    }
    return os;
  }*/
};

std::ostream & operator << (std::ostream &os, const Polynomial &p)
{
  int e = p.coefs.size() - 1;
  os << p.coefs.front();
  for ( int i = 1; i < e; ++i ) {
    if (p.coefs[i] != 0) {
      char sign = p.coefs[i] < 0 ? '-' : '+';
      os << sign << abs(p.coefs[i]) << "x*^" << e;
    }
  }
  if (p.coefs.back() != 0) {
    char sign = p.coefs.back() < 0 ? '-' : '+';
    os << sign << abs(p.coefs.back());
  }
  return os;
}

Polynomial derive(Polynomial f)
{
  f.coefs.pop_back();
  int e = f.coefs.size() - 1;
  for (int i = 0; i < e; ++i) {
    f.coefs[i] *= e;
    --e;
  }
  return f;
}

