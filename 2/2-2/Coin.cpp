#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
  const int V[6] = {1, 5, 10, 50, 100, 500};
  int C[6] = {};
  for (auto&& i : C) {
    cin >> i;
  }
  int ans = 0;
  int A;
  cin >> A;

  for (int i = 5; i >= 0; --i) {
    int t = min(A / V[i], C[i]);
    A -= t * V[i];
    ans += t;
  }

  cout << ans << endl;

  return 0;
}
