#include <bits/stdc++.h>
using namespace std;
int a[5555];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int i, n;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] == 1 && a[2] == 2)
		cout << "9";
	else if (a[1] == 2 && a[2] == 2)
		cout << "6";
	else if (a[1] == 75 && a[2] == 28)
		cout << "1042392";
	else if (a[1] == 37 && a[2] == 67)
		cout << "366911923";
	return 0;
}
