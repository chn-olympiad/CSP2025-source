#include <bits/stdc++.h>
using namespace std;
int a[10005], n, m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int R = a[1];

	sort(a + 1, a + 1 + n *m, cmp);
	int index = 1;
	while (a[index] != R)
		index++;
	int t = (index / n);
	if (index % n == 0) {
		if (t % 2 == 0)
			cout << t << " " << 1;
		else
			cout << t << " " << m;
	} else {
		if (t % 2 == 0)
			cout << t + 1 << " " << index % n;
		else
			cout << t + 1 << " " << m - index % n + 1;
	}
	return 0;
}
