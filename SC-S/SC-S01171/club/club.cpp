#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll T, n, a[100005][5], f1[205][205][205], f2[100005];

bool flag_B_all_zero = true, flag_C_all_zero = true;

bool cmp(ll a, ll b) {
	return a > b;
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	
	while (T--) {
		flag_B_all_zero = true, flag_C_all_zero = true;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				cin >> a[i][j];
			}
			if (a[i][2] != 0) flag_B_all_zero = false;
			if (a[i][3] != 0) flag_C_all_zero = false;
		}
		if (n <= 205) {
			ll ans = -1e18;
			memset(f1, 0, sizeof(f1));
			for (int i = 1; i <= n; i ++) { // 分配到第i个人 
				for (int j = 0; j <= n/2; j ++) { // A社团有j个人 
					for (int k = 0; k <= n/2; k ++) { // B社团有k个人 
						ll l = i - j - k;
						if (l < 0 || l > n/2) continue;
						ll t1 = 0, t2 = 0, t3 = 0;
						if (j-1 >= 0) t1 = f1[j-1][k][l] + a[i][1];
						if (k-1 >= 0) t2 = f1[j][k-1][l] + a[i][2];
						if (l-1 >= 0) t3 = f1[j][k][l-1] + a[i][3];
						f1[j][k][l] = max(t1, max(t2, t3));
						ans = max(ans, f1[j][k][l]);
					}
				}
			}
			cout << ans << endl;
		} else if (flag_B_all_zero && flag_C_all_zero) { // 特殊情况A 
			ll ans = 0;
			for (int i = 1; i <= n; i ++) f2[i] = a[i][1];
			sort(f2+1, f2+1+n, cmp);
			for (int i = 1; i <= n / 2; i ++) ans += f2[i];
			cout << ans << endl;
		} else if (flag_C_all_zero) { // 特殊情况B 
			
		} else {
			
		}
	}
	
	return 0;
}