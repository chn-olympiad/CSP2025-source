#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int dp[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	bool f1, f2, f3;
	f1 = f2 = f3 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 1) f1 = 1;
		if(a[i] == 0) f2 = 1;
		if(a[i] > 1 && a[i] <= 255) f3 = 1;
	}
	if(f1 && !f2 && !f3) cout << n / 2 << endl;
	else if(f1 && f2 && !f3) {
		int ans = 0;
		if(k == 0) {
			for(int i = 1; i <= n; i++) {
				if(a[i] == a[i - 1] && a[i] == 1) {
					ans++;
					a[i] = a[i - 1] = 0;
				}
				else if(a[i] == 0) ans++;
			}
		}
		else {
			for(int i = 1; i <= n; i++) {
				if(a[i] == 1) ans++;
			}
		}
		cout << ans << endl;
	}
	else {
		for(int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			if(a[i] == k) dp[i] = dp[i - 1] + 1;
			else {
				int l = a[i];
				for(int j = i - 1; dp[j] == dp[i]; j--) {
					l ^= a[j];
					if(l == k) {
						dp[i] = dp[i - 1] + 1;
						break;
					}
				}
			}
		}
		cout << dp[n] << endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

