#include <bits/stdc++.h>
using namespace std;
const int X = 5e5;
long long n, k, a[X], b[X], ans, tot;

bool check(int l, int r) {
	for (int i = l; i <= r; i++)
		if (b[i])
			return 0;
	return 1;
}

void bb(int i, int j) {
	if (ans == k && check(i, j) ) {
		for (int s = i; s <= j; s++)
			b[s]++;
		tot++;
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		ans = a[i];
		for (int j = i; j <= n; j++) {
			if (j == i) {
				bb(i, j);
			} else if (j != i) {
				ans = (ans xor a[j]);
				bb(i, j);
			}
		}
	}
	cout << tot ;
	return 0;
}


