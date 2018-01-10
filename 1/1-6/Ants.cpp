#include <algorithm>
#include <iostream>
#include <vector>
#include "vector_util.h"
using namespace std;

int main() {
  int L, n;
  cin >> L >> n;
  vector<int> v(n);
  cin >> v;

  // min time
  int minT = 0;
  for (const auto i : v) {
    minT = max(minT, min(i, L - i));
  }

  // max time
  int maxT = 0;
  for (const auto i : v) {
    maxT = max(maxT, max(i, L - i));
  }

  cout << "min = " << minT << endl;
  cout << "max = " << maxT << endl;

  return 0;
}
