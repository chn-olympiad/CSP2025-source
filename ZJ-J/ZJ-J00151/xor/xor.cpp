#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5, MAX_LOGK = 19;

int n, k;
int arr[MAX_N + 1];
int cnt0[MAX_LOGK][MAX_N + 1];
int dp[MAX_N + 1];

bool check(int l, int r, int i) {
	int c0 = cnt0[i][r] - cnt0[i][l - 1];
	int c1 = r - l + 1 - c0;
	return (((k >> i) & 1) ? 
	(c0 == 1 && (c1 & 1)) || (!(c0 & 1) && (c1 & 1)) || ((c0 & 1) && c0 != 1 && !(c1 & 1)) :
	(c0 == 1 && !(c1 & 1)) || (!(c0 & 1) && !(c1 & 1)) || ((c0 & 1) && c0 != 1 && (c1 & 1)));
} 

bool check1(int l, int r, int i) {
	int c0 = cnt0[i][r] - cnt0[i][l - 1];
	int c1 = r - l + 1 - c0;
	return (((k >> i) & 1) ? (c1 & 1) : !(c1 & 1));
} 

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
	for (int i = 0; i < MAX_LOGK; ++i) {
		for (int j = 1; j <= n; ++j) {
			cnt0[i][j] = cnt0[i][j - 1] + !((arr[j] >> i) & 1);
		}
	}
	for (int r = 1; r <= n; ++r) {
		dp[r] = dp[r - 1];
		for (int l = r; l >= 1; --l) {
			bool flag = false;
			for (int i = 0; i < MAX_LOGK; ++i) {
				if (!check1(l, r, i)) {
					flag = true;
					break;
				}
			}
			if (flag) continue;
			dp[r] = max(dp[r], dp[l - 1] + 1);
			break;
		}
	}
	printf("%d", dp[n]);
	return 0; 
}
