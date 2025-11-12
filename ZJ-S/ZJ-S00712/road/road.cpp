#include <bits/stdc++.h>
using namespace std;
const int N=1e6+30;
int head[2*N],nxt[2*N],to[2*N];
long long value[2*N],ans,dis[N],a[N];
int edge,n,m,k;
bool book[N],pd[N];
void add(int u,int v,long long w){
	nxt[++edge]=head[u];
	to[edge]=v;
	value[edge]=w;
	head[u]=edge;
}
long long prim(int t){
	long long dist=0;
	memset(pd,1,sizeof(pd));
	for(int i=n+1;i<=n+k;i++)pd[i]=book[i];
	for(int i=1;i<=n+k;i++)dis[i]=INT_MAX;
	dis[1]=0;
	while(true){
		bool p=0;
		for(int j=1;j<=n+k;j++)p=p|pd[j];
		if(!p)break;
		int maxx=INT_MAX,u;
		for(int j=1;j<=n+k;j++)if(pd[j]&&dis[j]<maxx){
			maxx=dis[j];
			u=j;
		}
		pd[u]=0;
		dist+=maxx;
		for(int e=head[u];e;e=nxt[e]){
			int v=to[e];
			long long w=value[e];
			if(!pd[v]) continue;
			dis[v]=min(dis[v],w);
		}
	}
	return dist;
}
void search(int dep,int sum,int t){
	if(sum>=ans)return ;
	if(dep==k+1){
		long long fzx=prim(t);
		ans=min(ans,fzx+sum);
		return ;
	}
	search(dep+1,sum,t);
	book[n+dep]=1;
	search(dep+1,sum+a[dep],t+1);
	book[n+dep]=0;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int u,v;
		long long w;
		book[i]=1;
		scanf("%d%d%lld",&u,&v,&w);
		ans+=w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		book[n+i]=0;
		scanf("%lld",&a[i]);
		for(int j=1;j<=n;j++){
			int u=n+i,v=j;
			long long w;
			scanf("%lld",&w);
			add(u,v,w);
			add(v,u,w);
		}
	}
	search(1,0,0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}