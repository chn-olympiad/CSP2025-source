#include <iostream>
using namespace std;

int n, m;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int cnt = 1;
	for (int i = 2; i <= n * m; i++)
		cnt += (a[i] > a[1]);
	int c = (cnt + n - 1) / n, r = (cnt - 1) % n + 1;
	if (c % 2 == 0) r = n + 1 - r;
	cout << c << ' ' << r;
	return 0;
}
