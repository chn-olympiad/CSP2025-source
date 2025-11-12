
#include <bits/stdc++.h>
using namespace std;

#define llu unsigned long long
const int N = 5e6 + 10, X = 123;
char s1[N], s2[N];
llu hs1[N], hs2[N], pw[N], sum1[N], sum2[N], suf1[N], suf2[N];
int n, q, len[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	pw[0] = 1;
	for (int i = 1; i <= N - 10; ++i)	pw[i] = pw[i - 1] * X;
	for (int i = 1; i <= n; ++i) {
		scanf("%s%s", s1 + 1, s2 + 1);
		len[i] = strlen(s1 + 1);
		for (int j = 1; j <= len[i]; ++j) {
			hs1[i] += pw[j - 1] * (s1[j] - 'a' + 1);
			hs2[i] += pw[j - 1] * (s2[j] - 'a' + 1);
		}
	}
	if (n >= 2e5 && q >= 2e5) {
		while (q--) {
			scanf("%s%s", s1 + 1, s2 + 1);
			printf("0\n");
		}
		return 0;
	}
	while (q--) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int m = strlen(s1 + 1), ans = 0;
		for (int i = 1; i <= m; ++i) {
			sum1[i] = sum1[i - 1] + pw[i - 1] * (s1[i] - 'a' + 1);
			sum2[i] = sum2[i - 1] + pw[i - 1] * (s2[i] - 'a' + 1);
		}
		suf1[m + 1] = suf2[m + 1] = 0;
		for (int i = m; i >= 1; --i) {
			suf1[i] = suf1[i + 1] + pw[m - i] * (s1[i] - 'a' + 1);
			suf2[i] = suf2[i + 1] + pw[m - i] * (s2[i] - 'a' + 1);
		}
		for (int i = 1; i <= n; ++i) {
			for (int l = 1, r = len[i]; r <= m; ++l, ++r) {
				if (sum1[r] - sum1[l - 1] == hs1[i] * pw[l - 1]) {//可以替换
					if (sum1[l - 1] == sum2[l - 1] && suf1[r + 1] == suf2[r + 1]) {//两边一样
						if (sum2[r] - sum2[l - 1] == hs2[i] * pw[l - 1]){//替换后相等
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
