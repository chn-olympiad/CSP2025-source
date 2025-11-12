#include <bits/stdc++.h>
using namespace std;
int a[505], s[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, sum = 0, maxx = 0;
	cin >> n >> m;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		a[i] = str[i] - '0';
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);
	for (int i = 0; i < n; i++) {
		if (a[i] == 1 && s[i] > sum) {
			sum++;
		}
	}
	if (sum == m) {
		while (n) {
			maxx += n - 1;
			n--;
		}
		cout << (maxx - 1) % 998 % 244 % 353;
	} else {
		cout << 0;
	}
	return 0;
}