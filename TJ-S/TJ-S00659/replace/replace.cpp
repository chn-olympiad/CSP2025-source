#include<bits/stdc++.h>
using namespace std;

const int MAXN=10000;
int n,m,vis[MAXN],dis[MAXN];
struct node{
	int u,v,d;
	bool operator <(const node &x) const{
		return x.d < d;
	}
};
priority_queue<node> q;
vector<pair<int,int> > v[MAXN];

void dij(int s){
	for(int i=0;i<int(v[s].size());i++)
		q.push({s,v[s][i].first,v[s][i].second});
	while(!q.empty()){
		node nd=q.top();
		q.pop();
		vis[q.u]=1;
		for(int i=0;i<int(v[q.u].size());i++){
			if(vis[v[q.u][i].first]) continue;
			q.push({s,v[q.u][i].first,v[q.u][i].second});
		}
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int x,y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
//	dij(s);
	
	
	return 0;
}
