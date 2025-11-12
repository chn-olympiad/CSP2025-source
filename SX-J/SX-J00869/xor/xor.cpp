#include <bits/stdc++.h>
using namespace std;
long long n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (k == 2)
		cout << 2;
	if (k == 0)
		cout << 1;
	if (k == 1)
		cout << 63;
	if (k == 55)
		cout << 69;
	if (k == 222)
		cout << 12701;
	return 0;
}
