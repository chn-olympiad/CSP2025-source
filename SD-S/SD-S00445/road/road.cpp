#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
int n,m,k,f[N],a[12][N/10+5],c[12];
ll ans=1e18;
struct edge{
	int u,v,w;
}e[N],g[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	return (f[x]==x?x:f[x]=find(f[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	ll sumc=0;
	for(int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i];sumc+=c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<(1<<k);++i){
		if(!sumc&&i!=(1<<k)-1)continue;
		ll sum=0,nn=n,t=0;
		for(int j=1;j<=k;++j){
			if((1<<j-1)&i){
				sum+=c[j];
				++nn;
				for(int l=1;l<=n;++l)g[++t]={l,nn,a[j][l]};
			}
		}
		for(int j=1;j<=nn;++j)f[j]=j;
		sort(g+1,g+t+1,cmp);
		int pos1=0,pos2=0,cnt=0;
		e[m+1].w=1e18;g[t+1].w=1e18;
		for(int j=1;j<=m+t;++j){
			int u,v,w;
			if(pos1+1<=m&&e[pos1+1].w<=g[pos2+1].w)++pos1,u=e[pos1].u,v=e[pos1].v,w=e[pos1].w;
			else ++pos2,u=g[pos2].u,v=g[pos2].v,w=g[pos2].w;
			if(find(u)!=find(v))++cnt,sum+=w,f[find(u)]=find(v);
			if(cnt==nn-1||sum>ans)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
