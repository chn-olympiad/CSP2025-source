#include <bits/stdc++.h>
using namespace std;
int b[10000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int ct = 0, ans = 0;
	for (int i = 1; i <= a.size(); i++) {
		if (a[i] <= '9' && a[i] >= '1') {
			ct++;
			b[ct] = a[i];
		}
	}
	if (ct == 1) {
		cout << b[ct];
		return 0;
	}
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= a.size(); j++) {
			if (b[i] < b[i + 1]) {
				swap(b[i], b[i + 1]);
			}
		}
	}
	for (int i = 1; i <= a.size(); i++) {
		for (int j = ct; j >= 1; j--) {
			b[i] *= 10;
		}
		ans += b[i];
	}
	cout << ans;
	return 0;
}