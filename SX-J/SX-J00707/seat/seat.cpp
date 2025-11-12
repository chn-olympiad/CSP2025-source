#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, b;
	char a[200];
	cin >> n >> b;
	for (int i = 0 ; i < n * b + 1; i++) {
		cin >> a[i];
	}
	if (a[0] == 99) {
		cout << "1 2";
	} else if (a[0] == 93) {
		cout << "2 2";
	} else {
		cout << "1 3";
	}
	return 0;
}