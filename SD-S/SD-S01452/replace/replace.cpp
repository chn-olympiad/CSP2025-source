#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5+5, L = 5e6+5, P = 131;

char s1[L], s2[L];
struct hsh_t {
	ull from, to;
	ull ori;
	int l, len;
} hsh[N];
ull nw_from[N], nw_to[N];

ull get_hash1(int l, int r) {
	ull h = 0;
	for (int i = l; i <= r; ++i) {
		h = h * P + s1[i] - 'a';
	}
	return h;
}

ull get_hash2(int l, int r) {
	ull h = 0;
	for (int i = l; i <= r; ++i) {
		h = h * P + s2[i] - 'a';
	}
	return h;
}

bool cmp1(hsh_t a, hsh_t b) {
	if (a.from != b.from)
		return a.from < b.from;
	if (a.to != b.to)
		return a.to < b.to;
	return a.ori < b.ori;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, cnt0 = 0, cnt = 0; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s%s", s1, s2);
		int len = strlen(s1);
		int l = 0, r = len - 1;
		for (; l < len; ++l) {
			if (s1[l] != s2[l])
				break;
		}
		for (; r >= 0; --r) {
			if (s1[r] != s2[r])
				break;
		}
		if (l > r) {
			++cnt0;
			continue;
		}
		++cnt;
		hsh[cnt].from = get_hash1(l, r);
		hsh[cnt].to = get_hash2(l, r);
		hsh[cnt].ori = get_hash1(0, len - 1);
		hsh[cnt].len = len;
		hsh[cnt].l = l;
	}
	sort(hsh + 1, hsh + cnt + 1, cmp1);
	for (int i = 1; i <= n; ++i) {
		nw_from[i] = hsh[i].from;
		nw_to[i] = hsh[i].to;
	}
	while (q--) {
		scanf("%s%s", s1, s2);
		int len = strlen(s1);
		int l = 0, r = len - 1;
		for (; l < len; ++l) {
			if (s1[l] != s2[l])
				break;
		}
		for (; r >= 0; --r) {
			if (s1[r] != s2[r])
				break;
		}
		if (l > r) {
			printf("%d\n", cnt0);
			continue;
		}
		ull hsh1 = get_hash1(l, r);
		ull hsh2 = get_hash2(l, r);
		int l1 = lower_bound(nw_from + 1, nw_from + cnt + 1, hsh1) - nw_from;
		int r1 = upper_bound(nw_from + 1, nw_from + cnt + 1, hsh1) - nw_from;
		int l2 = lower_bound(nw_to + l1, nw_to + r1, hsh2) - nw_to;
		int r2 = upper_bound(nw_to + l1, nw_to + r1, hsh2) - nw_to;
		int ans = 0;
		for (int i = l2; i < r2; ++i) {
			int nl = l - hsh[i].l;
			int nr = nl + hsh[i].len - 1;
			ull hsh3 = get_hash1(nl, nr);
			if (hsh3 == hsh[i].ori)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
