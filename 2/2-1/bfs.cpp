/**
 * 迷路の最短経路
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

using P = pair<int, int>;
#define x first
#define y second

int n, m;
const int INF = 100000000;
char a[100][100];
int d[100][100];  //最短距離の配列
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
P s, g;

int bfs() {
  queue<P> que;
  // 初期化
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = INF;
    }
  }

  que.push(s);
  d[s.x][s.y] = 0;

  while (que.size()) {
    P p = que.front();
    que.pop();

    if (p.x == g.x && p.y == g.y) {
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nx = p.x + dx[i], ny = p.y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' &&
          d[nx][ny] == INF) {
        que.push(make_pair(nx, ny));
        d[nx][ny] = d[p.x][p.y] + 1;
      }
    }
  }

  return d[g.x][g.y];
}

int main(int argc, char const* argv[]) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        s = make_pair(i, j);
      } else if (a[i][j] == 'G') {
        g = make_pair(i, j);
      }
    }
  }

  int res = bfs();
  cout << res << endl;

  return 0;
}
