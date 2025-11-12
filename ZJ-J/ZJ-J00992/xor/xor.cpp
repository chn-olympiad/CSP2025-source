#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

struct info {
	int l, r;
	info () {
	}
	info (const int &l, const int &r) : l(l), r(r) {
	}
	bool operator < (const info &a) {
		if (a.r == r)
			return l < a.l;
		return r < a.r;
	}
};

int n, k;
int a[N];
int s[N];
info c[25000010];
int l;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if (n <= 5000) {
		for (int i = 1; i <= n; i++)
			s[i] = s[i-1]^a[i];
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				if ((s[j] ^ s[i-1]) == k)
					c[++l] = info(i, j);
		sort(c+1, c+l+1);
		int ans = 1;
		int last = 1;
		for (int i = 2; i <= l; i++)
			if (c[i].l > c[last].r)
				++ans, last = i;
		printf("%d", ans);
	} else {
		if (k == 1) {
			bool f = true;
			for (int i = 1; i <= n; i++)
				if (a[i] > 2) {
					f = false;
					break;
				}
			if (f) {
				int cnt = 0;
				for (int i = 1; i <= n; i++)
					if (a[i])
						++cnt;
				printf("%d", cnt);
				return 0;
			}
		}
	}
}
