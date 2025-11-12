#include <bits/stdc++.h>
using namespace std;
const int N=1e4+3,M=1e6+3,Mx=2e15+3;
typedef long long ll;
ll n,m,k,c[13],a[13][N],x,y,z,o,done,ans;
bool vis[N],V[13];
struct node{
	ll v,w,add;
	friend bool operator <(node u1,node u2){
		return u1.w>u2.w;
	}
};
vector<node> vt[N];
priority_queue<node> vi[13],pq,pq2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	while(m--){
		cin>>x>>y>>z;
		vt[x].push_back({y,z,0});
		vt[y].push_back({x,z,0});
	}
	for(int i=1;i<=k;i++){
		V[i]=1;
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			vi[i].push({j,a[i][j],0});
		}
	}
	pq.push({1,0,0});
	while(1){
		if(pq2.empty()||pq.top().w<pq2.top().w+c[pq2.top().add]*V[pq2.top().add]){
			x=pq.top().v;
			y=pq.top().w;
			o=pq.top().add;
			pq.pop();
		}
		else{
			x=pq2.top().v;
			y=pq2.top().w+c[pq2.top().add]*V[pq2.top().add];
			o=pq2.top().add;
			pq2.pop();
		}
		if(vis[x])
			continue;
		ans+=y;
		V[o]=0;
		vis[x]=1;
		if(++done==n){
			cout<<ans;
			return 0;
		}
		for(auto i:vt[x]){
			pq.push({i.v,i.w,0});
//			cout<<"push"<<i.v<<','<<i.w<<','<<z+i.w<<','<<"0\n";
		}
		for(int i=1;i<=k;i++){
			while((!vi[i].empty())&&vis[vi[i].top().v])
				vi[i].pop();
			y=vi[i].top().w+a[i][x];
			pq2.push({vi[i].top().v,y,i});
//			cout<<"push"<<vi[i].top().v<<','<<y<<','<<z+y<<','<<i<<'\n';
		}
	}
	return 0;
}

