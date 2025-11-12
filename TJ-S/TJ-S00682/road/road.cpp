#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k;
vector<pair<int,int> > f[100005];
int fa[100005];
int ans;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void sry(){
	int p = 1;
	while(q.size() && p < n+k){
		pair<int,pair<int,int> > x = q.top();
		q.pop();
		int u = x.second.first,v = x.second.second,w = x.first;
		if(find(u) != find(v)){
			fa[find(u)] = v;
			ans += w;
			p++;
		}
	}
}


signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		q.push({w,{u,v}});
	}
	int t;
	for(int i = 1;i <= k;i++){
		cin >> t;
		for(int j = 1;j <= n;j++){
			cin >> t;
		}
	}
	sry();
	cout << ans;
} 
