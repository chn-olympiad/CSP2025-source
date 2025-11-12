#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<__LINE__<<" : "<<#x<<" "<<x
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e4+5,mod=1e9+7;

struct node{
	int u, v, w;
	node(int a, int b, int c){u = a, v = b, w = c;}
	bool operator < (const node &s) const{return w < s.w;}
};
vector<node> mp;
int n, m, k;
int s[12], vis[12];
ll ans = 1e18;

struct DSU{
	vector<int> f;
	DSU(int n):f(n){iota(f.begin(), f.end(), 0);}
	int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}
	bool merge(int a, int b){
		int fa = find(a), fb = find(b);
		if(fa == fb){return false;}
		f[fa] = fb; return true; 
	}
	void clear(){iota(f.begin(), f.end(), 0);}
}ds(N + 10);

void solve(ll res){
	if(res > ans){return;}
	for(auto x : mp){
		int u = x.u, v = x.v, w = x.w;
		if(u > n && !vis[u - n]){continue;}
		if(ds.merge(u, v)){res += w;}
	} 
	ans = min(ans, res);
	ds.clear();
}

void dfs(int u, ll base){
	if(u == k + 1){return solve(base);}
	dfs(u + 1, base);
	vis[u] = true;
	dfs(u + 1, base + s[u]);
	vis[u] = false; 
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u, v, w; cin>>u>>v>>w;
    	mp.push_back(node(u, v, w));
	}
	for(int i=1;i<=k;i++){
		cin>>s[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			mp.push_back(node(i + n, j, w));
		}
	}
	sort(mp.begin(), mp.end());
	dfs(1, 0);
	cout<<ans<<"\n"; 
    return 0; 
}
