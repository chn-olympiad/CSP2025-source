#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,w[15],ans,fa[20000];
struct node{
	int u,v,w;
}e[1100004];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	int opt=0;
	for(int i=1;i<=k;i++){
		cin>>w[i];if(w[i])opt=1;
		bool flag=0;
		for(int j=1;j<=n;j++){
			int v;cin>>v;
			e[++cnt]={n+i,j,v};
			if(!v)flag=1;
		}
		if(!flag)opt=1;
	}
	sort(e+1,e+cnt+1,cmp);
	if(!opt){
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=cnt;j++){
			int fax=find(e[j].u),fay=find(e[j].v);
			if(fax!=fay)fa[fax]=fay,ans+=e[j].w;
		}
		cout<<ans;
	}
	else{
		int final=1e18;
		for(int i=0;i<(1<<k);i++){
			ans=0;
			for(int j=1;j<=n+k;j++)fa[j]=j;
			for(int j=1;j<=k;j++)if(i&(1<<j-1))ans+=w[j];
			for(int j=1;j<=cnt;j++){
				if(e[j].u>n&&!((1<<e[j].u-n-1)&i))continue;
				int fax=find(e[j].u),fay=find(e[j].v);
				if(fax!=fay)fa[fax]=fay,ans+=e[j].w;
			}
			final=min(final,ans);
		}
		cout<<final;
	}
	return 0;
}
