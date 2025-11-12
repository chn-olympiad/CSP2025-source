#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10020
int n, m, k, dp[N], c[N];
bool jl[N];
vector<pair<int, int>>ve[N];
priority_queue<pair<int, int>>pq;
int dfs(int st,int hf) {
	jl[st]=true;
	int ans=LLONG_MAX,zc=0,fl=0;
	for (auto edge : ve[st]) {
		int v = edge.first, w = edge.second;
		if(jl[v])continue;
		fl=1;
		if (c[v])w += c[v],zc=c[v], c[v] = 0;
		int an=dfs(v,hf+w);
		if(zc){
			c[v]=zc;
			if(an==hf+w)an-=c[v],fl=0;
		}
		ans=min(an,ans);
	}
	jl[st]=false;
	return (fl)?ans:hf;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int j = 1; j <= n + k; j++) ve[j].reserve(n + k);
	for (int j = 1, u, v, w; j <= m; j++) {
		cin >> u >> v >> w;
		ve[u].push_back({v, w});
		ve[v].push_back({u, w});
	}
	for (int j = n + 1; j <= n + k; j++) {
		cin >> c[j];
		for (int i = 1, w; i <= n; i++)cin >> w, ve[j].push_back({i, w}), ve[i].push_back({j, w});
	}
	cout<<dfs(1,0);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/