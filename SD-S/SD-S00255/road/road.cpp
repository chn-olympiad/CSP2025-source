#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define sf std :: flush
#define lowbit(x) (x & (-x))
#define endl '\n'
const int N = 1e4 + 1;
int a[15],n,m,k,test[2000];
vector<pair<int,int> > e[N+10];
vector<bool> vis(N+10,0);
ll Prim(int t,int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	vis[1] = 1;
	ll res = 0; t--;
	for(int i = 0;i < e[1].size();i++) if(e[1][i].second <= n || (x & (1 << (e[1][i].second - n - 1)))) q.push(e[1][i]);
	while(!q.empty()){
		int u = q.top().second,w = q.top().first;  q.pop();
		if(vis[u]) continue;
		res += w;
		vis[u] = 1; t--;
		if(!t) break;
		for(int i = 0;i < e[u].size();i++){
			int v = e[u][i].second;
			if(vis[v] || v > n && !(x & (1 << (v - n - 1)))) continue;
			q.push(e[u][i]);
		}
	}
	for(int i = 1;i <= n+k;i++) vis[i] = 0;
	return res;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0;i < k;i++) test[1<<i] = i;
	int u,v,w;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		e[u].push_back({w,v});
		e[v].push_back({w,u});
	}
	for(int i = 1;i <= k;i++) for(int j = 0;j <= n;j++){
		if(j == 0) cin >> a[i];
		else{
			cin >> w;
			e[i+n].push_back({w,j});
			e[j].push_back({w,i+n});
		}
	}
	ll ans,l;
	ans = l = Prim(n,0);
	int bad = 0;
	for(int i = 0;i < k;i++){
		ll t = a[i+1] + Prim(n+1,1<<i);
		bad |= (1 << i) * (t >= l);
		ans = min(ans,t);
	}
	int mi = 1 << k;
	for(int i = 3;i < mi;i++){
		if(i & bad || i == lowbit(i)) continue;
		ll t = 0,cnt = n; 
		int x = i;
		while(x){
			int j = test[lowbit(x)] + 1;
			t += a[j]; cnt++;
			x -= lowbit(x);
		}
		t += Prim(cnt,i);
		ans = min(ans,t);
	}
	cout<<ans<<endl;
	cout<<sf;
    fclose(stdin);
    fclose(stdout);
	return 0;
}


