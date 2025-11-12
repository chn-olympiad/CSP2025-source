#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define fi first
#define se second
using namespace std;
int n,m,k;
vector<pair<int,int> > e[10086];
vector<pair<int,int> > te[10086];
int c[15],a[15][10086];
int ans=0;
struct node{
	int u,v,w;
	const bool operator > (const node b) const{
		return w>b.w;
	}
};
priority_queue<node,vector<node>,greater<node> > q; 
node ch(int u,int v,int w){
	node t;
	t.u=u,t.v=v,t.w=w;
	return t;
}
int fa[10086];
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int mst(int k2=0){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	while(q.size())q.pop();
	for(int u=1;u<=n+k;u++){
		for(auto x:e[u]){
			int v=x.fi,w=x.se;
			q.push(ch(u,v,w));
		}
	}
	int cnt=0,sum=0;
	while(!q.empty()&&cnt<n+k2-1){
		auto x=q.top();q.pop();
		int u=x.u,v=x.v,w=x.w;
		if(find(u)!=find(v)){
			sum+=w;
			merge(u,v);
			cnt++;
		} 
	}
	return sum;
}
void solveA(){//for task A
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[i+n].pb({j,a[i][j]});
			e[j].pb({i+n,a[i][j]});
		}
	}
	cout<<mst()<<"\n";
}
bool use[15];
void dfs(int d){
	if(d==k+1){
		int sum=0,cnt=0;
		for(int i=1;i<=n+k;i++)e[i]=te[i];
		for(int i=1;i<=k;i++){
			if(!use[i])continue;
			sum+=c[i];cnt++;
			for(int j=1;j<=n;j++){
				e[i+n].pb({j,a[i][j]});
				e[j].pb({i+n,a[i][j]});
			}
		}
		if(sum<ans)sum+=mst(cnt);
		ans=min(ans,sum);
		return;
	}
	use[d]=true;
	dfs(d+1);
	use[d]=false;
	dfs(d+1);
} 
void solveB(){//baoli
	for(int i=1;i<=n+k;i++){
		te[i]=e[i];
	}
	ans=1e18;
	dfs(1);
	cout<<ans<<"\n";
}
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=false;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(flag)solveA();
	else solveB();
	return 0;
}
// give me 56 pts plz! qwq!
