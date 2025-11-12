#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		int u = ch - 48;
		x = (x << 1) + (x << 3) + u;
		ch = getchar();
	}
	return f * x;
}

inline void write(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n > 9)
		write(n / 10);
	char c = n % 10 + 48;
	putchar(c);
}
int n, m, k;
int ans = 1e18;
const int N = 2e4+10;
int h[N];

int gen(int x) {
	if (x != h[x]) {
		h[x] = gen(h[x]);
	}
	return h[x];
}

struct side {
	int s, t, v;
};

bool cmp(side a, side b) {
	return a.v < b.v;
}
vector<side> G1;
int cit[12][N];
int ycit[12];
int ynd;

inline int solve(int zipmap, vector<side> G2) {
	//cout << zipmap << " " ;
	int nn = n;
	int cnt = 0;
	int ki = 1;
	while (zipmap) {
		if (zipmap & 1) {
			for (int j = 1; j <= ynd; j++) {
				int w = cit[ki][j];
				G2.push_back({nn + 1, j, w});
			}
			nn++;
			cnt += ycit[ki];
		}
		ki++;
		zipmap >>= 1;
	}
	for (int i = 1; i <= nn; i++)
		h[i] = i;
	sort(G2.begin(), G2.end(), cmp);
	for (int i = 0; i < (int)G2.size(); i++) {
		int u = G2[i].s, v = G2[i].t, w = G2[i].v;
		//	cout << w << " ";
		if (h[gen(u)] == h[gen(v)]) {
			continue;
		} else {
			cnt += w;
			h[gen(u)] = gen(v);
		}
	}
//	cout << cnt << endl;
	return cnt;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	//int n;
	//cin >> n;
	//cout << n + 1;
	n = read(), m = read(), k = read();
	ynd = n;
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		G1.push_back({u, v, w});
	}
	for (int i = 1; i <= k;) {
		int ci = read();
		if (ci == 0) {
			k--;
			for (int j = 1; j <= ynd; j++) {
				int w = read();
				G1.push_back({n + 1, j, w});
			}
			n++;
		} else {
			ycit[i] = ci;
			for (int j = 1; j <= n; j++) {
				cit[i][j] = read();
			}
			i++;
		}
	}
	for (int i = 1; i <= n; i++)
		h[i] = i;
	if (k == 0) {
		ans = 0;
		sort(G1.begin(), G1.end(), cmp);
		for (int i = 0; i < (int)G1.size(); i++) {
			int u = G1[i].s, v = G1[i].t, w = G1[i].v;
			if (h[gen(u)] == h[gen(v)])
				continue;
			else {
				ans += w;
				h[gen(u)] = gen(v);
			}
		}
	} else {
		int muy = (1 << (k )) - 1;
		for (int i = 0; i <= muy; i++) {
			ans = min(solve(i, G1), ans);
		}
	}
	//cout << n << " " << m << " " << k << endl;
	write(ans);
	return 0;
}
