#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 10;
const int N = 1e4 + 10;
const int N2 = 20;
int f[N],n,m,k,c[N2],ww[N2][N],cnt;
ll ans;
struct edg{
	int u,v,w;
	bool operator < (const edg & b) const{
		return w > b.w;
	}
};
priority_queue<edg> q;
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
map<int,map<int,int> > mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			mp[i][j] = INF;
		}
	}
	for(int i = 1;i <= m;++i){
		int u,v,w;
		cin >> u >> v >> w;
		if(k == 0) q.push({u,v,w});
		mp[u][v] = mp[v][u] = min(w,min(mp[u][v],mp[v][u]));
	}
	for(int i = 1;i <= k;++i){
		cin >> c[i];
		for(int j = 1;j <= n;++j){
			cin >> ww[i][j];
		}
	}
	for(int i = 1;i <= n;++i){
		f[i] = i;
	}
	for(int i = 1;i <= k;++i){
		for(int j = 1;j <= n;++j){
			for(int k2 = 1;k2 <= n;++k2){
				if(ww[i][j] + ww[i][k2] + c[i] < mp[j][k2]){
					mp[j][k2] = mp[k2][j] = ww[i][j] + ww[i][k2] + c[i];
				}
			}
		}
	}
	if(k != 0){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				if(mp[i][j] != INF) q.push({i,j,mp[i][j]});
			}
		}
	}
	for(int i = 1;i <= m;++i){
		if(cnt == n - 1) break;
		edg d = q.top();
		q.pop();
		int fx = find(d.u);
		int fy = find(d.v);
		if(f[fx] != f[fy]){
			f[fx] = fy;
			ans += d.w;
			cnt++;
		}
	}
	cout << ans;
	return 0;
}
