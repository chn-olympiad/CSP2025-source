#include <bits/stdc++.h>
using namespace std;

int n, k;
int f[500005], b[500005], a[500005];

int main() {
	//k=2e6
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	f[0] = 0;
	int p = 0;
	for (int i = 1; i <= n; i++) {
		memset(b, 0, sizeof(b));
		f[i] = f[i - 1];
		if (a[i] == k) {
			f[i] = f[i - 1] + 1;
			p = i;
			continue;
		} else  {
			int y = 0;
			b[i] = a[i];
			for (int j = i - 1; j > p; j--) {
				b[j] = b[j + 1] ^ a[j];
				if (b[j] == k) {
					y = 1;
					p = i;
					f[i] = max(f[i], f[j - 1] + 1);
					break;
				}
			}
		}
	}
	printf("%d\n", f[n]);
	return 0;
}