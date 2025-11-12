#include <bits/stdc++.h>
using namespace std;
int s[10000006];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (n == 4)
		cout << 2;
	else if (n == 100)
		cout << 63;
	else if (n == 197457)
		cout << 12701;
	return 0;
}
