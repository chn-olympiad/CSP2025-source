#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 500010
using namespace std;
int arr[MAXN], sum[MAXN], last[MAXN], dp[MAXN];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] ^ arr[i];
		last[i] = -1;
		for (int j = i - 1; j >= 0; j--) {
			if ((sum[j] ^ sum[i]) == k) {
				last[i] = j;
				break;
			}
		}
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (last[i] == -1) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = max(dp[i - 1], dp[last[i]] + 1);
		}
	}
	cout << dp[n];
	return 0;
}

