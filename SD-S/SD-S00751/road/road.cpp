#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct edge{
	int u,to,next;
	ll c;
}e[2*1000005+2*10*10005+25];
int head[10005];
ll cnt=0;
void addedge(int u,int v,ll w){
	cnt++;
	e[cnt].u=u;
	e[cnt].to=v; e[cnt].c=w; e[cnt].next=head[u];
	head[u]=cnt;
}
bool cmp(edge x,edge y){
	return x.c<=y.c;
}
ll ans=0;
bool vis[10005+100];
void kruskal(){
	for(int i=1;i<=cnt;i++){
		int c=e[i].c,to=e[i].to,u=e[i].u;
		if((!vis[to])||(!vis[u])){
			vis[to]=true; vis[u]=true;
			ans+=c;
		}
	}
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	//cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		//cin >> u >> v >> w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		//cin >> c;
		
		for(int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
			addedge(n+i,j,a);
			addedge(j,n+i,a);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	kruskal();
	printf("%d",ans);
	return 0;
}
//Ren5Jie4Di4Ling5%
