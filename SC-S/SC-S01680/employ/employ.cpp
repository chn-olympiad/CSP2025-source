#include <bits/stdc++.h>
#define gc getchar
#define ll long long
#define I inline
#define C const
using namespace std;
int rd() {
	int x = 0, f = 1; char c = gc();
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = gc(); }
	while(c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }
	return (x * f);
}

const int N = 500, P = 998244353;
I int add(C int & x, C int & y) { return x + y >= P ? x + y - P : x + y; }
I int sub(C int & x, C int & y) { return x < y ? x + P - y : x - y; }
I int mul(C int & x, C int & y) { return 1ll * x * y % P; }
I void ADD(int & x, C int & y) { x = add(x, y); }

int n, m, s[N + 1], c[N + 1], cnt, buc[N + 1], nw;
vector < vector < int > > f[N + 1][N + 1], g[N + 1]; // i, z, x, y
void Trs_right(int i, int z) {
	
}
void Solve() {
	n = rd(); m = rd();
	for(int i = 1; i <= n; ++ i) {
		s[i] = rd();
		cnt += (! s[i]);
	}
	for(int i = 1; i <= n; ++ i) {
		c[i] = rd();
		++ buc[c[i]];
	}
	for(int t = 0; t <= n; ++ t) {
		for(int i = 0; i <= n - cnt; ++ i) {
			f[t][i].resize(n - cnt + 1);
			for(int j = 0; j <= n - cnt; ++ j) { f[t][i][j].resize(n - cnt + 1); }
		}
	}
	f[0][0][0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		if(s[i] == 0) {
			for(int x = 0; x <= n - cnt; ++ x) for(int y = 0; y <= n - cnt; ++ y) for(int z = 0; z <= n - cnt; ++ z) {
				f[i][x][y][z] = f[i - 1][x][y][z];
			}
		} else {
			for(int z = 1; z <= n - cnt; ++ z) for(int j = 1; j <= buc[z - 1]; ++ j) Trs_right(i, z);
			for(int x = 0; x <= n - cnt; ++ x) for(int y = 0; y <= n - cnt; ++ y) for(int z = 0; z <= n - cnt; ++ z) {
				if(y < n - cnt && z >= 1) {
					ADD(f[i][x][y][z], mul(f[i - 1][x][y + 1][z - 1], y));
				}
				if(x >= 1) ADD(f[i][x][y][z], f[i - 1][x - 1][y][z]);
			}
		}
	}
	for(int z = 1; z <= n - cnt; ++ z) {
		int b = 0;
		for(int j = )
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	Solve();
	return 0;
}
/*
宁静的地平线 分开了生者和死者的行列
——北岛
*/