#include <bits/stdc++.h>
using namespace std;

long long n, m, k, u, v, w, ls, c[15][10005], ans, fa[10005], sumz;
struct jgt {
	long long x, y, z;
	friend bool operator < (jgt xa, jgt xb) {
		return xa.z < xb.z;
	}
};
vector <jgt> e, le;
bool A = 1;

long long fd (long long px) {
	if (fa[px] == px) return px;
	else return fa[px] = fd (fa[px]);
}

void to_le () {
	le.clear ();
	for (auto i : e)
		le.push_back (i);
} 

void to_e () {
	e.clear ();
	for (auto i : le)
		e.push_back (i);
} 

void qz () {
	for (long long i = 1; i <= n + k; i++)
		fa[i] = i;
	sort (e.begin (), e.end ());
	for (auto i : e) {
		long long fx = fd (i.x), fy = fd (i.y);
		if (fx == fy) continue ;
		else  {
//			cout << "tc : " << i.x << " " << i.y << " " << i.z << "\n";
			ans += i.z, fa[fx] = fy;
		}
	}
}

void dfs (long long px, long long ps) {
	if (px == k + 1) {
		to_e ();
		ans = ps;
		qz ();
//		cout << "ts : " << ans << " " << ps << "\n\n";
		sumz = min (sumz, ans);
		return ;
	}
	dfs (px + 1, ps);
	for (long long i = 1; i <= n; i++)
		le.push_back ({i, n + px, c[px][i]});
	dfs (px + 1, ps + c[px][0]);
	for (long long i = 1; i <= n; i++)
		le.pop_back ();
}

int main () {
	
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	
	ios :: sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		e.push_back ({u, v, w});
	}
	for (long long i = 1; i <= k; i++) {
		cin >> c[i][0];
		if (c[i][0]) A = 0;
		ls = 0;
		for (long long j = 1; j <= n; j++) {
			cin >> c[i][j];
			if (!c[i][j]) ls = 1;
		}
		if (!ls) A = 0;
	}
	
	if (A) {
		for (long long i = 1; i <= k; i++) {
			ls = 0;
			for (long long j = 1; j <= n; j++) {
				if (!c[i][j]) {
					ls = j;
					break ;
				}
			}
			for (long long j = 1; j <= n; j++)
				if (j != ls) e.push_back ({ls, j, c[i][j]});
		}
		qz ();
		cout << ans;
		return 0;
	}
	
	sumz = 1000000000000000000;
	to_le ();
	dfs (1, 0);
	
	cout << sumz;
	
	return 0;
}

/*

*/
