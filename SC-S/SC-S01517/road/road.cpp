#include<bits/stdc++.h>
#define N 10050
#define M 2005000
using namespace std;
int n,m,k,f[N],c[12],a[12][N],g[12],p[12]; struct Edge{int u,v,w;}E[M],E2[M];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool operator<(Edge aa,Edge bb){return aa.w<bb.w;}
long long krus(int sn,int sm){
	for(int i=1;i<=sn;i++) f[i]=i; sort(E2+1,E2+sm+1);
	int cnt=0; long long w=0; for(int i=1;i<=sm&&cnt<sn-1;i++){
		int fu=find(E2[i].u),fv=find(E2[i].v);
		if(fu!=fv) cnt++,f[fu]=fv,w+=E2[i].w;
	} return w;
}
bool check(){
	for(int i=1;i<=k;i++){
		if(c[i]!=0) return 0;
		g[i]=-1; for(int j=1;j<=n;j++) if(a[i][j]==0) g[i]=j;
		if(g[i]==-1) return 0;
	} return 1;
}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k; for(int i=1;i<=m;i++) cin>>E[i].u>>E[i].v>>E[i].w;
	if(k==0){
		for(int i=1;i<=m;i++) E2[i]=E[i];
		return cout<<krus(n,m)<<endl,0;
	}
	for(int i=1;i<=k;i++){cin>>c[i];for(int j=1;j<=n;j++) cin>>a[i][j];}
	if(check()){
		for(int i=1;i<=m;i++) E2[i]=E[i];
		for(int i=1;i<=k;i++) for(int j=1;j<=n;j++)
			if(j!=g[i]) E2[++m]={g[i],j,a[i][j]};
		return cout<<krus(n,m)<<endl,0;
	} long long ans=LLONG_MAX;
	for(int i=0;i<(1<<k);i++){ int sum=0,q=0;
		for(int j=1;j<=k;j++) if((i>>(j-1))&1) sum+=c[j],p[++q]=j;
		for(int j=1;j<=m;j++) E2[j]=E[j]; int m2=m;
		for(int j=1;j<=q;j++) for(int k=1;k<=n;k++)
			E2[++m2]={n+j,k,a[p[j]][k]};
		ans=min(ans,krus(n+q,m2)+sum);
	} return cout<<ans<<endl,0;
	return 0;
}