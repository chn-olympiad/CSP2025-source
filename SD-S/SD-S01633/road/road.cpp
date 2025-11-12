#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 3e6 + 10;
const int N = 1e4 + 10;
const ll INF = 1e18 + 7;
struct Edge{
	int u,v;
	ll w;
}edge[M];
int n,m,k,cnt,fa[N];
ll val[N][N];
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int Find(int x){
	if(x == fa[x]){
		return x;
	}
	return fa[x] = Find(fa[x]);
}
int c[15],a[15][N];
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++)fa[i] = i;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		cin >> u >> v >> w;
		edge[++cnt].u = u;
		edge[cnt].v = v;
		edge[cnt].w = w;
	}
	bool flg = true;
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= k;i ++)if(c[i] != 0)flg = false;
	if(flg){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				val[i][j] = INF;
			}
		}
		for(int i = 1;i <= k;i ++){
			for(int j = 1;j <= n;j ++){
				for(int o = j + 1;o <= n;o ++){
					val[j][o] = min(val[j][o],1ll * a[i][j] + a[i][o]);
				}
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				if(val[i][j] == INF)continue;
				cnt++;
				edge[cnt].u = i;
				edge[cnt].v = j;
				edge[cnt].w = val[i][j];
			}
		}
		int tot = 0;
		sort(edge + 1,edge + 1 + cnt,cmp);
		for(int i = 1;i <= cnt;i ++){
			int u = edge[i].u,v = edge[i].v;
			ll w = edge[i].w;
			int pu = Find(u),pv = Find(v);
			if(pu != pv){
				tot ++;
				ans += w;
				fa[pu] = pv;
			}
			if(tot == n - 1)break;
		}
		cout << ans << "\n";
	}
	else if(k == 0){
		int tot = 0;
		sort(edge + 1,edge + 1 + cnt,cmp);
		for(int i = 1;i <= cnt;i ++){
			int u = edge[i].u,v = edge[i].v;
			ll w = edge[i].w;
			int pu = Find(u),pv = Find(v);
			if(pu != pv){
				tot ++;
				ans += w;
				fa[pu] = pv;
			}
			if(tot == n - 1)break;
		}
		cout << ans << "\n";
	}
	
	
	
	
	
	
	return 0;
} 
