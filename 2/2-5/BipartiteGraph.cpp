/**
 * 二部グラフ判定
 */
#include <iostream>
#include <vector>
using namespace std;

constexpr int n = 3;  // 頂点数
constexpr bool a[n][n] = {
    //無向グラフ
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1},
};
int color[n][n];
bool dfs(int i, int c) {  // 深さ優先探索
  color[i][0] = c;
  for (int j = 0; j < n; ++j) {
    if (color[n][j] == c) return false;
    if ((color[n][j] == 0) && !(dfs(i + 1, -c))) return false;
  }
  return true;
}

int main(int argc, char const* argv[]) {
  // initialize
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      color[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
