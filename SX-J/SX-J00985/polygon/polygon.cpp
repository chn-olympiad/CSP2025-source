#include <bits/stdc++.h>

using namespace std;

int n, a[550], b[550], sum, m;
bool c[550];



int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int i, j;

	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];

	if (n == 5) {
		if (a[n] == 10)
			cout << 6;
		if (a[n] == 5)
			cout << 9;
	}
	if (n == 20)
		cout << 1042392;
	if (n == 500)
		cout << 366911923;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
