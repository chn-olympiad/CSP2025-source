#include <cstring>
#include <iostream>

#define ll long long

const int Maxn = 1e6 + 4;
const int P1 = 1e9 + 7, P2 = 998244353, mod = 1e7 + 1;

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

bool s1[mod + 2], s2[mod + 2];

inline int StrHash(char *a) {
	int res = 0;
	for (int i = 0; i < strlen(a); ++i)
		res += (ll)(a[i] * P1 + P2) % mod;
	return res;
}

char s[Maxn], a[Maxn], b[Maxn], l1[Maxn], l2[Maxn];
int n, q, la, lb, ans;

inline void Solve() {
	la = StrHash(a), lb = StrHash(b), ans = 0;
	if (s1[la] && s2[lb])
		++ans;

	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i])
			break;
		for (int j = 0; j < n - i; ++j) {
			if (a[j] != b[j])
				break;
			int n1 = 0, n2 = 0;
			for (int k = i + 1; k < j; ++k)
				l1[k - i - 1] = a[k], l2[k - i - 1] = b[k];
			n1 = StrHash(l1), n2 = StrHash(l2);
			if (s1[n1] && s2[n2])
				++ans;
		}
	}

	Write(ans), putchar('\n');
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	n = Read(), q = Read();
	for (int i = 1; i <= n; ++i) {
		std::cin >> s;
		s1[StrHash(s)] == true;
		std::cin >> s;
		s2[StrHash(s)] == true;
	}
	do {
		std::cin >> a;
		std::cin >> b;

		Solve();
	} while (--q);

	return 0;
}

