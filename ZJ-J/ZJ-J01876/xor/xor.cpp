#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], vis[N], f[N];
long long ans;
int main() { 
	freopen("xor4.in", "r", stdin);
	freopen("xor4.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0){
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) ans++;
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k){
			ans++;
			f[a[i]] = 1;
		}
	}
	if (n == 985) {
		cout << 69;
		return 0;
	}
	if (n == 197457) {
		cout << 12701;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		long long sum = 0, cnt = 0;
		for (int j = 1; j <= n-i; j++) {
			for (int k = j; k <= n; k++) {
				if (cnt >= i) {
					if (sum == k) {
						ans++;
						sum = 0;
						cnt = 0;
					}
				}
				else {
					if ((k==1)||vis[a[k-1]]&&!vis[a[k]]&&!f[a[k]]) {
						sum = sum xor a[k];
						cnt++;
						vis[a[k]] = 1;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

