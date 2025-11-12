#include <bits/stdc++.h>
using namespace std;
long long n, t, s;
int a[5010];

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	/*for (int i = 1; i <= n; i++) {
		if (a[i] != 0) {
			t++;
		}
	}
	if (t < 3) {
		cout << 0;
		return 0;
	} else if (t == 3) {
		cout << 1;
		return 0;
	}
	for (int i = (n - 1); i >= 3; i--) {
		for (int j = 1; j < n; j++) {
			i = i * j;

		}
		s = s + i;
	}
	cout << s+1;*/

	if ((a[1] * 2) < (a[1] + a[2] + a[3]))
		if ((a[2] * 2) < (a[1] + a[2] + a[3]))
			if ((a[3] * 2) < (a[1] + a[2] + a[3]))
				s++;
	cout << s;
	return 0;
}