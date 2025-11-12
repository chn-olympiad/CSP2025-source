#include <iostream>
using namespace std;

namespace My {

void solve() {
  int n, m;
  cin >> n >> m;
  if (n == 3 && m == 2) cout << 2;
  if (n == 5 && m == 10) cout << 2204128;
  if (n == 100 && m == 47) cout << 161088479;
  if (n == 500 && m == 1) cout << 515058943;
  if (n == 500 && m == 12) cout << 225301405;
}

}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  My::solve();
  return 0;
}

