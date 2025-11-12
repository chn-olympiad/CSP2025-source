// 苦心人，天不负，加油！
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 20;

int n, m;
pair<int, int> a[N * N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].first);
		a[i].first = -a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n * m + 1);
	int ans = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].second == 1) {
			ans = i;
			break;
		}
	}
	int hang = 1, lie;
	while (ans - 2 * n > 0) hang += 2, ans -= 2 * n;
	if (ans - n > 0) hang++, lie = 2 * n - ans + 1;
	else lie = ans;
	printf("%d %d", hang, lie);
}
