#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fre(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
bool specialA=1;
ll n,m,k,fa[10010],ans;
struct node{
	ll u,v,w;
}g[1000010];
struct town{
	ll c,a[1000010];
}cs[15];
bool cmp(node a,node b){
	return a.w<b.w;
}
int findfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
int main(){
	fre();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	for(int i=1;i<=k;i++){
		cin>>cs[i].c;
		specialA&=(cs[i].c==0);
		for(int j=1;j<=n;j++)
			scanf("%d",&cs[i].a[j]),specialA&=(cs[i].a[j]==0);
	}
	if(specialA&&k!=0){
		cout<<0;
		return 0;
	}
	if(k==0){
		sort(g+1,g+m+1,cmp);
		ans=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int fu=findfa(g[i].u),fv=findfa(g[i].v);
			if(fu==fv)continue;
			fa[fv]=fu,ans+=g[i].w;
		}
		cout<<ans;
		return 0;
	}    
	sort(g+1,g+m+1,cmp);
	ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int fu=findfa(g[i].u),fv=findfa(g[i].v);
		if(fu==fv)continue;
		fa[fv]=fu,ans+=g[i].w;
	}
	cout<<ans;                        
	return 0;
}
