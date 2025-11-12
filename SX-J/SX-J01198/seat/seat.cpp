#include <bits/stdc++.h>
using namespace std;
int a[20], b[20];

int main() {
	freopen("seat.in", "r", "stdin");
	freopen("seat.out", "w", "stdout");
	int n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i * j];
			if (a[i] > a[i + 1] && a[j] > a[j + 1])
				k = a[i] && a[j];

		}
	return 0;
}