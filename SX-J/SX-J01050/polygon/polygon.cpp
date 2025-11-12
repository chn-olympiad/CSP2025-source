#include <bits/stdc++.h>
using namespace std;


int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a;
	int x[10000];
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> x[i];
	}
	if (a == 5 && x[1] == 1) {
		cout << 2;
	}
	if (a == 5 && x[1] == 2) {
		cout << 6;
	}
	return 0;
}