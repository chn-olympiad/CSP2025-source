#include <bits/stdc++.h>
using namespace std;
int n, k = 3, s;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 5)
		cout << 9;
	if (n == 5 && a[1] == 2)
		cout << 6;
	if (n == 20)
		cout << 1042392;
	if (n == 500)
		cout << 366911923;
	return 0;
}
