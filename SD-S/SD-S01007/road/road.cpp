#include<bits/stdc++.h>
using namespace std;
#define int long long
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Rof(i, a, b) for(int i = (a); i >= (b); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)
template<typename T>void cmax(T &x, T y){x = max(x, y);}
template<typename T>void cmin(T &x, T y){x = min(x, y);}
const int N = 2e4 + 5, inf = 2e9;
struct edge{
	int u, v, w;
}e1[1000005], e2[N << 4];
int n, m, k, cnt, c[N], a[12][N], ff[N], siz[N], bl[N];
int find(int x){
	if(x == ff[x]) return x;
	return ff[x] = find(ff[x]);
}
void merge(int x, int y){
	if(siz[x] > siz[y]) swap(x, y);
	ff[x] = y; siz[y] += siz[x];
}
void Solve(){
	cin >> n >> m >> k;
	//Debug("n=%lld m=%lld k=%lld\n", n, m, k);
	For(i, 1, m) cin >> e1[i].u >> e1[i].v >> e1[i].w;
	For(i, 1, k){
		cin >> c[i];
		For(j, 1, n) cin >> a[i][j];
	}
	sort(e1 + 1, e1 + m + 1, [](edge a, edge b){return a.w < b.w;});
	For(i, 1, n) ff[i] = i, siz[i] = 1;
	int mst = 0;
	For(i, 1, m){
		int u = find(e1[i].u), v = find(e1[i].v);
		if(u == v) continue; mst += e1[i].w;
		merge(u, v); e2[++cnt] = e1[i];
	}
	For(i, 1, n) For(j, 1, k) e2[++cnt] = {i, n + j, a[j][i]};
	sort(e2 + 1, e2 + cnt + 1, [](edge a, edge b){return a.w < b.w;});
	int ans = mst;
	For(S, 1, (1 << k) - 1){
		int sum = 0, tot = 0;
		For(i, 1, k) if((S >> i - 1) & 1) sum += c[i];
		For(i, 1, n + k) ff[i] = i, siz[i] = 1;
		int num = 0, way = n + __builtin_popcount(S) - 1;
		For(i, 1, cnt){
			if(e2[i].v > n && !((S >> e2[i].v - n - 1) & 1)) continue;
			int u = find(e2[i].u), v = find(e2[i].v);
			if(u == v) continue; sum += e2[i].w, merge(u, v);
			++num; if(num == way) break;
		}
		cmin(ans, sum);
	}
	cout << ans << '\n';
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1; //cin >> T;
	while(T--) Solve();
	return 0;
}
