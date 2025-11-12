#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[21];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 21; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= n * m - i; j++) {
			int t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = a[j];
		}
	}
	for (int k = 1; k <= n * m; k++)
		if (a[k] <= a[n])
			return 0;
}
