#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N], ans;
long long n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 1)
				ans++;
		}
		cout << ans;
	}
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0)
				ans++;
			else {
				if (i + 1 < n && a[i + 1] == 1) {
					ans++;
					i++;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
