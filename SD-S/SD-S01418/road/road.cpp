#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000005;
int f[500005], n, m, k;
struct node{
	int u, v, w;
}e[N], e2[N];
int a[100005][20], c[200];
bool cmp(node x, node y){
	return x.w < y.w;
}
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) f[i] = i;
	for(int i = 1; i <= m; i ++){
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	//	cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1, e + m + 1, cmp);
	int ans = 0;
	if(k == 0){
		for(int i = 1; i <= m; i ++){
			int fu = find(e[i].u), fv = find(e[i].v);
			if(fu == fv) continue;
			f[fu] = fv;
			ans += e[i].w;
		}
		cout << ans ;
		return 0;
	}
	int flg = 0;
	for(int j = 1; j <= k; j ++){
		cin >> c[j];
		if(c[j]) flg = 1;
		for(int i = 1; i <= n; i ++){
			scanf("%lld", &a[i][j]);
			//if(a[i][j]) flg = 1;
		}
	}
	if(! flg){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				int w = 1e18;
				for(int d = 1; d <= k; d ++){
					w = min(w, a[i][d] + a[j][d]);
				}
				e[++ m] = {i, j, w};
			}
		}
		sort(e + 1, e + m + 1, cmp);
		for(int i = 1; i <= m; i ++){
			int fu = find(e[i].u), fv = find(e[i].v);
			if(fu == fv) continue;
			f[fu] = fv;
			ans += e[i].w;
		}
		cout << ans ;
		return 0;
	}int m2 = m;ans = 1e18;
	int hh = (1 << k);
	for(int t = 0; t < hh; t ++){
		int s = 0;
		m2 = m;
		for(int i = 1; i <= m; i ++){
			e2[i] = e[i];
		}
		for(int g = 0; g < k; g ++){
			if((t >> g) & 1) s += c[g + 1];
		}
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				int w = 1e18;
				for(int g = 0; g < k; g ++){
					if((t >> g) & 1) {
						w = min(w, a[i][g + 1] + a[j][g + 1]);
					}
				}	
				e2[++ m2] = {i, j, w};
			}
		}
		for(int i = 1; i <= n; i ++) f[i] = i;
		sort(e2 + 1, e2 + m2 + 1, cmp);
		for(int i = 1; i <= m2; i ++){
			int fu = find(e2[i].u), fv = find(e2[i].v);
			if(fu == fv) continue;
			f[fu] = fv;
			s += e2[i].w;
		}
		ans = min(ans, s);
	}
	cout << ans << endl;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
