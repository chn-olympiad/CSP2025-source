#include<bits/stdc++.h>
#pragma GCC optimize (O2)
#pragma GCC optimize (O3)
#pragma GCC optimize (1)
#pragma GCC optimize (2)
#pragma GCC optimize (3)
#pragma GCC optimize (4)
#pragma GCC optimize (5)
#pragma GCC optimize (6)
#pragma GCC optimize (7)
#pragma GCC optimize (8)
#pragma GCC optimize (9)
#pragma GCC optimize (a)
#pragma GCC optimize (b)
#pragma GCC optimize (c)
#pragma GCC optimize (d)
#pragma GCC optimize (e)
#pragma GCC optimize (f)
#pragma GCC optimize (g)
#pragma GCC optimize (h)
#pragma GCC optimize (i)
#pragma GCC optimize (j)
#pragma GCC optimize (k)
#pragma GCC optimize (l)
#pragma GCC optimize (m)
#pragma GCC optimize (n)
#pragma GCC optimize (o)
#pragma GCC optimize (p)
#pragma GCC optimize (q)
#pragma GCC optimize (r)
#pragma GCC optimize (s)
#pragma GCC optimize (t)
#pragma GCC optimize (u)
#pragma GCC optimize (v)
#pragma GCC optimize (w)
#pragma GCC optimize (x)
#pragma GCC optimize (y)
#pragma GCC optimize (z)
#define int long long
using namespace std;
const int CNM = 1e9, N = 1e4 + 21;
int n, m, k, cdi[100], c[100], vis[N], len[N], minn;
vector <int> edge[N];
int getint () {
	char ch = getchar ();
	int num = 0, fs = 1;
	while ( ( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar ();
	if (ch == '-') fs = -1, ch = getchar ();
	while ( ch >= '0' && ch <= '9' ) num = num * 10 + ch - '0', ch = getchar ();
	return num * fs;
}
void get (int t) {
	if (t > k) {
		priority_queue <int, vector <int>, greater <int> > q;
		for (int i = 1; i <= n + k ; i ++) vis[i] = 0, len[i] = 1e18;
		int smin = 0, u = 1, res = 0; vis[1] = 1;
		for (int i = 1; i <= k; i ++) {
			smin += cdi[i] * c[i];
			if (cdi[i] == 1) res ++;
		}
		if (smin >= minn) return ;
		q.push (1);
		for (int T = 1; T <= n + res - 1; T ++) {
			while (vis[q.top () % CNM] == 1 && !q.empty ()) q.pop ();
			for (int j = 0; j < edge[u].size (); j ++) {
				int d = edge[u][j] % CNM, w = edge[u][j] / CNM;
				if (vis[d] == 1) continue;
				if (d > n) {
					if (cdi[d - n] == 1) {
						if (w < len[d]) {
							len[d] = w;
							q.push (w * 1e9 + d);
						}
					}
				}
				else if (w < len[d]) {
					len[d] = w;
					q.push (w * 1e9 + d);
				}
			}
			while (vis[q.top () % CNM] == 1 && !q.empty ()) q.pop ();
			u = q.top () % CNM;
			int w = q.top () / CNM;
			if (smin >= minn) return ;
			smin += w; q.pop (); vis[u] = 1;
		}
		minn = min (smin, minn);
		return ;
	}
	get (t + 1);
	cdi[t] = 1, get (t + 1);
	cdi[t] = 0;
	return ;
}
signed main () {
	freopen ( "road.in", "r", stdin );
	freopen ( "road.out", "w", stdout );
	minn = 1e18;
	n = getint (), m = getint (), k = getint ();
	for (int i = 1; i <= m; i ++) {
		int u = getint (), v = getint (), w = getint ();
		edge[u].push_back (w * CNM + v);
		edge[v].push_back (w * CNM + u);
	}
	int tmp = 0;
	for (int i = 1; i <= k; i ++) {
		c[i] = getint (); if(c[i] == 0) tmp ++;
		for (int j = 1; j <= n; j ++) {
			int w = getint ();
			if (w == 0) tmp ++;
			edge[n + i].push_back (w * CNM + j);
			edge[j].push_back (w * CNM + n + i);
		}
	}
	if (tmp == k * (n + 1)) {
		printf ("0");
		return 0;
	}
	get ( 1 );
	printf ("%lld", minn);
	return 0;
}
