#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define maxn 100105
#define pb push_back
using namespace std;
struct edge{
	ll to;
	ll weight;
};
vector<edge> e[maxn];
int n,m,k;
ll cosi[15][maxn],csf[15];
bool vis[maxn];
ll ans[maxn];
bool check(){
	for(int i=1;i<=n;i++){
		if(!vis[i]) return false;
	}
	return true;
}
void bfs(ll n){
	queue<ll> q;
	q.push(n);
	while(!q.empty()){
		int x=q.front();
		ll Mi=0x3f3f3f3f,Miv;
		for(int i=0;i<e[x].size();i++){
			int p=e[x][i].to;
			int c=csf[p];
			if(e[x][i].weight+ans[x]+c<Mi&&!vis[p]){
				Mi=e[x][i].weight+ans[x]+c;
				Miv=p;
			}
		}
		vis[Miv]=true;
		ans[Miv]=Mi;
		if(check()) return;
		q.push(Miv);
		q.pop();
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(ans,0x3f3f3f3f,sizeof(ans));
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		edge tp;tp.to=v,tp.weight=w;
		e[u].pb(tp);
		tp.to=u;
		e[v].pb(tp);
	}
	for(int i=1;i<=k;i++){
		cin>>csf[n+i];
		for(int j=1;j<=n;j++){
			cin>>cosi[i][j];
			edge tp;tp.to=j,tp.weight=cosi[i][j];
			e[n+i].pb(tp);
			tp.to=n+i;
			e[i].pb(tp);
		}
	}
	vis[1]=true;
	ans[1]=0;
	bfs(1);
	ll Mx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(ans[i]>Mx) Mx=ans[i];
	}
	cout<<Mx;
	return 0;
}
