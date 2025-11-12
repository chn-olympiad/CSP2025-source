#include <bits\stdc++.h>
using namespace std;

void work(int n) {
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans %= 998244353;
	}
	cout << ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, a[1000] = {0};
	string nandu;
	cin >> n >> m >> nandu;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	work(n);
	return 0;
}
