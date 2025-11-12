//SN-J00369 张正轩 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1005];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, t = 1, s, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k > 1) {
		if (a[1] == k) ans++;
		for (int i = 2; i <= n; i++) {
			s = 0;
			for (int j = i; j >= t + 1; j--) {
				s = s ^ a[j];
				if (s == k) {
					ans++;
					t = i;
					break; 
				}
			}
		}
		cout << ans;
	}else {
		if (k == 1) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					ans++;
				}
			}
			cout << ans << endl;
		}else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) {
					ans++;
				}else if (a[i] == 1 && a[i - 1] == 1) {
					ans++;
					a[i] = 2;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
