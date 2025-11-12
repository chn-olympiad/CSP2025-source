#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,dis[N],ans[N],s;
bool vis[N];
struct node {
	int v,w;
};
vector<node> g[N];
queue<int> q;
void kru(int st)
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(st);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(vis[t]==true) continue;
		vis[t]=true;
		for(int i=0;i<=g[t].size()-1;i++)
		{
			node v=g[t][i];
			if(dis[v.v]>dis[t]+v.w){
				dis[v.v]=dis[t]+v.w;
				ans[v.v]=v.w;
			}
			q.push(v.v);
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		int w,w1;
		scanf("%lld",&w);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w1);
			g[m+i].push_back({j,w1});
			g[j].push_back({m+i,w+w1});
		}
	}
	kru(1);
	for(int i=1;i<=n;i++)
		s+=ans[i];
	cout<<s-3;
		
	return 0;
}

