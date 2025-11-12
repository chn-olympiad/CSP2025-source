#include <bits/stdc++.h>
#define fup(i, l, r) for (int i = (l); i <= (r); i++)
#define fdw(i, l, r) for (int i = (l); i >= (r); i--)
using lld = long long;
const int N = 505, P = 998244353;
int n, m, C[N], p[N], cnt[N];
char S[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, S + 1);
	fup(i, 1, n) scanf("%d", &C[i]), p[i] = i;
	std::sort(C + 1, C + n + 1);
	// if (m == 1) {
	// 	// printf("!!\n");
	// 	fup(i, 1, n) cnt[C[i] + 1]++;
	// 	lld ans = 1, fc = 1, cc = 0;
	// 	fup(i, 1, n) {
	// 		cc += cnt[i];
	// 		(ans *= cc) %= P;
	// 		(fc *= i) %= P;
	// 		cc--;
	// 	}
	// 	printf("%lld\n", (fc - ans + P) % P);
	// } else 
	if (m == n) {
		lld ans = 1;
		fup(i, 1, n) {
			if (S[i] == '0') ans = 0;
			if (C[i] == '0') ans = 0;
			(ans *= i) %= P;
		}
		printf("%lld\n", ans);
	} else {
		lld ans = 0;
		do {
			int c = 0;
			fup(i, 1, n) {
				if (c >= C[p[i]] || S[i] == '0') c++;
			}
			ans += c <= n - m;
		} while (std::next_permutation(p + 1, p + n + 1));
		printf("%lld\n", ans);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}