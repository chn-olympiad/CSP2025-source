#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
struct Node{
	int u, v, w;
	int id;
} a[N], b[N];
int cnt = 0;
struct Point{
	int v, to[10005];
} c[15];
int fa[10005];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
pair <int, int> G[N];
bool flag[N], vis[N];
//int dis[N];
//map <std::pair <int, int>, std::pair <int, int> > mp;

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		a[++cnt] = {u, v, w};
	}
	for(int i = 1; i <= k; ++i){
		cin >> c[i].v;
		for(int j = 1; j <= n; ++j){
			cin >> c[i].to[j];
		}
	}
	sort(a + 1, a + cnt + 1, [](Node x, Node y){
		return x.w < y.w;
	});
	for(int i = 1; i <= n; ++i) fa[i] = i;
	int tot = 0;
	int ans = 0;
	for(int i = 1; i <= m; ++i){
		int u = find(a[i].u), v = find(a[i].v), w = a[i].w;
		if(u != v){
			fa[u] = v;
			ans += w;
			b[++tot] = {a[i].u, a[i].v, w, 0};
			if(a[i].u > a[i].v) swap(a[i].u, a[i].v);
//			mp[{a[i].u, a[i].v}] = {w, 0};
			if(tot == n - 1) break;
		}
	}
	if(k == 0) cout << ans << '\n';
//	else if(n <= 1e3){
//		for(int i = 1; i <= n; ++i){
//			for(int j = i + 1; j <= n; ++j){
//				for(int x = 1; x <= k; ++x){
//					int tmp = c[x].to[i] + c[x].to[j] + c[x].v;
//					if(mp.count({i, j})){
//						int tmp2 = mp[{i, j}].first;
//						if(tmp2 > tmp) mp[{i, j}] = {tmp, x};
//					} else {
//						mp[{i, j}] = {tmp, x};
//					}
//				}
//			}
//		}
//		int now = 1;
//		vis[now] = 1;
//		int res = 0, side = 0;
//		while(side != n - 1){
//			int dist = 1e18;
//			int to = 0;
//			for(int i = 1; i <= n; ++i){
//				if(i != now && !vis[i]){
//					int tmp = 0;
//					if(now > i) swap(now, i), tmp = 1;
//					if(mp[{now, i}].first - flag[mp[{now, i}].second] * c[mp[{now, i}].second].v < dist){
//						to = tmp ? now : i, dist = mp[{now, i}].first - flag[mp[{now, i}].second] * c[mp[{now, i}].second].v;
//					}
//					if(tmp) swap(now, i);
//				}
//			}
//			res += dist;
//			flag[mp[{now, to}].second] = 1;
//			now = to;
//			side++;
//			vis[to] = 1;
//		}
//		cout << res << '\n';
//	} 
	else {
		int p = 0;
		for(int i = 1; i <= n; ++i){
			int min = 1e18, id = 0;
			for(int j = 1; j <= k; ++j){
				if(min > c[j].to[i]) min = c[j].to[i], id = j;
				else if(min == c[j].to[i]){
					if(c[j].v < c[id].v) id = j;
				}
			}
			G[++p] = {i, n + id};
		}
		sort(G + 1, G + p + 1, [](pair <int, int> x, pair <int, int> y){
			return x.second < y.second;
		});
        for(int i = 2; i <= p; ++i){
            if(G[i].second == G[i - 1].second){
				b[++tot] = {G[i].first, G[i - 1].first, c[G[i].second - n].v + c[G[i].second - n].to[G[i].first] + c[G[i].second - n].to[G[i - 1].first], G[i].second - n};
//				cout << G[i].first << ' ' << G[i - 1].first << ' ' << c[G[i].second - n].v << ' ' << c[G[i].second - n].to[G[i].first] + c[G[i].second - n].to[G[i].first] << '\n';
			}
        }
        sort(b + 1, b + tot + 1, [](Node x, Node y){
            return x.w < y.w;
        });
//        for(int i = 1; i <= tot; ++i) cout << b[i].u << ' ' << b[i].v << ' ' << b[i].w << '\n';
        for(int i = 1; i <= n; ++i) fa[i] = i;
        int sz = 0;
        ans = 0;
        flag[0] = 1;
        c[0].v = 0;
        for(int i = 1; i <= m; ++i){
            int u = find(b[i].u), v = find(b[i].v), w = b[i].w;
            if(u != v){
                if(!flag[b[i].id]) ans += c[b[i].id].v, flag[b[i].id] = 1;
                fa[u] = v;
                ans += w - c[b[i].id].v;
                sz++;
                if(sz == n - 1) break;
            }
        }
        cout << ans << '\n';
	}
	return 0;
}

