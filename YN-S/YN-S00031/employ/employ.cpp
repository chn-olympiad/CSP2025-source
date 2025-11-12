#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


int n, m, c[520] = {0}, cnt[510] = {0};
const long long M = 998244353;
long long p = 1, jc[510];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	int f = 1, t = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		if (c[i] == 0)
			t++;
		if (s[i - 1] == '0')
			f = 0;
	}
	if (n - t < m) {
		printf("0");
		return 0;
	}
	sort(c + 1, c + 1 + n);
	jc[1] = 1;
	for (int i = 2; i <= n; i++) {
		jc[i] = jc[i - 1] * i % M;
	}
	if (f) {
		p = jc[n - t] * jc[t] % M;
		int x = n - t - m;
		if (x == 0) {
			printf("%lld", p);
			return 0;
		}
		cnt[0] = t;
		for (int i = t + 1; i <= n; i++) {
			cnt[c[i]]++;
			if (c[t + 1] > t) {
				p = jc[n];
				break;
			}
			if (n - i + 1 >= m && c[i] >= i) {
				p = jc[n];
				break;
			}

		}

		printf("%lld", p);
		return 0;
	}
	printf("0");
	return 0;
}