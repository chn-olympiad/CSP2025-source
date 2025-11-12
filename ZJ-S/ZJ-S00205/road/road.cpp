#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=2e6+5;
struct node{
	int w,u,v;
}x[M];
int n,m,k,cnt;
int d[15][N];
int h[N],fa[N];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void prim(){
	long long ans=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(x+1,x+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u,v;
		u=find(x[i].u);
		v=find(x[i].v);
		if(u==v) continue;
		fa[u]=v;
		ans+=x[i].w;
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		x[++cnt]={u,v,w};
		x[++cnt]={v,u,w};
	}
	bool flag=true;
	for(int i=1;i<=k;i++)
	for(int j=1;j<=n+1;j++){
		scanf("%d",&d[i][j]);
		if(d[i][j]) flag=false;
	}
	if(flag){
		printf("0");
		return 0;
	}
	prim();
	return 0;
}
