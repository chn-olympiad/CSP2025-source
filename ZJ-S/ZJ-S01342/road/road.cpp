#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##END = (r); i <= i##END; i ++)
#define dwn(i, l, r) for (int i = (l), i##END = (r); i >= i##END; i --)
#define int long long
using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
struct Edge{
	int u, v, w;
	bool operator < (const Edge &nd) const{
		return w < nd.w;
	}
} t[M];
int fa[N], g[K][N], c[N], mx[K], se[K];
bitset<N> vis[K]; int cnt[K], zr[K];
vector<Edge> chs;
int n, m, k;

// RP += INF
// hao jue wang, wo zen me you lang fei le yi nian, xie bu chu zhe tang ti.
// hao xiang zhao ge di fang ku.

int get(int x){ return x == fa[x] ? x : fa[x] = get(fa[x]); }

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m >> k; rep(i, 1, m){
		cin >> t[i].u >> t[i].v >> t[i].w;
	} rep(i, 1, k){
		cin >> c[i]; 
		rep(j, 1, n) cin >> g[i][j];
	} rep(i, 1, n) fa[i] = i;
	sort(t + 1, t + m + 1);
	int ans = 0; 
	rep(i, 1, m){
		int l = t[i].u, r = t[i].v; if (get(l) == get(r)) continue;
		fa[get(l)] = get(r); chs.push_back(t[i]); ans += t[i].w;
	} reverse(chs.begin(), chs.end());
	
	rep(i, 1, k){
		mx[i] = -1, se[i] = -1;
		rep(j, 1, n){
			if (mx[i] == -1 || g[i][mx[i]] > g[i][j]) mx[i] = j;
			else if (se[i] == -1 || g[i][se[i]] > g[i][j]) se[i] = j;
		}
	} 
	
	int res = 1e18;
	rep(st, 0, (1 << k) - 1){
		int bas = 0; vector<int> cg; int now = ans;
		rep(i, 1, k) if ((st >> (i - 1)) & 1) bas += c[i],
			cg.push_back(i);
		rep(i, 1, k) vis[i].reset(), cnt[i] = 0;
		rep(i, 0, n - 2){
			int L = chs[i].u, R = chs[i].v, cst = chs[i].w;
			now -= cst;
			int dis = cst, st = 0, tar = 0, id = 0;
//			cout << L << ' ' << R << ' ' << cst << '\n';
			for (int u : cg){
				int disL = 1e18, tarL;
				if (mx[u] == L)
					if ((!vis[u][L]) && (!vis[u][se[u]]))
						disL = g[u][L] + g[u][se[u]], tarL = se[u];
				else if ((!vis[u][L]) && (!vis[u][mx[u]]))
					disL = g[u][L] + g[u][mx[u]], tarL = mx[u];
				
				int disR = 1e18, tarR;
				if (mx[u] == R) 
					if ((!vis[u][R]) && (!vis[u][se[u]]))
						disR = g[u][R] + g[u][se[u]], tarR = se[u];
				else if ((!vis[u][R]) && (!vis[u][mx[u]]))
					disR = g[u][R] + g[u][mx[u]], tarR = mx[u];
				
				if (disR > dis && disL > dis) continue;
				if (disL < disR) dis = disL, st = L, tar = tarL, id = u;
				else dis = disR, st = R, tar = tarR, id = u;
			}
//			cout << dis << ' ' << id << ' ' << st << ' ' << tar << '\n';
			now += dis; if (id != 0) vis[id][st] = 1, vis[id][tar] = 1;
		} res = min(res, now + bas);
	}
	
	cout << res;
	return 0;
}