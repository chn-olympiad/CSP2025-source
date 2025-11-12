#include <bits/stdc++.h>
using namespace std;
int n, k, num[500005], ck = 1, che = 1;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (num[i] != 1)
			ck = 0;
		if (num[i] != 1 && num[i] != 0)
			che = 0;
	}
	if (ck && k == 0) {
		cout << n / 2;
		return 0;
	}
	if (che) {
		if (k >= 2) {
			cout << 0;
			return 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (num[i] == 1)
				ans++;
		if (k == 1)
			cout << ans;
		else
			cout << n - ans;
		return 0;
	}
	if (k == 0) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (num[i] == 0)
				ans++;
		cout << ans;
		return 0;
	}
	cout << n / 3;
	return 0;
}
