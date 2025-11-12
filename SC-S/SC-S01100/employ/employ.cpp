#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5+10, mod = 998244353;
inline int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x*f;
}
int n = read(), m = read();
string s;
int c[MAXN];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> s;
	for (int i = 1; i <= n; i++)c[i] = read();
	int sum[MAXN];
	sum[1] = 1;
	for (int i = 2; i <= n; i++)sum[i] = sum[i - 1] * sum[i] % mod;
	cout << sum[n];
	return 0;
}
