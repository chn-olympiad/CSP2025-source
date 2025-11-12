//rp++
//love CCF
//怎么T2这么难，服了。 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e4+20,M=6e6+10;
int n,m,k,a[11][N],tot,fa[N],siz[N];
struct Edge{int u,v,w;}X[M],e[M];
bool cmp(Edge x,Edge y){return x.w<y.w;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int tot=0;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e[++tot]={u,v,w};
		e[++tot]={v,u,w};
	}
	long long sum=0;
	for(int i=1;i<=k;i++){
		cin>>a[i][0];sum+=a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++tot]={n+i,j,a[i][j]};
			e[++tot]={j,n+i,a[i][j]};
		} 
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=tot;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			if(siz[fx]<siz[fy]) fa[fx]=fy,siz[fy]+=siz[fx];
			else fa[fy]=fx,siz[fx]+=siz[fy];
			sum+=e[i].w;
		}
	}
	cout<<sum;
	return 0;
}
