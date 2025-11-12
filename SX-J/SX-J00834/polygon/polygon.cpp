#include <bits/stdc++.h>
using namespace std;
int n;
int l[3];
int maxn = -1;
int sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		maxn = max(maxn, l[i]);
		sum += l[i];
	}
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	if (sum > maxn * 2) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
