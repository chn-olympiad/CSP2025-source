#include<bits/stdc++.h>
using namespace std;
int n,m,k,len;
struct edge{
	int u,v,w;
};
int c[15],a[15][100005],u[100005],v[100005],w[100005];
edge G[3000005];
int fa[100005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
//		G[i].u=u,G[i].v=v,G[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
//		for(int j=1;j<=n;j++){
//			for(int jj=j+1;jj<=n;jj++){
//				u[++m]=j;
//				v[m]=j;
//				w[m]=a[i][j];
//				m++;
//				G[m].u=j,G[m].v=jj,G[m].w=a[i][j]+a[i][jj];
//			}
//		}
	}
	for(int i=1;i<=m;i++){
		G[i].u=u[i],G[i].v=v[i],G[i].w=w[i];
	}
	sort(G+1,G+m+1,cmp);
	int now=0,ans=0;
	for(int i=1;i<=m;i++){
		if(find(G[i].u)==find(G[i].v)) continue;
		else{
			ans+=G[i].w;now++;
			fa[G[i].u]=G[i].v;
		}
		if(now==n-1){
			cout<<ans;
			return 0;
		}
//		cout<<"------------\n";
	}
	return 0;
}