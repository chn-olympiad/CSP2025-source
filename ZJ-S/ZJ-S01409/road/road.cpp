#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
#define int long long
int n,m,k,ans;
int ct[MAXN];
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return dis>a.dis;
	}
};
bool b[MAXN];
bool c[MAXN];
vector<node> g[MAXN];
void f(){
	priority_queue<node> q;
	q.push({1,0});
	while(!q.empty()){
		node x=q.top();
		q.pop();
		if(b[x.id]) continue;
		b[x.id]=1;
		c[x.id]=1;
		for(auto v:g[x.id]){
			if(b[v.id]) continue;
			q.push({v.id,x.dis+v.dis});
			c[v.id]=1;
			ans+=v.dis;
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(c[i]==0) flag=false;
		}
		if(flag) return;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>ct[i];
		for(int j=1;j<=n;j++){
			int tmp;
			cin>>tmp;
		}
	}
	f();
	cout<<ans;
	return 0;
}