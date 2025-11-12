#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin (), (x).end ()
#define vec vector 
#define MAXN 100005
#define pii pair <int, int>

template <typename T> inline void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) { x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar (); }
	x *= f;	
}

template <typename T, typename ...Arp> inline void read (T &x, Arp &...arp) {
	read (x), read (arp...);
}

int T, n;
pii a[MAXN][4];
vec <pii> cnt[4];

void init () {
	for (int i = 1; i <= 3; ++i) cnt[i].clear ();
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	read (T);
	while (T--) {
		init (), read (n);
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j)
				read (a[i][j].x), a[i][j].y = j;
			sort (a[i] + 1, a[i] + 4);
		}
		
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += a[i][3].x; 		
			cnt[a[i][3].y].pb ({a[i][3].x - max (a[i][1].x, a[i][2].x), i});
		}
		
		int x = 0;
		for (int i = 1; i <= 3; ++i) 
			if (cnt[i].size () > n / 2) {
				x = i; break;
			}
			
		if (!x) {
			printf ("%d\n", ans);
			continue;
		}
		
		sort (all (cnt[x]));
		
		for (int i = 0; i < cnt[x].size () - n / 2; ++i)
			ans -= cnt[x][i].x;
		printf ("%d\n", ans);
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/ 