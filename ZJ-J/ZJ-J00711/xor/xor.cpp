#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7;
int a[N];
int prefix[N];
unordered_map<int, int> mp;
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	bool xiangdeng = 1;
	bool B = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i != 1) {
			if (a[i] != a[i - 1]) xiangdeng = 0;
		}
		mp[a[i]]++;
		if (a[i] != 1 && a[i] != 0) B = 0;
		prefix[i] = prefix[i - 1] ^ a[i];
	}
	if (xiangdeng) {
//		cout << "--xiangdeng\n";
		if (a[1] == k) {
			cout << n;
			return 0;
		}
		if (a[1] == 1) {
			if (k == 0) {
				cout << n / 2;
				
			} else {
				cout << 0;
			}
			return 0;
		}
		
		if (a[1] == 0) {
			if (k == 1) {
				cout << n / 2;
			} else {
				cout << 0;
			}
			return 0;
		}
	}
	
	if (B) {
//		cout << "--B\n";
		if (k == 1) {
			int ans = 0;
			ans += mp[1];
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0 && a[i + 1] == 0) {
					ans++;
					i++;
					continue;
				}
			}
			cout << ans << '\n';
			return 0;
		} else if (k == 0) {
			int ans = 0;
			ans += mp[0];
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1 && a[i + 1] == 1) {
					ans++;
					i++;
					continue;
				}
			}
			cout << ans << '\n';
			return 0;
		}
		
	}
	
	
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i <= n; i++) {
			int j = i + l - 1;
			if (a[i] != -1) {
				int flag = 1;
				for (int t = i; t <= j; t++) {
					if (a[t] == -1) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					if ((prefix[j] ^ prefix[i - 1]) == k) {
						ans++;
						for (int t = i; t <= j; t++) {
							a[t] = -1;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

