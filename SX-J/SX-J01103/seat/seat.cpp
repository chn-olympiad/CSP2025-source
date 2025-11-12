#include <bits/stdc++.h>
using namespace std;

int a[1010];

bool cmp(int x, int y) {
	return y < x;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t, q;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	if (n == 1  and m == 1) {
		cout << 1 << " " << 1;
		return 0;
	}
	int k = a[1], l = m * n;
	sort(a + 1, a + l + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (k == a[i]) {
			q = i / n + 1;
			if (q % 2 == 1) {
				t = i % n ;
				if (t == 0)
					t++;
			} else
				t = n - i % n + 1;
			break;
		}
	}
	cout << q << " " << t;
	return 0;
}