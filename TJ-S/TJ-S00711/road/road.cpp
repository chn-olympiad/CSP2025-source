#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,vi[10001],c[11],a[11][10001],p;
long long s,as = LLONG_MAX;
struct N{
	int v,w;
};
vector<N> g[10001];
void dfs(int d){
	vi[d] = 1;
	p = 1;
	for(int i = 2;i <= n;i++){
		if(g[d][i].w < g[d][p].w && !vi[i]) p = i;
	}
	s += p;
	dfs(p);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(N{v,w});
		g[v].push_back(N{u,w});
	}
	for(int j = 1;j <= k;j++){
		scanf("%d",&c[j]);
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[j][i]);
			if(a[j][i] == 0){
				s = 0;
				dfs(i);
				as = min(as,s);
			}
		}
	}
	printf("%lld",as);
	return 0;
}
