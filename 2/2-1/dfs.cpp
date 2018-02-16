/**
 * 部分和問題
 */
#include <iostream>
using namespace std;

int n;
int a[100] = {};
int k;

bool dfs(int i, int sum) {
  if (i == n) {
    return sum == k;
  }
  if (dfs(i + 1, sum + a[i])) {
    return true;
  }
  if (dfs(i + 1, sum)) {
    return true;
  }
  return false;
}

int main(int argc, char const* argv[]) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> k;

  cout << (dfs(0, 0) ? "Yes" : "No") << endl;

  return 0;
}
