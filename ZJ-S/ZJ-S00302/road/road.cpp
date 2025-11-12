#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nMax = 10001, mMax = 1000001, kMax = 11;
struct Edge {
	int u, v, w;
	bool operator < (const Edge e){
		return w < e.w;
	}
} Edges[mMax], Edges2[mMax + nMax * kMax];
vector<Edge> E[nMax + kMax];

int n, m, k;
int c[kMax], a[kMax][nMax];

class UnionFindSet {
	private:
		int nxt[nMax + kMax], siz[nMax + kMax];
	public:
		void init(){
			for(int i = 0; i <= n + k; i++) nxt[i] = i, siz[i] = 1;
		}
		int find(int x){
			if(nxt[x] == x) return x;
			return nxt[x] = find(nxt[x]);
		}
		void uni(int x, int y){
			x = find(x), y = find(y);
			if(x == y) return;
			if(siz[x] > siz[y]) swap(x, y);
			nxt[x] = y, siz[y] += siz[x];
		}
} ufs;

bool checkA(){
	int zero[kMax];
	
	for(int i = 0; i < k; i++){
		if(c[i] != 0) return false;
		
		zero[i] = -1;
		for(int j = 0; j < n; j++){
			if(a[i][j] == 0){
				zero[i] = j;
				break;
			}
		}
		if(zero[i] == -1) return false;
	}
	return true;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0, u, v, w; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({u, v, w});
		E[v].push_back({v, u, w});
		Edges[i] = {u, v, w};
	}
	for(int i = 0; i < k; i++){
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	sort(Edges, Edges + m);
	
	if(checkA()){
		int p = (1 << k) - 1;
			ll ans = 0;
			
			for(int i = 0; i < m; i++) Edges2[i] = Edges[i];
			
			int cnt = 0;
			for(int t = 0; t < k; t++){
				if(p & (1 << t)){
					ans += c[t];
					for(int i = 1; i <= n; i++){
						Edges2[m + cnt * n + i - 1] = {n + 1 + cnt, i, a[t][i]};
					}
					cnt ++;
				}
			}
			
			sort(Edges2, Edges2 + (m + cnt * n));
			
			int cnt2 = 1;
			ufs.init();
			for(int i = 0; i < m + cnt * n; i++){
				int u = Edges2[i].u, v = Edges2[i].v, w = Edges2[i].w;
				if(ufs.find(u) == ufs.find(v)) continue;
				ufs.uni(u, v), ans += w, cnt2 ++;
				if(cnt2 == n + cnt) break;
			}
		printf("%lld\n", ans);
	}else{
		
		ll ANS = LONG_LONG_MAX;
		for(int p = 0; p < (1 << k); p++){
			ll ans = 0;
			
			for(int i = 0; i < m; i++) Edges2[i] = Edges[i];
			
			int cnt = 0;
			for(int t = 0; t < k; t++){
				if(p & (1 << t)){
					ans += c[t];
					for(int i = 1; i <= n; i++){
						Edges2[m + cnt * n + i - 1] = {n + 1 + cnt, i, a[t][i]};
					}
					cnt ++;
				}
			}
			sort(Edges2, Edges2 + (m + cnt * n));
			
			int cnt2 = 1;
			ufs.init();
			for(int i = 0; i < m + cnt * n; i++){
				int u = Edges2[i].u, v = Edges2[i].v, w = Edges2[i].w;
				if(ufs.find(u) == ufs.find(v)) continue;
				ufs.uni(u, v), ans += w, cnt2 ++;
				if(cnt2 == n + cnt) break;
			}
			
			ANS = min(ANS, ans);
		}
		printf("%lld\n", ANS);
	}

	return 0;
}

