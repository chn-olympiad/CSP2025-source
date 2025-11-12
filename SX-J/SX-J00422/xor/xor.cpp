#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], lst, ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int tmp = 0;
		for (int j = i; j > lst; j--) {
			tmp ^= a[j];
			if (tmp == m) {
				ans ++;
				lst = i;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
