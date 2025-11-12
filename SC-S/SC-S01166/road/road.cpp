#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> rk,fa;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unite(int x,int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(rk[x]>rk[y]) fa[y]=x;
	else if(rk[y]>rk[x]) fa[x] = y;
	else fa[x]=y,rk[y]++;
}

ll MST(const vector<pair<int,pair<int,int>>> &edge,const int &n,const int &m){
	ll tot=0,cnt = 0;
	for(int i=1;i<=m;i++){
		if(cnt == n-1) return tot;
		int w = edge[i].first;
		int u = edge[i].second.first;
		int v = edge[i].second.second;
		if(find(u) == find(v)) continue;
		cnt++,tot+=w;
		unite(u,v);
	}
}
void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rk.assign(n+1,1);
	fa.resize(n+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	vector<pair<int,pair<int,int>>> edge(m+1); 
	for(int i=1;i<=m;i++) scanf("%d%d%d",&edge[i].second.first,&edge[i].second.second,&edge[i].first);
	vector<vector<int>> newPoints(k+1,vector<int>(n+2));
	for(int i=1;i<=k;i++) for(int j=1;j<=n+1;j++)cin >> newPoints[i][j];
	for(int i=1;i<=k;i++){
		for(int u=2;u<=n+1;u++){
			for(int v=2;v<=n+1;v++){
				edge.push_back({newPoints[i][u]+newPoints[i][v],{u,v}});
			}
		}
	}
	sort(edge.begin()+1,edge.end());
	cout << MST(edge,n,edge.size()-1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}