#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1e4 + 10;

int a[N],c[15];
int f[N],t[N],st[N];
LL dis[N];
vector<PII> g[1000010];
map<PII,int> r;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		r[{u,v}] = w;
		r[{v,u}] = w;
	}
	int idx = n;
	for(int i = 1;i <= k;i ++) {
		cin >> c[++idx];
		for(int i = 1;i <= n;i ++) {
			int y; scanf("%d",&y);
			g[idx].push_back({i,y});
			g[i].push_back({idx,y});
			r[{i,idx}] = y;
			r[{idx,i}] = y;
		}
	}
	sort(c + n,c + n + k);
	memset(dis,0x3f,sizeof dis);
	dis[1] = 0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,1});
	while(!q.empty()) {
		PII t = q.top(); q.pop();
		int u = t.second;
		if(st[u]) continue;
		st[u] = true;
		for(int i = 0;i < g[u].size();i ++) {
			PII ite = g[u][i];
			int v = ite.first,w = ite.second;
			if(v > n) {
				if(dis[v] > dis[u] + w + c[v]) {
					dis[v] = dis[u] + w + c[v];
					f[v] = u;
					//c[v] = 0;
					q.push({dis[v],v});
				}
			} else {
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					f[v] = u;
					q.push({dis[v],v});
				}
			}
		}
	}
//	for(int i = 1;i <= idx;i ++) {
//		cout << i << ' ' << f[i] << endl;
//	}
	for(int i = 1;i <= idx;i ++) t[f[i]] ++,t[i] ++;
	LL ans = 0;
	for(int i = n + 1;i <= idx;i ++) {
		if(t[i] <= 1) f[i] = 0;
		else ans += c[i]; 
	}
	for(int i = 1;i <= idx;i ++) {
		ans += r[{i,f[i]}];
		//cout << ans << ' ' << r[{i,f[i]}] << endl;
	}
	cout << ans << endl;
	return 0;
}
/*4 4 2
 1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/

