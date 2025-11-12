#include <bits/stdc++.h>
using namespace std;
int m, n;
long long ans = 1;
string s;
int a[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> m >> n;
	cin >> s;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = m; i > 0; i--) {
		ans *= i;
	}
	cout << ans;
	return 0;
}