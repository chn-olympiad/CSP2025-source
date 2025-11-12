#include <cstdio>
int a[500001], cnt = 0, n, k;
void find(int l) {
	bool f = 0;
	for (int i = l; i <= n; i ++ ) {
		int tmp = 0;
		for (int j = i; j <= n; j ++ ) {
			tmp ^= a[j];
			if (tmp == k) {
				cnt ++ , find(j + 1), f = 1;
				break;
			}
		}
		if (f) {
			break;
		}
	}
}
int main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++ ) {
		scanf("%d", &a[i]);
	}
	find(1);
	printf("%d", cnt);
	return 0;
}
