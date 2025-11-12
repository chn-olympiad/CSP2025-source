#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const int MAXN=1e6+10;
int h[MAXN],n,m,k,kx[15][MAXN];
long long ans=0;
struct node{
	int u,v,w;
};
vector<node> g;
bool cmp(node x,node y){
	return x.w<y.w;
}
int Find(int x){
	if(h[x]==x)return x;
	else return h[x]=Find(h[x]);
}
void dij(){
	for(int i=0;i<g.size();i++){
		int ux=g[i].u,vx=g[i].v,wx=g[i].w;
		if(Find(ux)==Find(vx)){
			continue;
		}else{
			h[Find(vx)]=ux;
			ans+=wx;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)h[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int t=1,c; 
		cin>>c;
		for(int j=1;j<=n;j++){
			scanf("%d",&kx[i][j]);
			if(kx[i][j]==0)t=j;
		}
		for(int j=1;j<=n;j++){
			if(j!=t)g.push_back({t,j,kx[i][j]});
		}
	}
	sort(g.begin(),g.end(),cmp);
	dij();
	cout<<ans;
	return 0;
}
