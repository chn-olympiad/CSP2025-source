#include<bits/stdc++.h>
using namespace std;
const int N=1e3+50;
int n,m,k;
using ll=long long;
ll c,fa[N*10],ans,x[50][N*10];
struct node{
	int u,v;
	ll w;
};
vector<node> edge;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool all_0=1;
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		edge.push_back({u,v,w});
	} 
	for(int i=1;i<=k;i++){
		scanf("%lld",&c);
		if(c!=0) all_0=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&x[i][j]);
		}
	} 
	if(all_0) {
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				edge.push_back({j,i+n,x[i][j]});
			}
		} 
		n+=k;
	}
	sort(edge.begin(),edge.end(),cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(auto i:edge){
		int u=find(i.u),v=find(i.v);
		if(u==v) continue;
		ans+=i.w;
		fa[v]=u;
	}
	printf("%lld",ans);
	return 0;
}
