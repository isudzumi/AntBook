#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include "vector_util.h"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::cin >> a;

  int ans = 0;

  for (auto i = a.cbegin(); i != a.cend(); ++i) {
    for (auto j = i + 1; j != a.cend(); ++j) {
      for (auto k = j + 1; k != a.cend(); ++k) {
        int len = *i + *j + *k;
        int max = std::max(*i, std::max(*j, *k));
        int rest = len - max;

        if (max < rest) {
          ans = std::max(ans, len);
        }
      }
    }
  }

  std::cout << ans << std::endl;
}
