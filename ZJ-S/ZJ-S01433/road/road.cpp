#include<bits/stdc++.h>
using namespace std;
const int N=10010,K=15;
int n,m,k;
long long a[N][K],c[K];
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct Edge{
	int u,v;
	long long w;
}e[10000010];
int cmp(Edge x,Edge y){
	return x.w<y.w;
}
void solve(){
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		fa[fu]=fv;
		ans+=w;
		if(++cnt==n-1) break;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int l=1;l<j;l++){
				e[++m]=Edge{j,l,c[i]+a[i][l]+a[i][j]};
			}
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	solve();
	return 0;
}
