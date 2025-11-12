#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
struct Node{
	int from,to,nxt,w;
}e[2*M];
int n,m,k;
int h[N],tot;
int c[20],a[20][N];
int fa[N];
long long ans;
int vis[20],siz[N];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
void Add(int u,int v,int w){
	tot++;
	e[tot].from=u;
	e[tot].to=v;
	e[tot].nxt=h[u];
	e[tot].w=w;
	h[u]=tot;
}
int Find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}
void Kruskal(){
	int cnt=0;
	for(int i=1;i<=tot;i++){
		int u=e[i].from,v=e[i].to;
		int fu=Find(u),fv=Find(v);
		if(fu==fv) continue;
		else{
			if(siz[fu]>siz[fv]) swap(fu,fv);
			fa[fu]=fv;
			ans=ans+1ll*e[i].w;
			cnt++;
		}
		if(cnt>=n-1) return ;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	} 
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Add(u,v,w);
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			//int w;
			//scanf("%d",&w);
			if(a[i][j]!=0) flag=1;
			scanf("%d",&a[i][j]);
			//Add(n+i,j,a[i][j]);
		}
	}
	if(k&&!flag){
		printf("%d\n",0);
		return 0;
	}
	sort(e+1,e+1+tot,cmp);
//	for(int i=1;i<=tot;i++){
//		printf("from %d to %d nxt %d w %d\n",e[i].from,e[i].to,e[i].nxt,e[i].w);
//	}
	Kruskal();
	printf("%lld\n",ans);
	return 0;
}
