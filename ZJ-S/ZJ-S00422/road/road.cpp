#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c,t[10005],t2;
int le=0;
struct ed{
	int u,v,w;
}e[3000005];
bool cmp(ed x,ed y){
	return x.w<y.w;
}
int fa[10005];
int getfa(int u){
	if(u==fa[u])return u;
	else{
		fa[u]=getfa(fa[u]);
		return fa[u];
	}
}
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	le=m+1;
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>t[j];
			if(t[j]==0)t2=j;
		}
		for(int j=1;j<=n;j++){
			e[le].u=t2,e[le].v=j,e[le].w=t[j];
			le++;
		}
	}
	sort(e,e+le,cmp);
	//for(int i=0;i<le;i++)cout<<e[i].u<<e[i].v<<e[i].w<<"\n";
	for(int i=0;i<n;i++)fa[i]=i;
	for(int i=0;i<le;i++){
		if(getfa(e[i].u)!=getfa(e[i].v)){
			fa[getfa(e[i].u)]=getfa(e[i].v);
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}