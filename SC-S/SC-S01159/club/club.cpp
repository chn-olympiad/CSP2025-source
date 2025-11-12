#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> a2;

const int N = 1e5;
int n, ans, a[N + 1][3], b[N + 1], cnt[3];
priority_queue<a2> q[3][3];

void add(int i, int o) {
  ans += a[i][o];
  b[i] = o;
  ++cnt[o];
  q[o][1].push({a[i][(o + 1) % 3] - a[i][o], i});
  q[o][2].push({a[i][(o + 2) % 3] - a[i][o], i});
  if (cnt[o] <= n / 2) {
    return;
  }
  for (int p : {1, 2}) {
    while (b[q[o][p].top()[1]] != o) {
      q[o][p].pop();
    }
  }
  if (q[o][1].top()[0] > q[o][2].top()[0]) {
    i = q[o][1].top()[1];
    add(i, (o + 1) % 3);
  }
  else {
    i = q[o][2].top()[1];
    add(i, (o + 2) % 3);
  }
  ans -= a[i][o];
  --cnt[o];
  return;
}

void clr() {
  ans = cnt[0] = cnt[1] = cnt[2] = 0;
  for (int i : {0, 1, 2}) {
    for (int j : {1, 2}) {
      while (!q[i][j].empty()) {
        q[i][j].pop();
      }
    }
  }
  return;
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int _t;
  cin >> _t;
  while (_t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
      int mx = max({a[i][0], a[i][1], a[i][2]});
      if (a[i][0] == mx) {
        add(i, 0);
      }
      else if (a[i][1] == mx) {
        add(i, 1);
      }
      else {
        add(i, 2);
      }
    }
    cout << ans << "\n";
    clr();
  }
  return 0;
}