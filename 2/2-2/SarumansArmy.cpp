#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, R;
  cin >> N >> R;
  int X[N];
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }

  sort(X, X + N);

  int i = 0, ans=0;
  while (i < N) {
    int s = X[i++];
    while (i < N && X[i] <= s + R) {
      ++i;
    }
    int p = X[i - 1];  // X[0]から最もRに近い点
    while (i < N && X[i] <= p + R) {
      ++i;
    }
    ++ans;
  }
  cout << ans << endl;
}
