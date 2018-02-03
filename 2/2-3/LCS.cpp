#include <algorithm>
#include <iostream>
using namespace std;

int dp[1001][1001];

int main() {
  int n, m;
  cin >> n >> m;
  char s[n], t[m];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  cout << dp[n][m] << endl;
}
