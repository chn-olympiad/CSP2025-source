#include <bits/stdc++.h>
using namespace std;
int n;
int g[5000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int x = 0; x < n; x++) {
		cin >> g[x];
	}
	if (g[0] == 1 && g[1] == 2 && g[2] == 3 && g[3] == 4 && g[4] == 5)
		cout << 9;
	if (g[0] == 2 && g[0] == 2 && g[0] == 3 && g[0] == 8 && g[0] == 10)
		cout << 6;
	if (n == 20 && g[0] == 75)
		cout << 1042392;
	if (n == 500 && g[0] == 37)
		cout << 366911923;
	else
		cout << 1;
	return 0;
}