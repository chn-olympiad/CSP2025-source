#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e4 + 10, M = 11;
vector<pii> l[N];
int c[M];
bool vis[N];

int n, m, k;
int ans = LONG_LONG_MAX;

void dfs(int u, int sum, int tot){
	if (tot == n){
		ans = min(ans, sum);
		return;
	}
	
	for (auto i : l[u]){
		int v = i.fi, w = i.se;
		
		if (vis[v]) continue;
		vis[v] = true;
		if (v > n) w += c[v - n];
		else	   tot++;
				
		dfs(v, sum + w, tot);
		
		if (v <= n) tot--; 
		vis[v] = false;
	}
	
	return;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	
	for (int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		
		l[u].push_back(mp(v, w));
		l[v].push_back(mp(u, w));
	}	
	
	for (int i = 1; i <= k; i++){
		scanf("%lld", &c[i]);
		
		for (int j = 1; j <= n; j++){
			int x;
			
			scanf("%lld", &x);
			
			l[j].push_back(mp(n + i, x));
			l[n + i].push_back(mp(j, x));
		}
	}
	
	dfs(1, 0, 1);
	
	printf("%lld", ans);
	return 0;
}