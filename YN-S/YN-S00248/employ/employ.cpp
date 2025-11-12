#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, s[505], c[505];

bool is_A() {
	for (int i = 1; i <= n; ++i)
		if (s[i] != 1)
			return false;
	return true;
}

void taskA() {
	long long ans = 1, k = 0;
	for (int i = 1; i <= n; ++i) {
		if (c[i] != 0)
			k++;
	}
	for (int i = 1; i <= k; ++i)
		ans = (ans * i) % mod;
	cout << ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);
	cin >> n >> m;
	string str;
	cin >> str;
	for (int i = 1; i <= n; ++i)
		s[i] = (str[i - 1] == '1');
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	if (is_A())
		taskA();
	else
		cout << 0;
	return 0;
}