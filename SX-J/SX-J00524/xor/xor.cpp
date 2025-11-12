#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, x = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int y = 0;
	for (int i = 1; i <= n; i++) {
		x = x ^a[i];
		if (x == k) {
			y++;
			x = 0;
		}
	}
	cout << y;
	return 0;
}