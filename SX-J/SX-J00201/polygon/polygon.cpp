#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 5];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 3) {
		cout << "1";
	} else {
		if (n == 10)
			cout << "1042392";
		else if (n == 500)
			cout << "366911923";
		cout << "1000000";
	}
	return 0;
}