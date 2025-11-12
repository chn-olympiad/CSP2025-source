#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 50, M = 1e4 + 50, MAXN = 2e9 + 1;
ll n, m, k, c[20];
ll f[M], V_C[15][M];
struct Node{
	ll u, v, w;
	bool ok;
}e[N];
bool cmp(Node LL, Node RR) {
	return LL.w < RR.w;
}
bool vis[15][M];
void Take_In();
ll To_Find(int x) {
	while (x != f[x]) x = f[x] = f[f[x]];
	return x;
}
ll read() {
	ll f = 1, x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x *= 10;
		x += (c - '0');
		c = getchar();
	}
	
	return x * f;
}
int main(){
//	freopen("road3.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	Take_In();
	
	ll ans = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (cnt == n - 1) break;
		ll Fx = To_Find(e[i].u), Fy = To_Find(e[i].v);
		if (Fx != Fy) {
			f[Fx] = Fy;
			ans += e[i].w;
			e[i].ok = true;
			cnt++;
		}
	}
	
	
	for (int i = m; i >= 1; i--) {
		if (e[i].ok == false) continue;
		
		ll MIN = MAXN, I1, I2, J;
		for (int j = 1; j <= k; j++) {
			ll tmp = V_C[j][e[i].u] + V_C[j][e[i].v];
			if (vis[j][e[i].u] == true) tmp -= V_C[j][e[i].u];
			if (vis[j][e[i].v] == true) tmp -= V_C[j][e[i].v];
			
			if (tmp < MIN) {
				MIN = tmp;
				J = j, I1 = e[i].u, I2 = e[i].v;
			}
		}
		
		if (e[i].w >= MIN) {
			// 砍掉原来的路 
			ans -= e[i].w;
			if (vis[J][I1] == false) {
				// 新的路 
				vis[J][I1] = true;
				ans += V_C[J][I1];
			}
			if (vis[J][I2] == false) {
				vis[J][I2] = true;
				ans += V_C[J][I2];
			}
		}
	}
	
	cout << ans;
	return 0;
}
void Take_In() {
	n = read(), m = read(), k = read();
	
	for (int i = 1; i <= m; i++) {
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
		e[i].ok = false;
	}
	
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) {
			V_C[i][j] = read();
		}
	}
	
	sort(e + 1, e + m + 1, cmp);
	// 并查集 初始化  
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	
	return ;
}