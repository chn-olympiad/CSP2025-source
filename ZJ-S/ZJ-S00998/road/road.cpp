#include<bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; a++)
#define reps(a, b, c) for(int a = b; a > 0; a--)
#define int long long

using namespace std;

const int N = 1e5 + 7;

struct edge{
	int u, v, w;
}e[N << 4], tem[N << 4];

int n, m, k, cnt, cnt2, x, y, z, q;
int c[15][N], f[N], ans = 2e15, res;
double t;

void add(int u, int v, int w){
	e[++cnt] = {u, v, w};
}

void add2(int u, int v, int w){
	tem[++cnt2] = {u, v, w};
}

int find(int x){
	return x == f[x] ? f[x] : f[x] = find(f[x]);
}


void rebuild(int stu){
	rep(i, 1, m) tem[i] = e[i];
	
	rep(i, 1, k){
		if (stu & (1 << i - 1)){
			res += c[i][0], q++;
			rep(j, 1, n) add2(n + i, j, c[i][j]);
		}
	}
}

void solve(){
	int tot = 0;
	rep(i, 1, n + 10) f[i] = i;
	sort(tem + 1, tem + 1 + cnt2, [](edge a, edge b){
		return a.w < b.w;
	});
	
	int it1 = 1, it2 = 1;
	
	while(1){
		if (((clock() - t) / 1000 >= 0.97)){
			res = 2e15;
			return;
		}
		int u = 0, v = 0, w = 0;
		
		if (e[it1].w < tem[it2].w || it2 > q * n){
			u = find(e[it1].u), v = find(e[it1].v), w = e[it1].w;
			it1++;
		}else{
			u = find(tem[it2].u), v = find(tem[it2].v), w = tem[it2].w;
			it2++;
		}
		if (u == v) continue;
		f[v] = u, res += w, tot++;
		if (tot == n + q - 1) break;
	}
}

inline int read(){
	char s;
	int x = 0;
	s = getchar();
	while (s < '0' || s > '9') s = getchar();
	while (s >= '0' && s <= '9'){
		x = (x << 3) + (x << 1) + s - '0';
		s = getchar();
	}
	return x;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	t = clock();
	n = read(), m = read(), k = read();
	rep(i, 1, m) x = read(), y = read(), z = read(), add(x, y, z);
	
	sort(e + 1, e + 1 + m, [](edge a, edge b){
		return a.w < b.w;
	});
	
	rep(i, 1, k){
		cin >> c[i][0];
		rep(j, 1, n) cin >> c[i][j];
	}
	
	for (int i = (1 << k) - 1; i >= 0 && ((clock() - t) / 1000 < 0.8); i--){
		cnt2 = 0, res = q = 0;
		rebuild(i);
		solve();
		ans = min(ans, res);
	}
	for (int i = 0; i <= (1 << k) - 1 && ((clock() - t) / 1000 < 0.97); i++){
		cnt2 = 0, res = q = 0;
		rebuild(i);
		solve();
		ans = min(ans, res);
	}
	cout << ans << "\n";

	return 0;
}

