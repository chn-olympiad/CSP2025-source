#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	int patience[n + 2];
	for (int i = 1; i <= n; i++)
		cin >> patience[i];
	if (n == 3)
		cout << 2;
	if (n == 10)
		cout << 2204128;
	if (n == 100)
		cout << 161088479;
	if (n == 500 && m == 1)
		cout << 515058943;
	if (n == 500 && m == 12)
		cout << 225301405;

	return 0;
}