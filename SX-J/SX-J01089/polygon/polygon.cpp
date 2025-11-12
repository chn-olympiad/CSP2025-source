#include <bits/stdc++.h>
using namespace std;
int n, a[5005], f[505], s;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int l = j + 1; l < n; l++) {
				if (a[i] + a[j] + a[l] > 2 * max(max(a[i], a[j]), a[l])) {
					f[s++] = a[i] + a[j] + a[l];
				}
			}
		}
	}
	printf("%d", s * 3);
	return 0;
}