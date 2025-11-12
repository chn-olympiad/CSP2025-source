#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

const int N = 110;
int n, m, a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int p = 0;
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]), p = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int x = 1, y = 0, flag = 0;
	for (int i = 1; i <= n * m; i++) {
		if (!flag) {
			++y;
			if (y == n + 1) ++x, y = n, flag = 1;
		} else {
			--y;
			if (y == 0) ++x, y = 1, flag = 0;
		}
		if (a[i] == p) {
			printf("%d %d\n", x, y);
			return 0;
		}
	}
	return 0;
}
