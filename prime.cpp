#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> printPrimesBetween(int m, int n);

int main(int argc, char *argv[]) {
  int t;
  cin >> t;

  int n, m;
  vector<vector<int> > primes_between;
  for (int i = 0; i < t; i++) {
    cin >> m >> n;
    primes_between.push_back(printPrimesBetween(m, n));
  }
  
  for (int i = 0; i < primes_between.size(); i++) {
    for(int j = 0; j < primes_between[i].size(); j++)
      cout << primes_between[i][j] << endl;
    cout << endl;
  }

}

vector<int> printPrimesBetween(int m, int n) {
  vector<int> primes_between;

  if(m == 1)
    m = 2;
  for (int i = m; i <= n; i++) {
    bool flag = false;
    for (int j = 2; j <= sqrt(i) && !flag; j++) {
      if (i % j == 0)
	flag = true;
    }
    
    if (!flag)
      primes_between.push_back(i);
  }
  
  return primes_between;
}
