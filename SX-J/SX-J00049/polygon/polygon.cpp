#include <bits/stdc++.h>
using namespace std;

int n, a[5001], ans = 0;
bool choose_or_not[5001];
void dfs(int p) {
	if (p == n + 1) {
		int sum = 0, maxx = INT_MIN;
		for (int i = 1; i <= n; i++) {
			if (choose_or_not[i]) {
				sum += a[i];
				maxx = max(maxx, a[i]);
			}
		}

		ans += (sum > 2 * maxx);
		ans %= 998244353;
		return;
	}

	choose_or_not[p] = 1;
	dfs(p + 1);

	choose_or_not[p] = 0;
	dfs(p + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	dfs(1);
	cout << ans % 998244353 << endl;
	return 0;
}
/*
I love CCF FOREVER!
I have myself a time here!
I love CCF, I love you, I love you!
I'm so in love with you!
I will never forget you!
I will never give you up!
I will never dessert you!
I will never let you down!
I will never say goodbye to you!
You're a part of my heart!
*/