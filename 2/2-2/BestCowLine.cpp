#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
  int N;
  cin >> N;
  char S[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  char T[N];

  int a = 0, b = N - 1;
  while (a <= b) {
    bool isLeft = true;
    for (int i = 0; a + i <= b; i++) {
      if (S[a + i] < S[b - i]) {
        isLeft = true;
        break;
      } else if (S[a + i] > S[b - i]) {
        isLeft = false;
        break;
      }
    }
    if (isLeft) {
      cout << S[a++];
    } else {
      cout << S[b--];
    }
  }
  cout << endl;

  return 0;
}
