#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w,i;
};
struct node1{
	int u,v,w,i;
}t[2002000];
bool cmp(node1 a,node1 b){
	return a.w>b.w;
}
int n,m,K,Sum,ans,c[11];
bool flag[2002000];
vector<node>g[2002000];
bool dfs(int x,int y,int fa){
	if(x==y)return true;
	bool res=false;
	for(auto o:g[x]){
		int v=o.v,i=o.i;
		if(v==fa||flag[i])continue;
		flag[i]=true;
		res|=dfs(v,y,x);
		flag[i]=false;
		if(res)return res;
	}return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&K);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		Sum+=w;
		g[u].push_back({v,w,i});
		g[v].push_back({u,w,i});
		t[i].u=u;t[i].v=v;
		t[i].w=w;t[i].i=i;
	}
	for(int i=1;i<=K;i++){
		int sum;
		scanf("%lld",&sum);
		c[i]=sum;
		for(int j=1;j<=n;j++){
			int w;
//			cout<<1;
			scanf("%lld",&w);
			g[i+m].push_back({j,w,m+(i-1)*n+j});
			g[j].push_back({i+m,w,m+(i-1)*n+j});
			t[m+(i-1)*n+j].u=i+m;
			t[m+(i-1)*n+j].v=j;
			t[m+(i-1)*n+j].w=w;
			t[m+(i-1)*n+j].i=m+(i-1)*n+j;
			sum+=w;
		}
		if(sum==0){
			puts("0");
			return 0;
		}
		Sum+=sum;
	}
	sort(t+1,t+1+m+K*n,cmp);
	for(int i=1;i<=m+K*n;i++){
		flag[i]=true;
		if(dfs(t[i].u,t[i].v,0)){
			Sum-=t[i].w;
		}
	}printf("%lld\n",Sum);
	return 0;
}
//zanmei lqx