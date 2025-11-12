#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		sum = a[1];
		if (a[i] > a[i - 1])
			swap(a[i], a[i - 1]);
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == sum) {
			cout << "1" << " " << i;
		}
	}
	return 0;
}