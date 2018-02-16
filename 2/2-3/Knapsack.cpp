#include <algorithm>
#include <iostream>
using namespace std;

int dp[100 + 1][100 + 1];
int n, W;
int w[100], v[100];

int rec(int i, int j) {
  if (dp[i][j] >= 0) {
    return dp[i][j];
  }
  int res;
  if (i == n) {  //終了条件
    res = 0;
  } else if (j < w[i]) {  //入らない場合
    res = rec(i + 1, j);
  } else {  // 入れるケース、入れないケースで大きい方
    res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }
  return dp[i][j] = res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  cin >> W;

  // dp初期化
  fill(dp[0], dp[100], -1);

  cout << rec(0, W) << endl;

  return 0;
}
