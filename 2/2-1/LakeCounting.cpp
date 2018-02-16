#include <iostream>
using namespace std;

int n, m;
char f[100][100];

void dfs(int x, int y) {
  f[x][y] = '.';
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int dx = x + i;
      int dy = y + j;
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && f[dx][dy] == 'W') {
        dfs(dx, dy);
      }
    }
  }
  return;
}

int main(int argc, char const* argv[]) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> f[i][j];
    }
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (f[i][j] == 'W') {
        dfs(i, j);
        ++ans;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
