//ALL FOR MYSELF, NOT ANYONE ELSE

//Prim怎么写啊啊啊啊啊啊啊啊啊啊啊啊啊 
#include<bits/stdc++.h>
//#define TERRY_MC
#define endl '\n'
using namespace std;
typedef long long ll;
#define int ll
const int N=1e4+20, M=2e6+10;;
int n,m,k,c[15],fa[N];
//vector<pair<int,int>> g[N];
struct edge {
	int u,v,w;
	friend bool operator<(edge a, edge b) {
		return a.w<b.w;
	}
}es[M];
void init() {
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
}
int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
bool merge(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx==fy) return false;
	fa[fx]=fy;
	return true;
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef TERRY_MC
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++) {
		cin>>u>>v>>w;
//		g[u].push_back({w,v});
//		g[v].push_back({w,u});
		es[i].u=u,es[i].v=v,es[i].w=w;
	}
	if(k!=0) {
		//超级原点至所有点（Kruskal不能单向边，加了肯定会答案变小，不如不加碰碰运气） 
	//	for(int i=1;i<=n;i++) {
	//		g[0].push_back({0,i});
	//	}
		m+=n;
		for(int i=1;i<=k;i++) {
			cin>>c[i];
			//超级原点至乡镇点 
	//		g[0].push_back({c[i],i+n}) 
	//但是Kruskal没法处理单向边没办法awa 
			m++;
			es[m].u=0,es[m].v=i,es[m].w=c[i];
			int a;
			for(int j=1;j<=n;j++) {
				cin>>a;
	//			g[i+n].push_back({a,j});
	//			g[j].push_back({a,i+n});
				m++;
				es[m].u=j;
				es[m].v=i+n;
				es[m].w=a;
			}
		}
	}
	sort(es+1,es+m+1);
	init();
	int ans=0;
	for(int i=1;i<=m;i++)
		if(merge(es[i].u,es[i].v)) {
			ans+=es[i].w;
		}
	cout<<ans<<endl;
	//似乎用不了Kruskal（可发现仅需要城市连边，乡村甚至可以不连，故我们使用Prim) 
	//但是***d我**忘了Prim咋写了 
	//Kruskal吧（错就错吧） 
	return 0;
}

