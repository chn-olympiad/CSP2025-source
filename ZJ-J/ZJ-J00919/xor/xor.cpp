#include <bits/stdc++.h>
using namespace std;

int a[200005];


int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	bool A = true;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			A = false;
	}
	if (k == 0 && A) {
		cout << n / 2 << endl;
		return 0;
	}
	if (k == 0 && !A) { // B, k == 0 || (buhui)
		int cnt = 0;
		if (a[1] == 0) {
			cnt++;
		}
		for (int i = 2; i <= n; i++) {
			if (a[i] == 1 && a[i - 1] == 1)
				cnt++, i++;
			if (a[i] == 0)
				cnt++;
		}
		cout << cnt << endl;
	}
	if (k == 1 && !A) { // B, k == 1 || (buhui)
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
