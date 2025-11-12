#include<bits/stdc++.h>
using namespace std;
int n,m,k;
namespace K0{
	
const int M=1e6+10;
const int N=1e4+10;
struct Edge{
	int u,v,w;
	bool operator <(Edge oth){
		return w<oth.w;
	}
}e[M];
	
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}	

int ans;
void input(){
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
}
void kruskal(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		int ru=find(e[i].u);
		int rv=find(e[i].v);
		if(ru==rv)continue;
//		printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
		fa[ru]=rv;
		ans+=e[i].w;
	}
	cout<<ans;
}
	
}
/*namespace K5{

const int N=1e3+10;
const int K=10;
int e[N][N];
int c[K],a[K][N];
void input(){
	puts("input");
	memset(e,0x3f,sizeof e);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u][v]=e[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
}

int ANS=1e9;
int ans=0;

int d[N];
bool vis[N];

void prim(){
	puts("prim");
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[1]=0;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&d[j]<d[x]){
				x=j;
			}
		}
		vis[x]=1;
		cout<<x<<d[x]<<'\n';
		ans+=d[x];
		cout<<"ans"<<ans<<'\n';
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				d[j]=min(d[j],e[x][j]);
			}
		}
	}
	ANS=min(ANS,ans);
}



}
void dfs(int t){
	cout<<"dfs";
	if(t>k){
		puts("prim");
		K5::prim();
		return;
	}
//	dfs(t+1);
	
	int el[K5::N][K5::N];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			el[i][j]=K5::e[i][j];
			K5::e[i][j]=min(K5::e[i][j],K5::a[t][i]+K5::a[t][j]);
		}
	}
	K5::ans+=K5::c[t];
	dfs(t+1);
	K5::ans-=K5::c[t];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			K5::e[i][j]=el[i][j];
		}
	}
}*/
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		using namespace K0;
		input();
		kruskal();
	}
	/*else if(n<=1e3&&k<=5){
		using namespace K5;
		input();
		puts("dfs1");
		dfs(1);
		cout<<ANS;
	}*/
}
