#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 5;
constexpr int M = 5e6 + 5;
constexpr int B = 24;

int n, q, cnt_L, cnt_R, tongl[N], tongr[N];
int cntbl, cntbr, fl[M], fr[M];
array<int, 27> toL[M];
array<int, 27> toR[M];


string s[2][N], tmp, s0, s1;

vector<int> vecL[M], vecR[M];

bitset<N> bitl, bitr;
bitset<N> bitll[N / B + 5], bitrr[N / B + 5];

void insertL(string str, int i) {
  reverse(str.begin(), str.end());
  int u = 0;
  int len = static_cast<int>(str.size());
  for (int i = 0; i < len; ++i) {
    int x = str[i] - 'a';
    if (!toL[u][x]) toL[u][x] = ++cnt_L;
    u = toL[u][x];
  }
  vecL[u].push_back(i);
}

void insertR(const string& str, int i) {
  int u = 0;
  int len = static_cast<int>(str.size());
  for (int i = 0; i < len; ++i) {
    int x = str[i] - 'a';
    if (!toR[u][x]) toR[u][x] = ++cnt_R;
    u = toR[u][x];
  }
  vecR[u].push_back(i);
}

void checkL(int u) {
  for (int x : vecL[u]) {
    bitl[x] = true;
  }
  if (vecL[u].size() > B) {
    fl[u] = ++cntbl;
    bitll[fl[u]] = bitl;
  }
  for (int i = 0; i < 27; ++i) {
    if (toL[u][i]) {
      checkL(toL[u][i]);
    }
  }
  for (int x : vecL[u]) {
    bitl[x] = false; 
  }
}

void checkR(int u) {
  for (int x : vecR[u]) {
    bitr[x] = true;
  }
  if (vecR[u].size() > B) {
    fr[u] = ++cntbr;
    bitrr[fr[u]] = bitr;
  }
  for (int i = 0; i < 27; ++i) {
    if (toR[u][i]) {
      checkR(toR[u][i]);
    }
  }
  for (int x : vecR[u]) {
    bitr[x] = false; 
  }
}
vector<int> tmppp;

void queryL(string str) {
  reverse(str.begin(), str.end());
  bitl.reset();
  int u = 0;
  int lst = 0;
  int len = static_cast<int>(str.size());
  tmppp.clear();
  for (int i = 0; i < len; ++i) {
    if (fl[u]) {
      lst = fl[u], tmppp.clear();
    } else if (!vecL[u].empty()) {
      tmppp.push_back(u);
    }
    int x = str[i] - 'a';
    if (!toL[u][x]) break;
    u = toL[u][x];
  }
  if (fl[u]) {
    lst = fl[u], tmppp.clear();
  } else if (!vecL[u].empty()) {
    tmppp.push_back(u);
  }
  bitl = bitll[lst];
  for (int x : tmppp) {
    for (int y : vecL[x]) {
      bitl[y] = true;
    }
  }
}

void queryR(const string& str) {
  bitr.reset();
  int u = 0;
  int lst = 0;
  int len = static_cast<int>(str.size());
  tmppp.clear();
  for (int i = 0; i < len; ++i) {
    if (fr[u]) {
      lst = fr[u], tmppp.clear();
    } else if (!vecR[u].empty()) {
      tmppp.push_back(u);
    }
    int x = str[i] - 'a';
    if (!toR[u][x]) break;
    u = toR[u][x];
  }
  if (fr[u]) {
    lst = fr[u], tmppp.clear();
  } else if (!vecR[u].empty()) {
    tmppp.push_back(u);
  }
  bitr = bitrr[lst];
  for (int x : tmppp) {
    for (int y : vecR[x]) {
      bitr[y] = true;
    }
  }
}

int main() {
  assert(freopen("replace.in", "r", stdin));
  assert(freopen("replace.out", "w", stdout));
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> s[0][i] >> s[1][i];
    int len = static_cast<int>(s[0][i].size());
    int l = 0;
    while (l < len && s[0][i][l] == s[1][i][l]) ++l;
    insertL(s[0][i].substr(0, l), i);

    tmp.clear();
    int r = len - 1;
    while (r >= 0 && s[0][i][r] == s[1][i][r]) {
      tmp.push_back(s[0][i][r]);
      --r;
    }
    tmp.push_back('a' + 26);
    while (r >= l) {
      tmp.push_back(s[0][i][r]);
      tmp.push_back(s[1][i][r]);
      --r;
    }
    reverse(tmp.begin(), tmp.end());
    insertR(tmp, i);
  }

  checkL(0);
  checkR(0);

  while (q--) {
    cin >> s0 >> s1;
    int len = static_cast<int>(s0.size());
    int l = 0;
    while (l < len && s0[l] == s1[l]) ++l;
    queryL(s0.substr(0, l));

    tmp.clear();
    int r = len - 1;
    while (r >= 0 && s0[r] == s1[r]) {
      tmp.push_back(s0[r]);
      --r;
    }
    tmp.push_back('a' + 26);
    while (r >= l) {
      tmp.push_back(s0[r]);
      tmp.push_back(s1[r]);
      --r;
    }
    reverse(tmp.begin(), tmp.end());
    queryR(tmp);
    cout << (bitl & bitr).count() << '\n';
  }
  return 0;
}