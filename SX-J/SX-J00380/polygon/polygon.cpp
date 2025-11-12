#include <bits/stdc++.h>
using namespace std;
int n, num = 0, a[100000];
int maxx = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			num++;
		}
	}
	num %= 998244353;
	cout << num;
	return 0;
}
