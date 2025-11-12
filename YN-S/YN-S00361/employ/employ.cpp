#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long ans = 1;
	for (int i = 1; i <= m; i++)
		ans *= (n - i + 1);
	cout << ans;
	return 0;
}