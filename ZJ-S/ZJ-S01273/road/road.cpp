#include <bits/stdc++.h>
using namespace std;
const int awa=1145145;
struct qwq{
	int to,w,next;
}Edge[awa<<1];
int cnt,head[awa],c[awa],ansS,wocal=INT_MAX;
/*void add(int u,int v,int w){
	Edge[cnt].to=v;
	Edge[cnt].w=w;
	Edge[cnt].next=head[u];
	head[u]=++cnt;
}*/
vector<pair<int,int> > V[awa];
void dfs(int u,int fa){
	for(int e=head[u];e;e=Edge[e].next){
		int v=Edge[e].to,w=Edge[e].w;
		if(v==fa)continue;
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		/*add(u,v,w);
		add(v,u,w);*/
		V[u].push_back({v,w});
		V[v].push_back({u,w});
	}
	for(int i=1,bye;i<=k;++i){
		cin>>bye;
		ansS+=bye;
		for(int j=1;j<=n;++i){
			cin>>bye;
			//if(bye>V[i][j])
			ansS+=bye;
		}
		wocal=min(wocal,ansS);
		ansS=0;
	}
	cout<<wocal;
}
/*为什么要考图论啊qwq*/