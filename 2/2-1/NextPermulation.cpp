#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  int perm[n];
  for (int i = 0; i < n; i++) {
    perm[i] = i;
  }

  do {
    for (auto&& i : perm) {
      cout << i << " ";
    }
    cout << endl;
  } while (next_permutation(perm, perm + n));

  return 0;
}
