#include <iostream>
using namespace std;

int memo[100] = {};

int fib(int n) {
  if (n <= 1) {
    return n;
  } else if (memo[n] != 0) {
    return memo[n];
  } else {
    return memo[n] = fib(n - 1) + fib(n - 2);
  }
}

int main(int argc, char const* argv[]) {
    fib(40);
    for (auto&& i : memo) {
        cout << i << " ";
    }
    cout << endl;
  return 0;
}
