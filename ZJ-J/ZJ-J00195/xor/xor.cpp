#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int n, k;
int a[N], id[N], s[N], dp[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], s[i] = s[i - 1] ^ a[i];
	}
	id[k] = n + 1;
	//cout << endl;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (id[s[i]]) {
			dp[i] = max(dp[i], dp[id[s[i]]] + 1);
		}
		id[s[i] ^ k] = i;
	}
	cout << dp[n];
	return 0;
}

