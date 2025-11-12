#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, a[500009], dp[109], k;
vector<int> v[200009];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		a[i] ^= a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= i; j++)
			if ((a[i]^a[j - 1]) == k)
				v[j].push_back(i);
		if (a[i] == k)
			v[1].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
//		for (int to : v[i])
//			cout << to << " ";
//		cout << endl;
		for (int to : v[i])
			dp[to] = max(dp[to], dp[i - 1] + 1);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[n];
	return 0;
}
