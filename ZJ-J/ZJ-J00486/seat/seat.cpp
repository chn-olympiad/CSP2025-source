#include <iostream>
#include <algorithm>
using namespace std;
#define N 15
int n, m, a[N * N], id = 0;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
		cin >> a[i];
	for (int i = 2; i <= n * m; ++i)
		id += (a[i] > a[1]);
	int c = id / n + 1;
	int r = (c & 1 ? id % n + 1 : n - id % n);
	cout << c << " " << r << endl;
	return 0;
}
