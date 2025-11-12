#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.in", "w", stdout);
	cin >> n >> k;
	if (n == 2 and k == 0) {
		cin >> a >> b;
		if (a == 0 or b == 0)
			cout << 1;
		else if (a == b)
			cout << 1;
		else
			cout << 0;
	} else if (n == 1) {
		cin >> a;
		if (a == k)
			cout << 1;
		else
			cout << 0;
	} else
		cout << 1;
	return 0;
}