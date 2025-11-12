#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;

const int N=1e6+10;
const int inf=1e9;
const int M=1e4;

ll n,m,k;
struct op{
	ll v,w;
};
vector<op> e[N];
ll dis[N],vis[N],ans=INT_MAX;
ll more[N];
map<int,map<int,int> > vis_pos;
priority_queue<pr,vector<pr>,greater<pr> > q;

void disj(int s,int t){
	for(ll i=1;i<=N;i++) dis[i]=inf,vis[i]=0;
	dis[s]=0;
	q.push(make_pair(s,0));
	while(!q.empty()){
		ll u=q.top().first,d=q.top().second;
		q.pop();
		if(u==t){
			ans=min(ans,d);
			continue;
		}
		if(vis[u]) continue;
		vis[u]=1;
		for(ll i=0;i<e[u].size();i++){
			ll v=e[u][i].v,w=e[u][i].w;
			if(vis_pos[u][v]) continue;
			vis_pos[u][v]=1;
			if(vis[v]) continue;
			if(v<=M){
				if(dis[u]+w<dis[v]) dis[v]=dis[u]+w;
				q.push(make_pair(v,dis[v]));
			}
			if(v>M){
				if(dis[u]+w+more[v]<dis[v]) dis[v]=dis[u]+w+more[v];
				q.push(make_pair(v,dis[v]));
			}
		}
	}
}

int main(){
	freopen("road.in.txt","r",stdin);
	freopen("road.out.txt","w",stdout); 
	cin >> n >> m >> k;
	for(ll i=1;i<=m;i++){
		ll u,v,d;
		cin >> u >> v >> d;
		e[u].push_back({v,d});
		e[v].push_back({u,d});
	}
	 
	for(ll i=1;i<=k;i++){
		ll c;cin >> c;
		more[M+i]=c;
		for(ll j=1;j<=n;j++){
			ll w;
			cin >> w;
			e[M+i].push_back({j,w});
			e[j].push_back({M+i,w});
		}
	}
	
	int tot=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			disj(i,j);
			tot+=ans;
			ans=INT_MAX;
		}
	} 
	cout << tot ;
	return 0;
}