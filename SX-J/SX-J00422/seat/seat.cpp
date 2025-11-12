#include <bits/stdc++.h>
using namespace std;
int n, m, r, a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= (n * m); i++)
		scanf("%d", &a[i]);
	r = a[1];
	sort(a + 1, a + 1 + (n *m), greater<int>());
	for (int i = 1; i <= (n * m); i++) {
		if (a[i] == r) {
			r = i;
			break;
		}
	}
	r--;
	printf("%d %d", ((r / n) + 1), ((((r / n) + 1) % 2) ? ((r % n) + 1) : (n - (r % n)) ) );
	return 0;
}
