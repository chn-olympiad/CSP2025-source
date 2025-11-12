#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
const int MAXN = 10000000;

struct Val {
	int v, tag;
	bool operator <(const Val &x)const {
		return v > x.v;
	}
};
Val a[N], b[N], c[N];
int cnta, cntb, cntc, cnt;
bool ce = false;
long long ans;
int t, n, lim;
bool used[N];

int read() {
	int s = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		s = (s << 3) + (s << 1) + (ch^'0');
		ch = getchar();
	}
	return s;
}

void dfs(int cur, int as, int bs, int cs, long long v) {
	if (cnt++ > MAXN)
		return;
	if (cur > n) {
		ans = max(ans, v);
		return;
	}
	int av = 0, bv = 0, cv = 0;
	if (as < lim)
		av = a[cur].v;
	if (bs < lim)
		bv = b[cur].v;
	if (cs < lim)
		cv = c[cur].v;
	if (av >= bv && av >= cv) {
		dfs(cur + 1, as + 1, bs, cs, v + av);
		if (bv >= cv) {
			dfs(cur + 1, as, bs + 1, cs, v + bv);
			dfs(cur + 1, as, bs, cs + 1, v + cv);
		} else {
			dfs(cur + 1, as, bs, cs + 1, v + cv);
			dfs(cur + 1, as, bs + 1, cs, v + bv);
		}
	} else if (bv >= av && bv >= cv) {
		dfs(cur + 1, as, bs + 1, cs, v + bv);
		if (av >= cv) {
			dfs(cur + 1, as + 1, bs, cs, v + av);
			dfs(cur + 1, as, bs, cs + 1, v + cv);
		} else {
			dfs(cur + 1, as, bs, cs + 1, v + cv);
			dfs(cur + 1, as + 1, bs, cs, v + av);
		}
	} else {
		dfs(cur + 1, as, bs, cs + 1, v + cv);
		if (av >= bv) {
			dfs(cur + 1, as + 1, bs, cs, v + av);
			dfs(cur + 1, as, bs + 1, cs, v + bv);
		} else {
			dfs(cur + 1, as, bs + 1, cs, v + bv);
			dfs(cur + 1, as + 1, bs, cs, v + av);
		}
	}
}

void solve() {
	cnt = 0;
	if (ce || n < 500) {
		dfs(1, 0, 0, 0, 0);
		return;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	cnta = 0;
	cntb = 0;
	cntc = 0;
	int pa = 1, pb = 1, pc = 1;
	while (cnt < n) {
		int av = 0, bv = 0, cv = 0;
		if (cnta < lim) {
			while (used[a[pa].tag])
				++pa;
			av = a[pa].v;
		}
		if (cntb < lim) {
			while (used[b[pb].tag])
				++pb;
			bv = b[pb].v;
		}
		if (cntc < lim) {
			while (used[c[pc].tag])
				++pc;
			cv = c[pc].v;
		}
		if (av >= bv && av >= cv) {
			ans += av;
			++cnta;
			used[a[pa].tag] = true;
		} else if (bv >= av && bv >= cv) {
			ans += bv;
			++cntb;
			used[b[pb].tag] = true;
		} else {
			ans += cv;
			++cntc;
			used[c[pc].tag] = true;
		}
		++cnt;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		lim = n >> 1;
		for (int i = 1; i <= n; ++i)
			used[i] = false;
		for (int i = 1; i <= n; ++i) {
			a[i].v = read();
			b[i].v = read();
			c[i].v = read();
			if (c[i].v)
				ce = true;
			a[i].tag = i;
			b[i].tag = i;
			c[i].tag = i;
		}
		solve();
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}