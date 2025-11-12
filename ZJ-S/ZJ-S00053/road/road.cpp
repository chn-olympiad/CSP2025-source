# include <bits/stdc++.h>

# define int long long
# define rint register int

using namespace std;

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 1000;

struct edge {
  int u, v, w;
};

//vector <node> e[(M + K * N) << 1];
edge x[(M + K * N) << 1];
int n, m, k;
int fa[N], c[N];
int a[20][N];


inline bool cmp  (edge x, edge y) {
  return x.w < y.w;
}

inline int find (int x) {
  if (fa[x] == x) return x;
  return fa[x] = find (fa[x]);
}

inline void work () {
  int cnt = 0, sum = 0;
  for (rint i = 1; i <= m; i ++) {
  	int xx = find (x[i].u), yy = find (x[i].v);
  	if (xx != yy) {
  	  fa[xx] = yy;
  	  cnt ++,
  	  sum = sum + x[i].w;
	}
	if (cnt == n - 1) break;
  }
  cout << sum << endl;
  return ;
}

inline void solve () {
  for (rint i = 1; i <= k; i ++)
  	for (rint j = 1; j < n; j ++) {
  	  for (rint p = j + 1; p <= n; p ++) {
         int w = a[i][j] + a[i][p];
         x[++ m].u = j,
         x[m].v = p,
         x[m].w = w;
      }
	}
  return ;
}

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("road.in", "r", stdin);
  freopen ("road.out", "w", stdout);
  
  cin >> n >> m >> k;

  for (rint i = 1; i <= n; i ++) fa[i] = i;  
  for (rint i = 1; i <= m; i ++)
  	cin >> x[i].u >> x[i].v >> x[i].w;

  for (rint i = 1; i <= k; i ++) {
  	cin >> c[i];
  	for (rint j = 1; j <= n; j ++)
  	  cin >> a[i][j];
  }
  
  solve ();
  
  for (rint i = 1; i <= m; i ++)
	x[i + m].u = x[i].v,
  	x[i + m].v = x[i].u,
  	x[i + m].w = x[i].w;  	  	
  m = m * 2;
  
  
  sort (x + 1, x + m + 1, cmp);

  work ();


  return 0;
}

