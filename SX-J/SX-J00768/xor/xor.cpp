#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[10];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int w;
	for (int i = 1; i <= n; i++) {
		w = max(a[i], a[i + 1]);
	}
	cout << w;
	return 0;
}
