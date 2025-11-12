#include <bits/stdc++.h>
#define mpr(a, b) make_pair(a, b)
#define pii pair<int, int>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, tmp[N];
struct node {
	pii a[3];
}p[N];
inline int read() {
	int now = 0, nev = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch) {
		if (ch == '-') nev = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		now = (now << 1) + (now << 3) + (ch & 15);
		ch = getchar();
	}
	return nev * now;
}
bool cmp(node x, node y) {
	if (x.a[2] != y.a[2])
		return x.a[2] > y.a[2];
	return x.a[1] > y.a[1];
}
void solve() {
	n = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) 
			p[i].a[j] = mpr(read(), j);
		sort(p[i].a, p[i].a + 3);
	}
	sort(p + 1, p + 1 + n, cmp);
	priority_queue<pii> que[3];
	int cnt[3] = {0, 0, 0}, res = 0;
	for (int i = 1; i <= n; i++) {
		pii x = p[i].a[2];
		cnt[x.second]++;
		que[x.second].push(mpr(-x.first, i));
		res += x.first;
	}
	int pos = 3, tot = 0;
	for (int i = 0; i < 3; i++) if (cnt[i] > n / 2) pos = i;
	if (pos != 3) {
		while (!que[pos].empty()) {
			pii t = que[pos].top();
			tmp[++tot] = t.first + p[t.second].a[1].first;
			que[pos].pop();
		}
		sort(tmp + 1, tmp + 1 + tot);
		for (int i = 1; i <= cnt[pos] - n / 2; i++)
			res += tmp[tot - i + 1];
	}
	printf("%lld\n", res);
	return;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T--)
		solve();
	return 0;
}
