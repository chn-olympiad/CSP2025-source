#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l);i<=(r);++i)
#define per(i, r, l) for(int i(r);i>=(l);--i)
using namespace std;

template <typename T>
inline void read(T &x){
	x = 0;
	static char c;
	static bool f;
	c = getchar(), f = 0;
	while(c<'0'||c>'9'){ if(c == '-')f = 1; c = getchar(); }
	while('0'<=c&&c<='9')x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	x = f ? -x : x;
}

const int N = 1e4 + 50, M = 1.5e6 + 10;
using ll = long long;
int n,m,k;
int c[20];
int a[11][N];

struct node{
	int u, v, w;
	bool friend operator <(const node &a,const node &b){
		return a.w < b.w;
	}
}e[M];

namespace sub1{
	int fa[N];
	int find(int x){ return fa[x] == x ? x : fa[x] = find(fa[x]); }
	void solve(){
		sort(e+1,e+m+1);
		rep(i, 1, n)fa[i] = i;
		ll ans = 0;
		int ct = 0;
		rep(i, 1, m){
			int x = find(e[i].u), y = find(e[i].v);
			if(x == y)continue;
			++ct;
			fa[x] = y;
			ans += e[i].w;
			if(ct == n-1)break;
		}
		printf("%lld\n",ans);
	}
}

bool mk[20];
bool vis[N];
ll dis[N];
vector<pair<int,int> > g[N];
ll prim(){
	rep(i, 1, n+k)dis[i] = 1e18, vis[i] = 0;
	dis[1] = 0;
	ll res = 0;
	rep(tim, 1, n+k){
		int ps = 0;
		rep(i, 1, n)if(!vis[i]){
			if(!ps)ps = i;
			else if(dis[ps] > dis[i])ps = i;
		}
		rep(i, 1, k)if(!vis[i+n] && !mk[i]){
			if(!ps)ps = i+n;
			else if(dis[ps] > dis[i+n])ps = i+n;
		}
		if(!ps)continue;
		vis[ps] = 1;
		res += dis[ps];
		if(ps > n){
			rep(i, 1, n)if(!vis[i] && dis[i] > a[ps-n][i])
				dis[i] = a[ps-n][i];
		}else{
			for(const pair<int,int> &p : g[ps]){
				int v = p.first, w = p.second;
				if(!vis[v] && dis[v] > w)dis[v] = w;
			}
			rep(i, 1, k)if(!vis[i+n] && !mk[i] && dis[i+n] > a[i][ps])
				dis[i+n] = a[i][ps];
		}
	}
	return res;
}

namespace sub2{
	void solve(){
		rep(i, 1, m)
			g[e[i].u].emplace_back(e[i].v, e[i].w),
			g[e[i].v].emplace_back(e[i].u, e[i].w);
		
		ll ans = -1;
		rep(st, 0, (1<<k)-1){
			ll res = 0;
			rep(i, 1, k){
				if(st >> (i-1) & 1)
					res += c[i], mk[i] = 0;
				else
					mk[i] = 1;
			}
			res += prim();
			if(ans == -1)ans = res;
			else ans = min(ans, res);
		}
		printf("%lld\n",ans);
	}
}

namespace sub3{
	inline bool check(){
		rep(i, 1, k)if(c[i])return false;
		rep(i, 1, k){
			bool flag = 0;
			rep(j, 1, n)if(!a[i][j])flag = 1;
			if(!flag)return false;
		}
		return true;
	}
	void solve(){
		rep(i, 1, m)
			g[e[i].u].emplace_back(e[i].v, e[i].w),
			g[e[i].v].emplace_back(e[i].u, e[i].w);
		printf("%lld\n",prim());
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

//	double tim = clock();

	read(n), read(m), read(k);
	rep(i, 1, m)read(e[i].u), read(e[i].v), read(e[i].w);
	rep(i, 1, k){
		read(c[i]);
		rep(j, 1, n)read(a[i][j]);
	}
	if(!k)
		sub1::solve();
	else if(sub3::check())
		sub3::solve();
	else
		sub2::solve();
		
//	cerr << 1.0*(clock()-tim)/CLOCKS_PER_SEC*1000<<"Ms\n";
	
	return 0;
}