// std T4
#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18) + 10, mod = 998244353;
int n, m;

int dp[N][20], S[510], c[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char c; cin >> c;
		S[i] = c - '0';
//		cin >> S[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int U = (1 << n) - 1;
	dp[0][0] = 1;
	for(int s = 0; s < U; s++) {
		int len = 0;
		for(int i = 1; i <= n; i++) len += ((s >> (i - 1)) & 1);
		for(int i = 0; i <= len; i++) {
			for(int k = 1; k <= n; k++) {
				if(!((s >> (k - 1)) & 1)) {
					if(i >= c[k] || !S[len + 1]) {
						dp[s ^ (1 << (k - 1))][i + 1] = (dp[s ^ (1 << (k - 1))][i + 1] * 1ll + dp[s][i]) % mod;
					} 
					else {
						dp[s ^ (1 << (k - 1))][i] = (dp[s ^ (1 << (k - 1))][i] * 1ll + dp[s][i]) % mod;
					}
				}

			}
		}
//		cout << s << "  : ";
//		for(int i = 1; i <= n; i++) {
//			cout << ((s >> (i - 1)) & 1) << " "; 
//		}
//		
//		cout <<"  :  ";
//		cout << dp[s][0] << " " << dp[s][1] << " " << dp[s][2] << " " << dp[s][3] << "\n";
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
//		cout << dp[U][i] << " ";
		int r = n - i;
		if(r >= m) {
			ans = (1ll * dp[U][i] + ans) % mod;
		}
	}
	cout << ans;
	return 0;
} 