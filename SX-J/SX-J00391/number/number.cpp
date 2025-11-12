#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string n;
	cin >> n;
	int a[11] = {0};
	for (long long i = 0; i < n.size(); i++) {
		if (n[i] >= '0' && n[i] <= '9')
			a[n[i] - '0'] += 1;
		//cout << a[i] << " ";
	}
//	for (int i = 9; i >= 0; i--) {
//
//		cout << a[i] << " ";
//	}
	string ans = "";
	for (int i = 9; i >= 0; i--) {
		if (a[i] != 0) {
			for (int j = 1; j <= a[i]; j++) {
				ans += (i + 48);
			}
		}
		//cout << a[i] << " ";
	}
	cout << ans;
	return 0;
}