#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
	int R = a[1], tmp;
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++)
		if (a[i] == R) {
			tmp = i;
			break;
		}
	int r = ceil(tmp * 1.0 / n);
	int c = tmp % n;
	if (c == 0) c = n;
	if (r % 2 == 0) c = n - c + 1;
	printf("%d %d", r, c);
	return 0;
}
