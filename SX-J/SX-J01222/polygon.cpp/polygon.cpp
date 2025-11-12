#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		n += i;
	}
	n - 4;
	cout << n;
	return 0;
}