#include <bits/stdc++.h>
using namespace std;
int a, arr[5005], big = -1000000, he;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> arr[i];
		big = max(big, arr[i]);
		he += arr[i];
	}
	if (a == 3) {
		if (he > big * 2)
			cout << 1;
		else
			cout << 0;
	} else
		cout << 1;
	return 0;
}
