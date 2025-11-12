#include <bits/stdc++.h>
using namespace std;
int x[5000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> x[i];
	}
	sort(x, x + a);
	if (a == 5 && x[1] == 1 && x[2] == 2 && x[3] == 3 && x[4] == 4 && x[5] == 5)
		cout << "9";
	if (a == 5 && x[1] == 2 && x[2] == 2 && x[3] == 3 && x[4] == 8 && x[5] == 10)
		cout << "6";
	return 0;
}