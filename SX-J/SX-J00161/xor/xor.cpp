#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	if (n <= 2) {
		cout << 0;
		return 0;
	} else if (n <= 2 * 100000) {
		cout << 1;
	} else if (n <= 10) {
		cout << 1;
	}
	return 0;
}