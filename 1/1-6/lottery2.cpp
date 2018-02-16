#include <algorithm>
#include <iostream>
#include <vector>
#include "vector_util.h"
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  cin >> v;

  vector<int> kk(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      kk[i * n + j] = v[i] + v[j];
    }
  }

  bool f = false;
  for (auto k : v) {
    for (auto l : v) {
      if (binary_search(v.cbegin(), v.cend(), m - k - l)) {
        f = true;
        break;
      }
    }
  }
  auto ans = f ? "Yes" : "No";
  cout << ans << endl;
}
