#include <bits/stdc++.h>
using namespace std;
int num;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int a[1010] = {0};
	int ans = 0, m = 1;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[ans] = s[i] - 48;
			ans++;
		}
	}
	for (int i = 0; i < ans; i++) {
		for (int j = i + 1; j < ans ; j++) {
			if (a[i] > a[j]) {
				int b = a[j];
				a[j] = a[i];
				a[i] = b;
			}
		}
	}
	for (int i = 0; i < ans; i++) {
		if (i == 0)
			num += a[i];

		else {
			for (int j = 0; j <= i - 1; j++) {
				m *= 10;
			}
			num += a[i] * m;
		}
		m = 1;

	}
	cout << num;
	return 0;
}
