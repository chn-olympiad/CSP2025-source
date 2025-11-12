#include<bits/stdc++.h>
using namespace std;
#define I inline
#define gc getchar
#define int long long
const int N = 10050, M = 1000010, K = 12;
int c[K], w[K][N], ans, n, m, k, rt[N], val[K];
struct edge {
	int a, b, c;
} e[M], tr[N];
I bool cmp(edge a, edge b) {
	return a.c < b.c;
}
I int read() {
	int x = 0; char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
	return x;
}
I int find(int x) {
	return rt[x] == x ? x : rt[x] = find(rt[x]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) e[i].a = read(), e[i].b = read(), e[i].c = read();
	int tot = 0;
	stable_sort(e + 1, e + 1 + m, cmp);
	for(int i = 1; i <= n; i++) rt[i] = i;
	for(int i = 1; i <= m; i++) {
		int x = find(e[i].a), y = find(e[i].b);
		if(x != y) {
			rt[y] = x;
			tr[++tot] = e[i];
			ans += e[i].c;
		}
		if(tot == n - 1) break;
	}
	for(int i = 0; i < k; i++) {
		val[i] = read();
		for(int j = 1; j <= n; j++) {
			w[i][j] = read();
		}
	}
//	cout << ans << '\n';
	for(int i = 1; i < (1 << k); i++) {
		int sum = 0, cnt = 0;
		for(int j = 1; j < n; j++) e[j] = tr[j]; tot = n - 1;
		for(int j = 0; j < k; j++) if(i & (1 << j)) {
			sum += val[j]; cnt++;
			for(int o = 1; o <= n; o++) {
				e[++tot] = {j + n + 1, o, w[j][o]};
			}
		}
//		for(int j = 1; j < n; j++) {
//			for(int o = 0; o < k; o++) if(i & (1 << o)) {
//				if(tr[j].c > w[o][tr[j].a] + w[o][tr[j].b]) {
//					cout << i << ' ' << j << ' ' << o << '\n' << tr[j].a << ' ' << tr[j].b << " zztql " << tr[j].c << '\n';
//					sum = sum - tr[j].c + w[o][tr[j].a] + w[o][tr[j].b];
//				}
//			}
//		}
//		cout << i << ' ' << sum << ' ' << tot << '\n';
		for(int j = 1; j <= n + k; j++) rt[j] = j;
		stable_sort(e + 1, e + 1 + tot, cmp);
		int E = 0;
		for(int j = 1; j <= tot; j++) {
			int x = find(e[j].a), y = find(e[j].b);
			if(x != y) {
				rt[y] = x;
				E++;
				sum += e[j].c;
			}
			if(E == n + cnt - 1) break;
		}
//		cout << "i = " << i << ' ' << sum << '\n';
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
