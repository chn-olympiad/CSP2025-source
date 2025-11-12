#include <bits/stdc++.h>
using namespace std;

long long n, k, pre[500001], a[500001], dp[500001][2];

int XOR(int a, int b) {
	int A, B, c, C = 0, i = 1;
	while (a != 0 || b != 0) {
		A = a % 2;
		B = b % 2;
		c = ((A || B) && ((!A) || (!B)));
		a = a / 2;
		b = b / 2;
		C += i * c;
		i *= 2;
	}
	return C;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	pre[1] = a[1];
	for (int i = 2; i <= n; i++) {
		pre[i] = XOR(a[i], pre[i - 1]);
	}

	dp[0][0] = 0;
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		int j = i;
		dp[i][0] = dp[i - 1][0];
		while (dp[j][1] == 0 && j >= 1) {
			if (max(pre[i] - pre[j - 1], pre[j - 1] - pre[i]) == k) {
				dp[i][0]++;
				dp[i][1] = 1;
				break;
			}
			j--;
		}
	}
	cout << dp[n][0];
}