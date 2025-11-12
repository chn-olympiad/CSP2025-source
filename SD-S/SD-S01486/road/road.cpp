#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
int c[15][N];
struct Edge{int u,v,w;}e1[M*2];
int tot;
bool cmp(Edge a,Edge b){return a.w<b.w;}
int fa[N];
int Find(int u){return u==fa[u]?u:fa[u]=Find(fa[u]);}
struct Node{int to,nex,w,num;}e[M*2];
int head[N],cnt;
long long ans;
bool used[M];
void add(int u,int v,int w){e[++cnt]=(Node){v,head[u],w};head[u]=cnt;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e1[i].u>>e1[i].v>>e1[i].w,cnt++;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++) cin>>e1[++cnt].w,e1[cnt].u=n+i,e1[cnt].v=j;
	}
	sort(e1+1,e1+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int u=e1[i].u,v=e1[i].v,w=e1[i].w;
		int fau=Find(u),fav=Find(v);
		if(fau!=fav){
			fa[fau]=fav;
			ans+=w;
//			used[i]=1;
//			add(u,v,w),add(v,u,w);
			tot++;
			if(tot==n+k-1) break;
		}
	}
	cout<<ans;
	return 0;
}
