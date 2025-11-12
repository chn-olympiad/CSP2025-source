#include <bits/stdc++.h>
//#define int long long
#define maxn 11000
#define maxm 2000100
#define ll long long
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -f;ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch -'0'; ch = getchar();}
	return x * f;
}
int fa[maxn];
int find(int x) {
	if (fa[x] == x) {
		return fa[x];
	}
	return fa[x] = find(fa[x]);
}
int n, m, k;
struct edge {
	int to, val, nxt, fro;
}e[maxm << 1], cpye[maxm << 1];
bool cmp (const edge a, const edge b) {
	return a.val < b.val;
}
int head[maxn], cnt = 0;
void add(int u, int v, int w) {
	e[++cnt].nxt = head[u];
	e[cnt].fro = u;
	e[cnt].to = v;
	e[cnt].val = w;
	head[u] = cnt;
}
int c[15];
int a[15][maxn];
int usk[15];
int ndg[maxm], tdg[maxm], vdg[maxm];
int iptm;
ll dfs(int kth, int op) {
	if (kth == 0) {
		return min(dfs(kth + 1, 0), dfs(kth + 1, 1));
	}
	if (kth == k) {
		usk[kth] = op;
		//solve
		int tmp = 0;
		for (int i = 1; i <= k; i++) {
			if (usk[i] == 1) tmp++;
			for (int j = 1; j <= n; j++) {
				if (usk[i] == 1){
					m ++;
//					cerr << i << " " << j << " " << a[i][j] << endl;
//					if (a[i][j] == 0) system("pause");
					add(tmp + n, j, a[i][j]); add(j, tmp + n, a[i][j]);
				}
			}
		}
		sort(e + 1, e + m * 2 + 1, cmp);
		ll ans = 0;
		for (int i = 1; i <= m * 2; i++) {
			int u = e[i].fro, v = e[i].to;
			if (find(u) == find(v)) continue;
			else {
//				cerr << u << " " << v << " " << e[i].val << endl;
				fa[find(u)] = find(v);
				ans += e[i].val;
			}
		}
		for (int i = 1; i <= k; i++) {
			if (usk[i] == 1) ans += c[i];
		}
		
		memset(e, 0, sizeof(e));
		memset(head, 0, sizeof(head));
		cnt = 0;
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		
		m = iptm;
		for (int i = 1; i <= m; i++) {
			add(ndg[i], tdg[i], vdg[i]);
			add(tdg[i], ndg[i], vdg[i]);
		}
//		for (int i = 1; i <= k; i++) {
//			cout << usk[i] ;
//		}
//		cout << "  " << ans << endl;
		return ans;
		//memset! 
	}
	usk[kth] = op;
//	cerr << kth << endl;
	return min(dfs(kth + 1, 0), dfs(kth + 1, 1));
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	iptm = m;
	for (int i = 1; i <= m; i++) {
		int u, v, vv;
		u = read(); v = read(); vv = read();
		ndg[i] = u; tdg[i] = v; vdg[i] = vv;
		add(u, v, vv); add(v, u, vv);
	}
	int cmax = 0;
	for (int i = 1; i <= k; i++) {
		c[i] = read(); 
		cmax = max(c[i], cmax);
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	if (k == 0) {
		sort(e + 1, e + m * 2 + 1, cmp);
		ll ans = 0;
		for (int i = 1; i <= m * 2; i++) {
			int u = e[i].fro, v = e[i].to;
			if (find(u) == find(v)) continue;
			else {
				fa[find(u)] = find(v);
				ans += e[i].val;
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (cmax == 0) {
		for (int i = 1; i <= k; i++) {
			int val0 = 0;
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 0) {
					val0 = j;
				}
			}//多了一堆点的mst 
			for (int j = 1; j <= n; j++) {
				m ++;
				if (j != val0) {
					add(val0, j, a[i][j]); add(j, val0, a[i][j]);
				}
			}//1736
		}
		sort(e + 1, e + m * 2 + 1, cmp);
		ll ans = 0;
		for (int i = 1; i <= m * 2; i++) {
			int u = e[i].fro, v = e[i].to;
			if (find(u) == find(v)) continue;
			else {
				fa[find(u)] = find(v);
				ans += e[i].val;
			}
		}
		cout << ans << endl;
		return 0;
	}
	else {
		ll ans = dfs(0, 0);
		cout << ans << endl;
		return 0;
	}
	return 0;
}

/*
5 6 0
1 2 3
1 2 4
2 3 4
3 4 5
4 5 5
2 5 1


4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
