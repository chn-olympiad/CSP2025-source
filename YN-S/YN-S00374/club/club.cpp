#include <bits/stdc++.h>
using namespace std;
int n;
int a [1001][1001];
int b;

int main() {
	freopen("club.in", "w", stdin);
	freopen("club.out", "r", stdout);
	int t;
	int j, i = 1;
	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][j];
		b = a[i][j] + a[i][j + 1];
	}
	cout << b;
	return 0;
}
