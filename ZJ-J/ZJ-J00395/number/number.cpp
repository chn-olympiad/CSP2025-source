#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  string s;
  cin >> s;
  priority_queue<int> pq;
  for (char &x : s) {
    if (x >= 48 && x <= 57) {
      pq.push(x - 48);
    }
  }
  string ans = string();
  while (!pq.empty()) {
    ans.push_back(pq.top() + '0');
    pq.pop();
  }
  cout << ans << endl;
}