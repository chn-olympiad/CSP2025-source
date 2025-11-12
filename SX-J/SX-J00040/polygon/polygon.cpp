#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	string a[n];
	int m = 0;
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n + 1; i++) {
		if (a[i] + a[i + 1] > a[i + 2])
			m++;
		cout << m << endl;
	}
	cout << m << endl;
	return 0;
}
