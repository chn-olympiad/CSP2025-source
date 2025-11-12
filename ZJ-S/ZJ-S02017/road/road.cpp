#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,INF=0x3f3f3f3f;
int n,m,k,fa[N],ans;
struct edge{
	int v,w;
};
vector<edge>g[N];
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}int f(int x){
	if(fa[x]==x)return x;
	return fa[x]=f(fa[x]);
}void mst(){
	init();
	for(int i=1;i<=n;i++){
		int idx=-1,idy=-1,mn=INF;
		for(int j=0;j<g[i].size();j++){
			int v=g[i][j].v,w=g[i][j].w;
			int fx=f(i),fy=f(v);
			if(fx!=fy&&w<mn)mn=w,idx=fx,idy=fy;
		}if(idx!=-1)fa[idx]=idy,ans+=mn;
	}
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back((edge){v,w}),g[v].push_back((edge){u,w});
	}if(!k){
		mst();
		cout<<ans;
	}cout<<0;
	return 0;
}
