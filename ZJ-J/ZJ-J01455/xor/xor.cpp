#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int a[N], sum[N];

int dp[N];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int n, k;
	cin >> n >> k;
	bool flag = false;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != 1) 	flag = true;
		sum[i] = sum[i - 1] ^ a[i];
	}
	if (flag == false) {//A 10#
		cout << n / 2;
		return 0;
	}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= n; j ++) {
				if ((sum[j] ^ sum[i - 1]) == k) {
					i = j;
					ans ++;
					break;
				}
			}
		}
		cout << ans;
	return 0;
}
/*
4 2
2 1 0 3
*/