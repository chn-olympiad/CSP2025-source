#include <iostream>
using namespace std;

int main() {
	int n, k = 0;
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n <= 2 && k == 0) {
		cout << 1;
	}
}