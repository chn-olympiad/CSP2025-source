#include <bits/stdc++.h>
using namespace std;

int a[10100];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
		cin >> a;
	if (a <= 3)
		cout << 10
		     else
			     cout << 1;
	return 0;
}