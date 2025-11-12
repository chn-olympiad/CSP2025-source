#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct line {
	int u , v , w;
	bool operator < (line b) const {
		return w < b.w;
	}
} l[50000005];
int n , m , k;
int fa[10015];
int b[15];
ll vis[10005];
bool z[10005];
int find(int idx) {
	return fa[idx] == 0 ? idx : fa[idx] = find(fa[idx]);
}
int g[15][10005];
vector < pair < int , int > > e[10005];

signed main() {
	
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	scanf("%d%d%d" , &n , &m , &k);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &l[i].u , &l[i].v , &l[i].w);
	}
	bool f = true;
	for (int i = 1 ; i <= k ; i++) {
		scanf("%d" , b + i);
		if (b[i] != 0)
			f = false;
		bool p = false;
		for (int j = 1 ; j <= n ; j++) {
			scanf("%d" , g[i] + j);
			if (g[i][j] == 0)
				p = true;
		}
		f = f && p;
	}
	if (k == 0) {
		sort(l + 1 , l + n + 1);
		ll sum = 0;
		for (int i = 1 ; i <= m ; i++) {
			int fs = find(l[i].u);
			int ft = find(l[i].v);
			if (fs != ft) {
				fa[ft] = fs;
				sum += l[i].w;
			}
		}
		printf("%lld" , sum);
	}
	else {
		if (f) {
			
			ll sum = 0;
			for (int i = 1 ; i <= k ; i++) {
				for (int j = 1 ; j <= n ; j++) {
					l[++m] = {n + i , j , g[i][j]};
				} 
			}
			sort(l + 1 , l + m + 1);
			for (int i = 1 ; i <= m ; i++) {
				int fs = find(l[i].u);
				int ft = find(l[i].v);
				if (fs != ft) {
					fa[ft] = fs;
					sum += l[i].w;
				}
			}
			printf("%lld" , sum);
			
			return 0;
		}
		ll ans = 9e18;
		for (int t = 0 ; t <= (1 << k) - 1 ; t++) {
			ll sum = 0;
			vector < int > v;
			vector < int > w;
			for (int i = 1 ; i <= k ; i++) {
				if (t & (1 << (i - 1))) {
					sum += b[i];
					v.push_back(i);
				}
			}
			w.push_back(1);
			z[1] = 1;
			for (int p = 2 ; p <= n + (int)v.size() ; p++) {
				for (int i = 1 ; i <= n + k ; i++)
					vis[i] = 9e18;
				for (int j : w) {
					for (auto l : e[j]) {
						if (l.first < vis[l.second]) {
							vis[l.second] = l.first;
						}
					}
					for (int l : v) {
						if (g[n + l][j] < vis[n + l]) {
							vis[n + l] = g[n + l][j];
						}
					}
				}
				int mi = 1;
				for (int i = 1 ; i <= n ; i++) {
					if (!z[i] && vis[i] < vis[mi]) {
						mi = i;
					}
				}
				for (auto i : v) {
					if (!z[n + i] && vis[n + i] < vis[mi]) {
						mi = n + i;
					}
				}
				w.push_back(mi);
				sum += vis[mi];
				z[mi] = 1;
			}
			ans = min(sum , ans);
		}
		printf("%lld\n" , ans);
	}
	
	return 0;
}
