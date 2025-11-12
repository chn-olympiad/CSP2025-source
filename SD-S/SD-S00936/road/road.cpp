#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int n,m,k,fa[N];
struct node{
	int u,v;
	ll w;
//	int p;
}edge[N<<1],edge2[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
bool cmp2(node a,node b){
	return a.w>b.w; 
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
ll work(){
	ll ans=0,tot=0;
	for(int i=1;i<=m;i++){
		node p=edge[i];
		int u=p.u,v=p.v;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			ans+=p.w;
			edge2[++tot]=p;
		}
		if(tot==n-1)
			return ans;
	}
//	if(k<=0){
//		cout<<ans;
//		exit(0);
//	}
//	sort(edge2+1,edge2+1+tot,cmp2);
//	for(int i=1;i<=tot;i++){
//		for(int j=1;j<=k;j++){
//			
//		}
//	}
}
vector<int>g[N];
//void dfs(int x,ll tot){
//	if(x>k){
//		ans=min(ans,tot);
//		return;
//	}
//	
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		edge[i]={u,v,w};
	}
	for(int i=1,x;i<=k;i++){
		cin>>x;
		g[i].push_back(x);
		for(int j=1,y;j<=n;j++){
			cin>>y;
			g[i].push_back(y);
		}
	}
//	if(k<=0){
//		cout<<work(n);
//		return 0;
//	}
//	dfs(1);
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	ll ans=work();
	cout<<ans;
	return 0;
}


