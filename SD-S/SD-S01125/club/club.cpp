#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

const int Maxn = 1e5 + 4;

inline ll Read() {
	char ch = getchar();
	ll ct = 0, lve = 1;

	while (ch < '0' || ch > '9') {
		if (ch == '-')
			lve = -lve;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ct = (ct << 3) + (ct << 1) + ch - '0';
		ch = getchar();
	}
	return ct * lve;
}
inline void Write(ll x) {
	if (x < 0)
		x = -x;
	if (x > 9)
		Write(x / 10);
	putchar(x % 10 + '0');
}

inline ll max(ll x, ll y) {
	return x > y ? x : y;
}
inline ll min(ll x, ll y) {
	return x < y ? x : y;
}

int n, m, v[Maxn];
struct A {
	ll d1, d2, d3;
} a[Maxn];

inline bool cmp1 (int x, int y) {
	int z1 = max(a[x].d2, a[x].d3), z2 = max(a[y].d2, a[y].d3);
	return a[x].d1 - z1 < a[y].d1 - z2;
}
inline bool cmp2 (int x, int y) {
	int z1 = max(a[x].d1, a[x].d3), z2 = max(a[y].d1, a[y].d3);
	return a[x].d2 - z1 < a[y].d2 - z2;
}
inline bool cmp3(int x, int y) {
	int z1 = max(a[x].d1, a[x].d2), z2 = max(a[y].d1, a[y].d2);
	return a[x].d3 - z1 < a[y].d3 - z2;
}

std::vector <int> v1, v2, v3;
ll ans;

inline void Solve() {
	for (int i = 1; i <= n; ++i) {
		if (a[i].d1 >= a[i].d2 && a[i].d1 >= a[i].d3)
			v1.push_back(i), v[i] = 1;
		else if (a[i].d2 >= a[i].d1 && a[i].d2 >= a[i].d3)
			v2.push_back(i), v[i] = 2;
		else
			v3.push_back(i), v[i] = 3;
	}

	if (v1.size() > (m = n >> 1)) {
		std::sort(v1.begin(), v1.end(), cmp1);
		for (int i = 0; i < v1.size() - m; ++i)
			v[v1[i]] = a[v1[i]].d2 > a[v1[i]].d3 ? 2 : 3;
	} else if (v2.size() > m) {
		std::sort(v2.begin(), v2.end(), cmp2);
		for (int i = 0; i < v2.size() - m; ++i)
			v[v2[i]] = a[v2[i]].d1 > a[v2[i]].d3 ? 1 : 3;
	} else if (v3.size() > m) {
		std::sort(v3.begin(), v3.end(), cmp3);
		for (int i = 0; i < v3.size() - m; ++i)
			v[v3[i]] = a[v3[i]].d1 > a[v3[i]].d2 ? 1 : 2;
	}

	ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += v[i] == 1 ? a[i].d1 : v[i] == 2 ? a[i].d2 : a[i].d3;
		v[i] = 0;
	}

	Write(ans), putchar('\n');
	v1.clear(), v2.clear(), v3.clear();
}

int T;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	T = Read();

	do {
		n = Read();
		for (int i = 1; i <= n; ++i)
			a[i].d1 = Read(), a[i].d2 = Read(), a[i].d3 = Read();

		Solve();
	} while (--T);

	return 0;
}

