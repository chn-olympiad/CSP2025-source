#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[21];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int t = 1;
	b[0] = n;
	for (int i = 1; i <= 2 * n; i++) {
		b[i] = t;
		if (i < n)
			t++;
		else if (i > n)
			t--;
	}
	int ans, sum;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			ans = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == ans)
			sum = i;
	}
	int y = sum % (2 * n  );
	if (sum % n != 0)
		sum = sum + n;
	int x = sum  / n;
	cout << x << " " << b[y] << endl;
	return 0;
}
