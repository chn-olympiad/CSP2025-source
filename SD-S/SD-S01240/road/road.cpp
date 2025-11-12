#include<bits/stdc++.h>



using namespace std ;
typedef pair<int,int> pii;
typedef long long ll;
const int N=2e4+50;
ll dis[N];
int vis[N];
vector<pii>g[N];
int used[N];
ll cc[N];
struct node {
	int pre,nxt;
	ll w;
	friend bool operator>(node x,node y) {
		return x.w>y.w;
	}
};
int n,m,k;
ll fa[N],ww[N];
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int check(int x,int y) {
	return find(x)==find(y);
}
void merge(int x,int y) {
	fa[find(x)]=find(y);
}
ll prim() {
	int tot=0;
	ll ans=0;
	priority_queue<node,vector<node>,greater<node>>q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(used,0,sizeof used);
	for(int i=n+1; i<=n+k; i++) {
		q.push({i,i,cc[i-n]});
	}
	q.push({1,1,0});
	for(int i=0; i<=n+k; i++)fa[i]=i;
	while(q.size()) {
		node x=q.top();
		q.pop();
		int u=x.nxt,w=x.w;
		if(check(u,x.pre)&&u!=x.pre)continue;
//		if(u<=n)tot++;
		merge(u,x.pre);
		ans+=w;
		if(u!=x.pre)used[x.pre]++;
		ww[x.pre]+=w;
		
//		cout<<u<<" "<<x.pre<<endl;
		for(auto _:g[u]) {
			int v=_.first,w=_.second;
			if(check(v,u)==0&&(v==1||check(v,1)==0)) {
				cout<<u<<" "<<v<<endl;
				q.push({u,v,w});
			}
		}

	}
	return ans;
}
ll gg[15][N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
//	g[0].push_back({1,0});
	for(int i=1; i<=k; i++) {
		int c;
		cin>>c;
		cc[i]=c;
		for(int j=1; j<=n; j++) {
			int x;
			cin>>x;
			gg[i][j]=x;
			g[n+i].push_back({j,x});
		}
	}
	ll ans=prim();
	for(int i=1; i<=k; i++) {
		if(used[n+i]<=1) {
			cout<<"-"<<n+i<<endl;
			ans-=ww[n+i];
		}
	}
	cout<<ans;


}
