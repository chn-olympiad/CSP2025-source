#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int w, u = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == u)
			w = i;
	int y = ceil(double(w) / double(n)), x;
	cout << y << " " ;
	if (w % n == 0)
		x = n;
	else
		x = w % n;
	if (y % 2 == 0) {
		cout << n - x + 1;
	} else {
		cout << x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}