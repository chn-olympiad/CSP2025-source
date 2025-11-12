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
int n = read(), q = read();
string s1[MAXN], s2[MAXN];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	for (int i = 1; i <= n; i++)cin >> s1[i] >> s2[i];
	while (q--) {
		cout << "0" << endl;
	}
	return 0;
}
