#include <bits/stdc++.h>
using namespace std;
int s[1001], c[1001];
long long ans;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = n; i >= n; i--) {
		ans *= i % 99844353;
	}
	cout << ans << endl;
	return 0;
}
