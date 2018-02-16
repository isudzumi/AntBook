#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

constexpr int max_n = 100000;
int n;
int s[max_n], t[max_n];
pair<int, int> itv[max_n];

int main(int argc, char const* argv[]) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  for (int i = 0; i < n; i++) {
    itv[i].first = t[i];//終了時刻をfirstに
    itv[i].second = s[i];
  }

  // first(終了時刻)の早い順にソート
  sort(itv, itv + n);

  int ans = 0, t = 0;
  for (int i = 0; i < n; i++) {
    if (t < itv[i].second) {
      ++ans;
      t = itv[i].first;
    }
  }

  cout << ans << endl;

  return 0;
}
