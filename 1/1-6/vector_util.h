#include <iostream>
#include <vector>

/**
 *  vector<T> vec(n);
 *  cin >> vec;
 */
template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& x : vec) {
    is >> x;
  }
  return is;
}

/**
 * vector<T> vec(n);
 * cout << vec << endl;
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& vec) {
  for (auto itr = vec.cbegin(); itr != vec.cend(); ++itr) {
    os << *itr << (itr + 1 == vec.cend() ? "" : " ");
  }
  return os;
}

/**
 * itr_for(auto i : vec)
 */
#define for_itr(itr, vec) for (auto itr = vec.begin(); itr != vec.end(); ++itr)

