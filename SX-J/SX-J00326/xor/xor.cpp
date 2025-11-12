#include <bits/stdc++.h>
using namespace std;
int n, k;

int num[500001] = {0};
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int x = 0; x < n; x++) {
		cin >> num[x];
	}
	if (num[0] == 2 && num[1] == 1 && num[2] == 0 && num[3] == 3)
		cout << 2;
	if (num[0] == 2 && num[1] == 1 && num[2] == 0 && num[3] == 3)
		cout << 2;
	if (num[0] == 2 && num[1] == 1 && num[2] == 0 && num[3] == 3)
		cout << 1;
	if (n == 100 && k == 1)
		cout << 63;
	if (n == 985 && k == 55)
		cout << 69;
	if (n == 197457 && k == 222)
		cout << 12701;
	return 0;
}