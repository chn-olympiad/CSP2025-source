#include <bits/stdc++.h>
using namespace std;

struct aaa {
	long long u, v, w;
} t[2000000];
long long n, m, k, cnt, c[20], ans, d, bs;
long long fa[20000];

long long kr() {
	long long a = 0, b;
	bool f = false;
	char c;
	c = getchar();
	if (c == '-') {
		c = getchar();
		f = true;
	}
	b = c - '0';
	while (b >= 0 && b <= 9) {
		a = a * 10 + b;
		c = getchar();
		b = c - '0';
	}
	if (f) {
		a = a * (-1);
	}
	return a;
}

bool cmp(aaa a, aaa b) {
	return a.w < b.w;
}

long long father(long long a) {
	if (fa[a] == a) {
		return a;
	}
	fa[a] = father(fa[a]);
	return fa[a];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = kr();
	m = kr();
	k = kr();
	for (int i = 1; i <= m; i++) {
		cnt++;
		t[cnt].u = kr();
		t[cnt].v = kr();
		t[cnt].w = kr();
	}
	for (int i = 1; i <= k; i++) {
		c[i] = kr();
		ans = ans + c[i];
		for (int j = 1; j <= n; j++) {
			cnt++;
			t[cnt].u = n + i;
			t[cnt].v = j;
			t[cnt].w = kr();
		}
	}
	d = n + k;
	for (int i = 1; i <= d; i++) {
		fa[i] = i;
	}
	sort(t + 1, t + 1 + cnt, cmp);
	long long u, v, w;
	bs = 1;
	for (int i = 1; i <= cnt; i++) {
		u = t[i].u;
		v = t[i].v;
		w = t[i].w;
		if (bs >= d) {
			printf("%lld", ans);
			fclose(stdin);
			fclose(stdout);
			return 0;
			break;
		}
		if (father(u) != father(v)) {
			fa[fa[u]] = std::min(fa[u], fa[v]);
			fa[fa[v]] = std::min(fa[u], fa[v]);
			ans = ans + w;
			bs++;
		}
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
