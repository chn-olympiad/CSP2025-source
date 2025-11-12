#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> PII;

#define ep emplace
#define eb emplace_back
#define fir first
#define sec second

#define add(a, b) ((((a) = (a) + (b)) >= mod) && ((a) -= mod))

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}

const int N = 20;
const int mod = 998244353;

int n, m, a[N], f[N][1 << N];
char s[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++ ) a[i] = read();
	int tot = (1 << n) - 1;
	f[0][0] = 1;
	for (int st = 0; st <= tot; st ++ ) {
		int up = __builtin_popcount(st);
		for (int i = 0; i <= up; i ++ ) {
			for (int p = 0; p < n; p ++ ) {
				if (st >> p & 1) continue;
				if (s[up + 1] == '0' || a[p + 1] <= i) add(f[i + 1][st | (1 << p)], f[i][st]);
				else add(f[i][st | (1 << p)], f[i][st]);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= n - m; i ++ ) add(res, f[i][tot]);
	printf("%d\n", res);
	return 0;
}
/*
20pts ״ѹ dp 
*/
