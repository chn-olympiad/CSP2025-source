#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=1e4+5,M=1e6+5,K=12;
int fa[N],n,m,k,cnt,p[N];
ll ans,a[K][N],c[K];
struct Node{
	ll w;
	int u,v;	
	bool operator <(const Node &x)const{
		return w<x.w;
	}
}e[M],e1[N];
int find(int i){
	return i==fa[i]?i:fa[i]=find(fa[i]);
}
bool unite(int x,int y){
	x=find(x), y=find(y);
	if(x==y) return true;
	fa[x]=y;
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++)
		if(!unite(e[i].u,e[i].v)) ans+=e[i].w, e1[++cnt]=e[i];
	for(int i=1;i<(1<<k);i++){
		ll res=0;
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1) res+=c[j];
		for(int j=1;j<=n;j++)
			p[j]=0;
		for(int j=cnt;j>=1;j--){
			int u=e1[j].u,v=e1[j].v,w=e1[j].w;
			if(!p[u]&&!p[v]){
				int q=0;
				for(int x=1;x<=k;x++)
					if(a[x][u]+a[x][v]<w&&(!q||q&&a[x][u]+a[x][v]<a[q][u]+a[q][v])) q=x;
				if(q>0) res+=a[q][u]+a[q][v], p[u]=p[v]=q;
				else res+=w;
			}
			else if(p[u]||p[v]){
				if(!p[u]) swap(u,v);
				if(a[p[u]][v]<w) res+=a[p[u]][v], p[v]=p[u];
				else res+=w;
			}
			else res+=w;
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}