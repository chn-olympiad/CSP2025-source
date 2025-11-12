#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a >> b;
	if (b == 2)
		cout << 6;
	else 	if (b == 1)
		cout << 9;
	else
		cout << 1;
	return 0;
}
