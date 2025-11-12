#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[101];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int c, r;
	cin >> c >> r;
	for (int i; i <= c; i++) {
		for (int j; j <= r; j++) {
			cin >> a[i];
			cin >> a[j];
		}
	}

	return 0;
}
