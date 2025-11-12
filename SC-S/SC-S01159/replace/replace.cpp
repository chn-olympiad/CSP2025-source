#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5;
const int L = 5e6;
int n, q, sl[N + 1][2];
string s[N + 1][2], t[2];

namespace sub1 {

const int P[2] = {(int)1e9 + 7, (int)1e9 + 9};
const int K = 131;
int pw[L + 1][2];
vector<int> f[N + 1][2][2], g[2][2];
int ts, lne, rne;

void cal_f(string s, vector<int> f[2]) {
  for (int o : {0, 1}) {
    f[o].resize(s.size());
    for (int i = 1; i < s.size(); i++) {
      f[o][i] = ((ll)f[o][i - 1] * K + s[i]) % P[o];
    }
  }
  return;
}

bool check(int st, int x) {
  int l = sl[x][0];
  if (st + l - 1 < rne || st + l - 1 > ts) {
    return 0;
  }
  for (int o : {0, 1}) {
    int th[2], sh[2];
    th[0] = (g[0][o][st + l - 1] + P[o] - (ll)g[0][o][st - 1] * pw[l][o] % P[o]) % P[o];
    th[1] = (g[1][o][st + l - 1] + P[o] - (ll)g[1][o][st - 1] * pw[l][o] % P[o]) % P[o];
    sh[0] = f[x][0][o][l];
    sh[1] = f[x][1][o][l];
    if (th[0] != sh[0] || th[1] != sh[1]) {
      return 0;
    }
  }
  return 1;
}

void sol() {
  pw[0][0] = pw[0][1] = 1;
  for (int i = 1; i <= L; i++) {
    for (int o : {0, 1}) {
      pw[i][o] = (ll)pw[i - 1][o] * K % P[o];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int o : {0, 1}) {
      cal_f(s[i][o], f[i][o]);
    }
  }
  while (q--) {
    cin >> t[0] >> t[1];
    t[0] = " " + t[0];
    t[1] = " " + t[1];
    cal_f(t[0], g[0]);
    cal_f(t[1], g[1]);
    if (t[0].size() != t[1].size()) {
      cout << "0\n";
      continue;
    }
    ts = t[0].size() - 1;
    lne = 0;
    for (int i = 1; i <= ts; i++) {
      if (t[0][i] == t[1][i]) {
        continue;
      }
      if (!lne) {
        lne = i;
      }
      rne = i;
    }
    int cnt = 0;
    for (int i = 1; i <= lne; i++) {
      for (int j = 1; j <= n; j++) {
        if (check(i, j)) {
//          cout << i << " " << j << "*\n";
          ++cnt;
        }
      }
    }
    cout << cnt << "\n";
  }
  return;
}

}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i][0] >> s[i][1];
    sl[i][0] = s[i][0].size();
    sl[i][1] = s[i][1].size();
    s[i][0] = " " + s[i][0];
    s[i][1] = " " + s[i][1];
  }
  sub1::sol();
  return 0;
}