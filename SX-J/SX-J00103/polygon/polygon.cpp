#include <bits/stdc++.h>
using namespace std;
int a[101];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i; i <= n; i++) {
		cin >> a[i];
	}
	cout << a[0];
	return 0;
}
