#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
using ll = long long;
constexpr ll N = 1e5 + 5, inf = 3e4;
ll a[N][4], ch[N], cnt[N], b[N], top, n;
void work() {
  cin >> n;
  top = 0;
  fo(i, 1, 3) cnt[i] = 0;
  fo(i, 1, n) b[i] = -inf;
  fo(i, 1, n) fo(j, 1, 3) cin >> a[i][j];
  fo(i, 1, n) fo(j, 1, 3) if (a[i][j] > a[i][ch[i]]) ch[i] = j;
  ll sum = 0, mx = 1;
  fo(i, 1, n) {
    cnt[ch[i]]++;
    if (cnt[ch[i]] > cnt[mx])  mx = ch[i];
  }
  fo(i, 1, n) sum += a[i][ch[i]];
  if (cnt[mx] <= n / 2)  return cout << sum << "\n", void();
  int delt = cnt[mx] - n / 2;
//  cerr << delt << "del";
  fo(i, 1, n) {
    if (ch[i] != mx) continue;
    b[++top] = -inf;
    fo(j, 1, 3) {
      if (j != mx)
        b[top] = max(b[top], a[i][j] - a[i][ch[i]]);
    }
  }
  sort(b + 1, b + top + 1, greater<int>());
  fo(i, 1, delt)  sum += b[i];
  cout << sum << "\n";
}
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    work();
  return 0;
}

