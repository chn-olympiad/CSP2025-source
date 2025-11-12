#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 1;
string s;
int c[114514];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cout << ans;
	cin >> n >> m;
	cin >> s;

	for (int i = 1; i <= n; i++) {

		cin >> c[i];
	}

	for (int i = 1; i <= n; i++) {

		ans = (ans * i ) % 998244353;
	}

	cout << ans;

	return 0;
}
