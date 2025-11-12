#include <bits/stdc++.h>
using namespace std;
int x[110];

int main() {
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n, m;
	cin >> n >> m;
	int a = 1, b = 1;
	for (int i = 1; i <= n * m; i++) {
		cin >> x[i];
	}
	for (int j = 2; j <= m * m; j++) {
		if (a < n && x[j] > x[1]) {
			a++;
		}
		if (a == n && x[j + 1] > x[1]) {
			b = b + 1;
		}
	}
	cout << b << ' ' << a;
	return 0;
}