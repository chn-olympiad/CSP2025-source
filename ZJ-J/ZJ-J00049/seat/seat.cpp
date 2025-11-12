# include <bits/stdc++.h>

using namespace std;

const long long N = 100 + 10;

struct node {
  long long x;
  long long w;
};

node a[N];
long long n, m, pos, cnt;

inline bool cmp (node x, node y) {
  return x.w > y.w;
}

inline void dfs (long long x, long long y, bool lim) {
  cnt ++;
  if (cnt == pos) {
  	cout << x << " " << y << '\n';
  	return ;
  }
  if (lim == 0) {
  	if (y != n) dfs (x, y + 1, 0);
  	else dfs (x + 1, n, 1);
  }
  else if (lim == 1) {
  	if (y != 1) dfs (x, y - 1, 1);
  	else dfs (x + 1, 1, 0);
  }
  return ;
}

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("seat.in", "r", stdin);
  freopen ("seat.out", "w", stdout);
  
  cin >> n >> m;
  
  for (int i = 1; i <= n * m; i ++)
    cin >> a[i].w,
    a[i].x = i;
  sort (a + 1, a + n * m + 1, cmp);
  
  for (int i = 1; i <= n * m; i ++)
  	if (a[i].x == 1) {pos = i; break;}
  dfs (1, 1, 0);
  return 0;
}

