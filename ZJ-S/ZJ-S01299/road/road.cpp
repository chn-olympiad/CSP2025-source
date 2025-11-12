#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+7,M=1e6+7;
int n,m,fa[N],cnt;
int find(int x){
	return x==fa[x]?x:x=find(fa[x]);
}
struct T{
	int u,v,w;
}e[M];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	sort(e+1,e+m+1,[&](T A,T B){
		return A.w<B.w;
	});
	int ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		u=find(u),v=find(v);
		if(u==v)continue;
		fa[u]=v;
		ans+=w;
	}
	cout<<ans;
	return 0;
}

