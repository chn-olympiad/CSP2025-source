#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+10;

int n, s[N], cnt, temp;

int main() {
	freopen("polygon.cpp", "r", stdin);
	freopen("polygon.cpp", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	if (n = 3) {
		if (s[1] + s[2] > s[3]) {
			cnt++;
		}
		if (s[1] + s[3] > s[2]) {
			cnt++;
		}
		if (s[2] + s[3] > s[1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}