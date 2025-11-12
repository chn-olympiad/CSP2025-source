#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PPIII = pair<PII, ll>;
vector<PII> ed[10015];
vector<PPIII> edges;
int c[15];
int a[15][10015];
int fa[10015];
ll bj[2000];
int find(int x) {
	return fa[x] == x?x:fa[x]=find(fa[x]);
}
ll ans_s = 0;
void init(int n){
	for(int i=1;i<=n;++i) fa[i] = i;
}
void solve(int n, int W=0, int k=0, int id = 0){
//	cout << "solve " << n << " " << W << " " << k << " " << id << endl;
	init(n);
	if(id == 0) sort(edges.begin(), edges.end(), [](PPIII p, PPIII q){
		return p.second<q.second;
	});
	int cnt = n-k;
	int kkksc03 = W;
	if(id == 1) while(kkksc03) kkksc03 &= (kkksc03-1), cnt += 1;
	for(PPIII i: edges){
		int u = i.first.first;
		int v = i.first.second;
		int w = i.second;
		
		if(id == 1 and v > n-k and !(W & (1<<v-n+k-1))) continue;
		
		if(find(u) != find(v)){
			fa[fa[u]] = fa[v];
			ans_s += w;
			--cnt;
		}
		if(cnt == 0) break;
	}
}
bool check_SpecialA(int k){
	for(int i=1;i<=k;++i){
		if(c[i]!=0) return false;
	}
	return true;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;++i){
		int u, v, w;
		cin >> u >> v >> w;
		ed[u].push_back({v, w});
		ed[v].push_back({u, w});
		edges.push_back({{u, v}, w});
	}
	for(int i=1;i<=k;++i){
		cin >> c[i];
		for(int j=1;j<=n;++j){
			cin >> a[i][j];
		}
	}
	// Origining Testcase Progamming
	if(k == 0){ // 16pts
		solve(n);
		cout << ans_s << endl;
	}else if(check_SpecialA(k)){ // 32pts
//		puts("Able");
		for(int j=1;j<=k;++j){
			for(int i=1;i<=n;++i){ // L1
				ed[n+j].emplace_back(PII{i, a[j][i]});
				ed[i].emplace_back(PII{n+j, a[j][i]});
				edges.emplace_back(PPIII{{i, n+j}, a[j][i]});
			}
		}
		solve(n+k); // O(m log m)
		cout << ans_s << endl;
	}else{
		ll anss = 1e15;
		for(int j=1;j<=k;++j){
			for(int i=1;i<=n;++i){ // L1
				ed[n+j].emplace_back(PII{i, a[j][i]});
				ed[i].emplace_back(PII{n+j, a[j][i]});
				edges.emplace_back(PPIII{{i, n+j}, a[j][i]});
			}
		} // O(2^km)
		sort(edges.begin(), edges.end(), [](PPIII p, PPIII q){
			return p.second<q.second;
		});
		for(int w=0;w<(1<<k);w++){
			ll a1 = 0;
			if(w == 0) a1 = c[0];
			else if(w & (w-1) == 0) a1 = c[1 + (int)(log2(w & (-w))+0.05)];
			else a1 = bj[w & (w-1)] + c[1 + (int)(log2(w & (-w))+0.05)];
			bj[w] = a1;
			if(a1 > anss) continue;
			solve(n+k, w, k, 1);
			anss = min(anss, ans_s+a1);
			ans_s=0;
		}
		cout << anss << endl;
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/