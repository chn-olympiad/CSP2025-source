#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
}

int n, m, rp;
int a[155];

int main() {
	file();
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int rk = 0;
	for (int i = 1; i <= n * m; i++)
		if (a[i] >= a[1])
			rk++;
	int a = (rk - 1) / n + 1;
	cout << a << " ";
	if (a & 1)
		cout << rk - (a - 1) * n;
	else
		cout << n - (rk - (a - 1) * n) + 1;
	return 0;
}
