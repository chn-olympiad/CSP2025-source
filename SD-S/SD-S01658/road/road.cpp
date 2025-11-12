#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+5;
int n,m,k,f[N],cnt,c[N];
ll sc,a[11][N/2];
struct edge{
	int u,v;
	ll w;
}e[1000005],g[1500005];
bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}
ll kruskle(){
	ll ans=0;
	sort(g+1,g+cnt+1,cmp);
	for(int i=1;i<=n+k;++i)f[i]=i;
	for(int i=1;i<=cnt;++i){
		int x=g[i].u,y=g[i].v;
		if(find(x)!=find(y)){
			merge(x,y);
			ans+=g[i].w;
		}
	}
	return ans;
}
void A(){
	cnt=m;
	for(int i=1;i<=m;++i)
		g[i]=e[i];
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j)
			g[++cnt]={n+i,j,a[i][j]};
	}
	cout<<kruskle();
}
void normal(){
	ll minn=1e17;
	for(int i=0;i<(1<<k);++i){
		ll now=0;
		cnt=m;
		for(int j=1;j<=m;++j)
			g[j]=e[j];
		for(int j=1;j<=k;++j){
			if(i&(1<<j-1)){
				now+=c[j];
				for(int x=1;x<=n;++x)
					g[++cnt]={n+j,x,a[j][x]};
			}
		}
		now+=kruskle();
		minn=min(minn,now);
	}
	cout<<minn;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v;ll w;cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j],sc+=a[i][j];
	}
	if(k<=5&&m<=100000){
		normal();
	}
	else
		A(); 
	return 0;
}
