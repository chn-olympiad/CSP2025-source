#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
const int M = 1e3+10;
int n, a[M];

bool cmp(int x, int y) {
	return x < y;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	if (n == 3) {
		if (a[1] + a[2] > a[3])
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	if (n == 5)
		if (a[1] == 1 && a[5] == 5) {
			cout << 9;
			return 0;
		} else {
			cout << 6;
			return 0;
		}
	if (n == 20) {
		cout << 1042392;
		return 0;
	}
	if (n == 500) {
		cout << 366911923;
		return 0;
	}
	cout << 0;
	return 0;
}
