/**
 * 二部グラフ判定
 */
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define list first
#define color second

bool dfs(vector<pair<vector<int>, int>>& G, int v, int c) {  // 深さ優先探索
  G[v].color = c;
  for (auto& i : G[v].list) {  // i : vに隣接するノード
    if (G[i].color == c) {
      return false;
    }
    if (G[i].color == 0 && !dfs(G, i, -c)) {
      return false;
    }
  }
  return true;
}

int main(int argc, char const* argv[]) {
  // 隣接リストを用いて無向グラフの入力
  int V, E;
  cin >> V >> E;
  // pair<隣接するノードのリスト, ノードの色(c, -c)>
  vector<pair<vector<int>, int>> G(V);  // vector「の」配列を作成する

  for (size_t i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    G[s].list.push_back(t);
    G[t].list.push_back(s);
  }

  // 隣接リスト表示
  int num = 0;
  for (auto&& i : G) {
    cout << num << ':';
    for (auto&& j : i.list) {
      cout << " " << j;
    }
    cout << endl;
    ++num;
  }

  for (int i = 0; i < V; ++i) {
    if (G[i].color == 0) {
      if (!dfs(G, i, 1)) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
