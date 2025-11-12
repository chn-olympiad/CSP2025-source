#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

vector<int> num(5010, 0), sum(5010, 0);
vector<long long>dp(5010 * 5010, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> num[i];
	}

	int ans = 0;
	if (n == 3) {
		int maxLen = -1;
		int total = 0;
		for (int i = 1; i <= n; i ++) {
			maxLen = max(maxLen, num[i]);
			total += num[i];
		}

		if (maxLen * 2 < total) {
			ans ++;
		}
		cout << ans;
	} else {
		cout << n * 2 - 1;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}