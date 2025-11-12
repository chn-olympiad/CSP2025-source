#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
int n,m,k;
int c[15];
struct edge{
	int v,w,fa;
	bool operator <(const edge &a)const{
		return a.w<w;
	}
};
vector<edge> mp[N];
priority_queue<edge> q;
int vis[N],to[15];
int cnt,tot;
void tree(){
	q.push({1,0});
	while(!q.empty()){
		edge h=q.top();
		q.pop();
		int u=h.v;
		if(vis[u])	continue;
		if(u<=n){
			tot++;
			cnt+=h.w;
			vis[u]=1;
			if(h.fa>n){
				cnt+=to[h.fa-n];
				to[h.fa-n]=0;
			}
		}
		else{
			to[u-n]=h.w;
			vis[u]=1;
		}
		if(tot==n)	break;
		int len=mp[u].size();
		for(int i=0;i<len;i++){
			int v=mp[u][i].v;
			if(vis[v])	continue;
			q.push({v,mp[u][i].w,u});
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[u].push_back({v,w,u});
		mp[v].push_back({u,w,v});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			mp[j].push_back({n+i,c[i]+w,j});
			mp[n+i].push_back({j,w,n+i});
		}
	}
	tree();
	cout<<cnt;
	return 0;
}
