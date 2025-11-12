#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

namespace My {
constexpr int N = 1e5 + 5;
struct D {
  int no, club, v;
  bool taken;
} a[3][N];
struct Delta {
  int i, v;
} delta[N];
int n, cnt[3], lim;
bool taken[N];

bool operator<(const D& x, const D& y) {
  return x.v < y.v;
}

int conf(int peak) {
  int target = -1;
  for (int i = 1; i <= 2; ++i) {
    if (cnt[(peak + i) % 3] < lim) {
      target = (peak + i) % 3;
      break;
    }
  }
  if (target == -1) return 0;
  for (int i = 1; i <= n; ++i) {
    if (a[peak][i].taken)
      delta[i] = {i, a[target][i].v - a[peak][i].v};
    else
      delta[i] = {i, INT_MIN};
  }
  sort(delta + 1, delta + 1 + n, [](const Delta& x, const Delta& y) {
    return x.v > y.v;
  });
  int num = cnt[peak] - lim, ret = 0;
  for (int i = 1; i <= num; ++i) {
    ret += delta[i].v;
  }
  cnt[target] += num, cnt[peak] -= num;
  return ret;
}

int solve0() {
	for (int i = 0; i < 3; ++i) {
	  sort(a[i] + 1, a[i] + 1 + n, [](const D& x, const D& y) {
      return x.v > y.v;
    });
  }
  for (int i = 0; i < 3; ++i) cnt[i] = 0;
  int idx[3] = {1, 1, 1}, ans = 0;
  while (idx[0] <= n || idx[1] <= n || idx[2] <= n) {
    D cur = {0, -1, -1, 0};
    for (int i = 0; i < 3; ++i) {
      if (idx[i] > n) break;
      while (taken[a[i][idx[i]].no]) idx[i]++;
    }
    if (idx[0] > n && idx[1] > n && idx[2] > n) break;
    for (int i = 0; i < 3; ++i) {
      if (idx[i] > n) break;
      cur = max(cur, a[i][idx[i]]);
    }
    ans += cur.v;
    idx[cur.club]++;
    cnt[cur.club]++;
    taken[cur.no] = 1;
    a[cur.club][cur.no].taken = 1;
  }
  if (cnt[0] > lim) ans += conf(0);
  if (cnt[1] > lim) ans += conf(1);
  if (cnt[2] > lim) ans += conf(2);
  return ans;
}

int solveA() {
  int ans = 0;
  sort(a[0] + 1, a[0] + 1 + n, [](const D& x, const D& y) {
    return x.v > y.v;
  });
  int to = n >> 1;
  for (int i = 1; i <= to; ++i) ans += a[0][i].v;
  return ans;
}

int conf2(int peak, int target) {
  for (int i = 1; i <= n; ++i) {
    if (a[peak][i].taken)
      delta[i] = {i, a[target][i].v - a[peak][i].v};
    else
      delta[i] = {i, INT_MIN};
  }
  sort(delta + 1, delta + 1 + n, [](const Delta& x, const Delta& y) {
    return x.v > y.v;
  });
  int num = cnt[peak] - lim, ret = 0;
  for (int i = 1; i <= num; ++i) {
    ret += delta[i].v;
  }
  cnt[target] += num, cnt[peak] -= num;
  return ret;
}

int solveB() {
	for (int i = 0; i < 2; ++i) {
	  sort(a[i] + 1, a[i] + 1 + n, [](const D& x, const D& y) {
      return x.v > y.v;
    });
  }
  for (int i = 0; i < 2; ++i) cnt[i] = 0;
  int idx[2] = {1, 1}, ans = 0;
  while (idx[0] <= n || idx[1] <= n) {
    while (taken[a[0][idx[0]].no]) idx[0]++;
    while (taken[a[1][idx[1]].no]) idx[1]++;
    if (idx[0] > n && idx[1] > n) break;
    D cur = max(a[0][idx[0]], a[1][idx[1]]);
    ans += cur.v;
    idx[cur.club]++;
    cnt[cur.club]++;
    taken[cur.no] = 1;
    a[cur.club][cur.no].taken = 1;
  }
  if (cnt[0] > lim) ans += conf2(0, 1);
  if (cnt[1] > lim) ans += conf2(1, 0);
  return ans;
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
  	cin >> n;
  	lim = n >> 1;
  	memset(taken + 1, 0, n * sizeof(*taken));
  	bool aa = 1, ab = 1;
  	// todo
  	for (int i = 1; i <= n; ++i) for (int j = 0; j < 3; ++j) {
  	  a[j][i] = {i, j, 0, 0};
  	  cin >> a[j][i].v;
  	  if (j == 1 && a[j][i].v) aa = 0;
  	  if (j == 2 && a[j][i].v) aa = ab = 0;
    }
    cout << (aa ? solveA() : ab ? solveB() : solve0()) << '\n';
  }
}

}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	My::solve();
	return 0;
}

