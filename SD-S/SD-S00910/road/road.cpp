#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+9;
const ll M=1e6+9;
const ll K=19;
ll n,m,k;
vector <ll> to[M];
vector <ll> w[M];
ll c[K][N];
ll d[N],dd[N];
bool vis[N];
struct node{
	ll id,val,val1;
	bool operator <(const node &a)const{
		if(a.val==val) return a.val1<val1;
		return a.val<val;
	}
};
priority_queue<node>q;
int cnt1;
void djsl(){
	memset(d,0x3f,sizeof d);
	q.push({1,0,0});
//	vis[1]=1;
//	d[1]=0;
	while(!q.empty()){
		node t=q.top();
		ll u=t.id;
		d[u]=min(d[u],t.val);
		q.pop();
		if(vis[u]) continue;
		cnt1+=t.val1;
//		cout<<u<<' '<<t.val<<' '<<t.val1<<endl;
		vis[u]=1;
		for(int i=0;i<to[u].size();i++){
			ll v=to[u][i];
			if(vis[v]) continue;
			q.push({v,d[u]+w[u][i],w[u][i]});
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,W;
		cin>>u>>v>>W;
		to[u].push_back(v);
		to[v].push_back(u);
		w[u].push_back(W);
		w[v].push_back(W);
	}
	bool d=1;
	ll nn=n;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		if(c[i][0]){
			d=0;	
		}
		for(int j=1;j<=nn;j++){
			cin>>c[i][j];
		}
		if(d){
			n++;
			for(int j=1;j<=nn;j++){
				to[j].push_back(n);
				to[n].push_back(j);
				w[j].push_back(c[i][j]);
				w[n].push_back(c[i][j]);
			}
			
		}
	}
	if(k==0){
		djsl();
		cout<<cnt1<<endl;
	}
	else if(d){
		djsl();
		cout<<cnt1<<endl;
	}
	return 0;
}
