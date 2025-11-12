#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+50;
int n,m,k,l,fa[maxn],use[maxn],cnt;
ll ans;
struct road{
	int u,v,w,cost,type;
}g[maxn];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void addedge(int u,int v,int w){
	g[++l].u=u;
	g[l].v=v;
	g[l].w=w;
}
bool cmp(road x,road y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		g[l].type=0;
		addedge(v,u,w);
		g[l].type=0;
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			int w;
			scanf("%d",&w);
			addedge(n+i,j,w+c);
			g[l].type=1;
			g[l].cost=c;
			addedge(j,n+i,w+c);
			g[l].type=1;
			g[l].cost=c;
		}
	}
	sort(g+1,g+1+l,cmp);
	for(int i=1;i<=l;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w,f1=find(u),f2=find(v);
		if(f1!=f2){
			ans+=w;
			fa[f2]=f1;
			if(g[i].type==0)cnt++;
			else{
				if(u<v)swap(u,v);
				if(!use[u]){
					use[u]=1;
				}else{
					cnt++;
					ans-=g[i].cost;
				}
			}
		}
		if(cnt==n-1){
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
