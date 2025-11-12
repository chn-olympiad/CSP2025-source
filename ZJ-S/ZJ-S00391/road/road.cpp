#include <bits/stdc++.h>
#define pll pair<long long, long long>
using namespace std;
typedef long long Int;
const Int MaxN = 1e4+100;
const Int INF = 0x3f3f3f3f3f3f;
Int n, m, k;
Int res = INF;
vector<Int> G[MaxN];
vector<Int> W[MaxN];
Int c[20];
Int a[20][MaxN];
Int  dis[MaxN];
bool vis[MaxN];
Int cheat = 0;
priority_queue<pll, vector<pll>, greater<pll> > q;
void dd(Int s, Int sta){
	Int cnt = 0;
	Int tmp = 0;
	Int ta = sta;
	while(ta){
		tmp ++;
		if(ta&1){
			cnt += c[tmp];
		}
		ta >>= 1;
	}
	while(q.size()) q.pop();
	for(Int i = 1; i <= n; i ++){
		dis[i] = INF;
		vis[i] = false;
	}
	q.push({0,s});
	while(q.size()){
		Int tmp = q.top().first;
		Int s = q.top().second;
		q.pop();
		if(vis[s]) continue;
		cnt += tmp;
		vis[s] = true;
		for(Int i = 0; i < G[s].size(); i ++){
			Int t = G[s][i];
			Int v = W[s][i];
			if(vis[t]) continue;
			if(dis[t] > v){
				dis[t] = v;
				q.push({dis[t],t});
			}
		}
		tmp = 0;
		Int ta = sta;
		while(ta){
			tmp ++;
			if(sta&1){
				for(Int i = 1; i <= n; i ++){
					if(vis[i]) continue;
					if(dis[i] > a[tmp][s]+a[tmp][i]){
						dis[i] = a[tmp][s]+a[tmp][i];
						q.push({dis[i],i});
					}
				}
			}
			ta >>= 1;
		}
		
	}
	
	res = min(res,cnt);
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for(Int i = 1; i <= m; i ++){
		Int u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		G[u].push_back(v);
		W[u].push_back(w);
		G[v].push_back(u);
		W[v].push_back(w);
	}
	for(Int i = 1; i <= k; i ++){
		scanf("%lld", &c[i]);
		for(Int j = 1; j <= n; j ++){
			scanf("%lld", &a[i][j]);
			cheat += a[i][j];
		}
		cheat += c[i];
	}
	if(cheat == 0) printf("0\n");
	else {
		for(Int sta = 0; sta < (1<<k); sta ++){
			dd(1,sta);
		}
		printf("%lld\n", res);
	}
		
	
	//printf("0\n");
	return 0;
}
/*

*/

