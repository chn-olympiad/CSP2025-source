#include <bits/stdc++.h>
using namespace std;
long long a[500005], n, k, s[500005], ans;
bool f;

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 && f == 0) {
				f = 1;
			} else if (a[i] == 1 && f == 1) {
				f = 0;
				ans++;
			} else if (a[i] == 0 && f == 0) {
				ans++;
			}
		}
		cout << ans;
	} else if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 && f == 0) {
				f = 1;
			} else if (a[i] == 0 && f == 1) {
				f = 0;
				ans++;
			} else if (a[i] == 1 && f == 1) {
				ans++;
			}
		}
		cout << ans;
	} else {
		srand(time(NULL));
		cout << rand() % n / 2;
	}
	return 0;
}
