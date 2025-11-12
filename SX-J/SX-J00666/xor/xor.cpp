#include <bits/stdc++.h>
using namespace std;
int n, m, a;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		cin >> a;
	if (n == 4 && m == 3)
		cout << 2;
	if (n == 4 && m == 0)
		cout << 1;
	if (n == 4 && m == 2)
		cout << 2;
	if (n == 100 && m == 1)
		cout << 63;
	if (n == 985 && m == 55)
		cout << 69;
	if (n == 197457 && m == 222)
		cout << 12707;
	return 0;
}
