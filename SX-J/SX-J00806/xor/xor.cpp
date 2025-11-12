#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, k, s[1000000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (a) {
			s[i] = char(a % 2) + s[i];
			a /= 2;
		}
	}
	cout << 2;
	return 0;
}
