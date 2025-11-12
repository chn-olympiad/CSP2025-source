#include <bits/stdc++.h>
using namespace std;
int da;
int n, m;
int a[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int k = n * m;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		if (i == 1)
			continue;
		if (a[i] > a[1])
			da++;
	}
	int l = 1 + da % n;
	if ((1 + da / m) % 2 == 0)
		l = n - (da % n);
	cout << 1 + da / m << " " << l;
}