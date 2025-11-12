#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[10005];
struct st{
	int u,v,w;
}e[1000005];
int findfa(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=findfa(fa[x]);
}
bool cmp(st x,st y){
	return x.w<y.w;
}
signed main(){
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[i]={u,v,w};
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int cnt=0,ans=0;
		for(int i=1;i<=m;i++){
			int u=e[i].u;
			int v=e[i].v;
			int fau=findfa(u);
			int fav=findfa(v);
			if(fau==fav){
				continue;
			}
			fa[fau]=fav;
			cnt++;
			ans+=e[i].w;
		}
		cout<<ans;
	}
}
