#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int n, s, b, c, tmp;
int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		s = a[i];
		b = a[i - 1];
		c = a[i - 2];
		int maxx = 0;
		if (maxx < s) {
			maxx = s;
		} else if (maxx < b) {
			maxx = b;
		} else if (maxx < c) {
			maxx = c;
		}
		if ((s + b + c) > maxx * 2) {
			tmp++;
		}
	}
	tmp %= 998;
	tmp %= 244;
	tmp %= 353;
	cout << tmp;
	return 0;
}
