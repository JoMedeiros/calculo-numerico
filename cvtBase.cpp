#include <string>
#include <cmath>

std::string cvtBase(std::string num)
{
  int base1 = 3;
  int base2 = 5;
  std::string res = "";
  char * algs = {'0', '1', '2', '3','4'}
  int alg = 0;
  int exp = 0;

  for (int i=num.size()-1; i >= 0; --i)
  {
    char c = num[i]; // -48 dá o número
    alg += c - 48;

    if (alg > base2){
      res.insert(0,algs[alg%base2];
      alg /= base2;
    }
    
  }

  return res;
}



int main()
{
  return 0;
}
