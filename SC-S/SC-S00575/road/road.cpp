#include<bits/stdc++.h>
using namespace std;
int n,m,k,d;
struct edge{
	int u,v,w;
}f[1100005],g[1100005];
vector<int>nw[15];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[1100005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>f[i].u>>f[i].v>>f[i].w;
	} 
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>d;
			nw[i].push_back(d);
		}
	}
	sort(f+1,f+1+m,cmp);
	int t=(1<<k),cnt=0;
	long long ans=1e18;
	for(int i=0;i<t;i++){
		long long sum=0;
		cnt=0;
		for(int j=0;j<k;j++){
			if((i|(1<<j))==i){
				sum+=nw[j+1][0];
				for(int l=1;l<=n;l++){
					g[++cnt]={j+n+1,l,nw[j+1][l]};
				}
			}
		}
		if(sum>=ans){
			continue;
		}
		for(int j=1;j<=m;j++){
			g[++cnt]=f[j];
		}
		sort(g+1,g+1+cnt,cmp);
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=1;j<=cnt;j++){
			int x=find(g[j].u),y=find(g[j].v);
			if(x==y)continue;
			fa[x]=y;
			sum+=g[j].w;
			if(sum>ans)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
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