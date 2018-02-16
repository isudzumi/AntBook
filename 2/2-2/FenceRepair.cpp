#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int L[N];
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  ll ans = 0;

  while (N > 1) {
    // mii1:最短の板, mii2:次に短い板
    int mii1 = 0, mii2 = 1;
    if (L[mii1] > L[mii2]) {
      swap(mii1, mii2);
    }

    // L[N]の中で最も小さい2数を見つける
    for (int i = 2; i < N; i++) {
      if (L[i] < L[mii1]) {
        mii2 = mii1;
        mii1 = i;
      } else if (L[i] < L[mii2]) {
        mii2 = i;
      }
    }

    // 最も深いノードを足し合わせる
    int t = L[mii1] + L[mii2];
    ans += t;

    if (mii1 == N - 1) {
      swap(mii1, mii2);
    }
    // L[N-1]の配列を作る
    L[mii1] = t;
    L[mii2] = L[N - 1];
    --N;
  }

  cout << ans << endl;
}
