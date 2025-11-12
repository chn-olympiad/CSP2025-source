#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pt pair <int, int>
using namespace std;
const int N = 2e6 + 10;
int n, m, k, maxn = 1e18;
bool Aflg = 1, Bflg = 1;
int ma[15][N], fa[N], vis[15];
vector <pt> e[N];
struct edge {
	int u, v, d;
} eg[N], teg[N], tt[N];
int df = 0;
inline bool cmp(edge x, edge y) {
	return x.d < y.d;
}
inline int find(int x) {
	df++;
	if(x == fa[x]) {
		return x;
	}
	return fa[x] = find(fa[x]);
}
inline int prt() {
	int cm = m, ck = 0;
	int ans = 0, cnt = 0;
	for(int i = 1; i <= n + k + 1; i++) {
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++) {
		eg[i] = teg[i];
		df++;
	}
	for(int i = 1; i <= k; i++) {
		if(vis[i]) {
			++ck;
			for(int j = 2; j <= n + 1; j++) {
				eg[++cm].u = n + ck;
				eg[cm].v = j - 1;
				eg[cm].d = ma[i][j];
			}
			ans += ma[i][1];
//			cout << ck << endl;
		}
	}
//	cout << cm << " " << ck << " ";
	sort(eg + m + 1, eg + cm + 1, cmp);
	int id1 = 1, id2 = m + 1;
	for(int i = 1; i <= cm; i++){
		if(id1 > m){
			tt[i] = eg[id2];
			id2++;
			continue;
		}
		if(id2 > cm){
			tt[i] = eg[id1];
			id1++;
			continue;
		}
		if(eg[id1].d <= eg[id2].d){
			tt[i] = eg[id1];
			id1++;
		}else{
			tt[i] = eg[id2];
			id2++;
		}
	}
	for(int i = 1; i <= cm; i++){
		eg[i] = tt[i];
	}
//	cout << m << " " << cm  << " " << n  << " "<< k  << " " << cm - m<< endl;
	for(int i = 1; i <= cm; i++) {
		df++;
		if(find(eg[i].u) != find(eg[i].v)) {
			fa[find(eg[i].u)] = fa[find(eg[i].v)];
			ans += eg[i].d;
			cnt++;
		}
		if(cnt == n + ck - 1) {
			return ans;
		}
	}
}
inline void dfs(int now) {
	if(now == k + 1) {
		maxn = min(prt(), maxn);
		return;
	}
	vis[now] = 1;
	dfs(now + 1);
	
	vis[now] = 0;
	dfs(now + 1);
}
signed main() {
//	int tim = time(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n + k + 1; i++) {
		fa[i] = i;
	}
	if(k > 0) Bflg = 0;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		eg[i].u = u, eg[i].v = v, eg[i].d = w;
//		e[u].push_back(v, w);
//		e[v].push_back(u, w);
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n + 1; j++) {
			cin >> ma[i][j];
		}
		if(ma[i][1] != 0) {
			Aflg = 0;
		}
	}
	sort(eg + 1, eg + m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		teg[i] = eg[i];
	}
	if(Bflg) {
		cout << prt() << endl;
		return 0;
	}
	if(Aflg) {
		for(int i = 1; i <= k; i++) {
			vis[i] = 1;
		}
		cout << prt() << endl;
		return 0;
	}
	dfs(1);
	cout << maxn << endl;
//	cout << df << endl;
//	cout << time(0) - tim << endl;
	return 0;
}


/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
