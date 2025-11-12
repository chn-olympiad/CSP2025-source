#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m, k;
constexpr int N = 2e6 + 10;
int f[N], c[20][N];

struct Edge{
	int u, v, w;
	int id;
}e[N];

int find(const int &x){
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool cmp(const Edge &x, const Edge &y){
	return x.w < y.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	bool IsA = true;
	for(int i = 1; i <= n; ++i)
		f[i] = i;
	for(int i = 1; i <= m; ++i)
		cin >> e[i].u >> e[i].v >> e[i].w, e[i].id = 0;
	for(int i = 1; i <= k; ++i){
		cin >> c[i][0];
		if(c[i][0])
			IsA = false;
		bool Is0 = false;
		for(int j = 1; j <= n; ++j)
			cin >> c[i][j], c[i][j] += c[i][0], Is0 = Is0 || !c[i][j];
		IsA = IsA && Is0;
	}
	if(k == 0){
//		cout << 1;
		sort(e + 1, e + m + 1, cmp);
		int cnt = 0;
		ll res = 0;
		for(int i = 1; i <= m; ++i){
			int fu = find(e[i].u);
			int fv = find(e[i].v);
			if(fu != fv){
				f[fu] = fv;
				cnt++;
				res += e[i].w;
				if(cnt == n - 1)
					break;
			}
		}
		cout << res << '\n';
	}
	else if(IsA){
		vector <int> free(k + 1);
		for(int i = 1; i <= k; ++i){
			for(int j = 1; j <= n; ++j){
				if(!c[i][j])
					free[i] = j;
			}
		}
		int cnt = 0;
		for(int i = 1; i <= k; ++i){
			for(int j = 1; j <= n; ++j){
				if(j == free[i])
					continue;
				e[m + ++cnt] = Edge{free[i], j, c[i][j]};
			}
		}
		sort(e + 1, e + m + cnt + 1, cmp);
		ll res = 0;
		int Edgecnt = 0;
		for(int i = 1; i <= m + cnt; ++i){
			int fu = find(e[i].u);
			int fv = find(e[i].v);
			if(fu != fv){
				f[fu] = fv;
				Edgecnt++;
				res += e[i].w;
				if(Edgecnt == n - 1)
					break;
			}
		}
		cout << res;
	}
	else if(n <= 1000){
		int cnt = 0;
		for(int i = 1; i <= k; ++i)
			for(int l = 1; l <= n; ++l)
				for(int j = l + 1; j <= n; ++j)
					e[m + ++cnt] = Edge{l, j, c[k][l] + c[k][j] + c[k][0], i};
		vector <bool> vis(k + 1);
		sort(e + 1, e + m + cnt + 1, cmp);
		int EdgeCnt = 0;
		ll res = 0;
		for(int i = 1; i <= m + cnt; ++i){
			int fu = find(e[i].u);
			int fv = find(e[i].v);
			if(fu != fv){
				f[fu] = fv;
				EdgeCnt++;
				res += e[i].w;
				if(e[i].id){
					if(vis[e[i].id])
						res -= c[e[i].id][0];
					vis[e[i].id] = true;
				}
				if(EdgeCnt == n - 1)
					break;
			}
		}
		cout << res << '\n';
	}
}