#include <bits/stdc++.h>
using namespace std;
int n, m, c[501], mod = 998244353, flag[501], sum, ans, cur[501];
long long jcb[501];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		flag[i + 1] = s[i] - '0';
		if (flag[i + 1] == 0) {
			flag[0] = 1;
			cur[i + 1] = cur[i] + 1;
		} else {
			sum++;
		}
	}

	jcb[0] = 1;
	for (long long i = 1; i <= n; i++) {
		jcb[i] = (jcb[i - 1] * i) % mod;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (flag[0] == 0) {
		cout << jcb[n];
		return 0;
	}
	if (sum < m) {
		cout << 0;
		return 0;
	}
	return 0;
}
