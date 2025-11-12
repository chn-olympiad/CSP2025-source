#include <bits/stdc++.h>
using namespace std;
int a[100000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >>> a[i];
	}
	sort(a[i], a[i] + 1);
	for (int i = 0; i < n * m; i++) {
		cout << a[i];
	}


	return 0;
}
