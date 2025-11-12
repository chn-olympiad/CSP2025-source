#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[150];

int main() {
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int ans = a[1];
	for (int i = 1; i <= n * m; i++) {
		for (int j = i + 1; j <= n * m; j++) {
			if (a[j] > a[i]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	int hang, lie;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == ans) {
			if (i % n == 0)
				lie = i / n;
			else
				lie = i / n + 1;
			if (lie % 2 == 1)
				hang = lie % n + 1;
			else
				hang = m - lie % n;
		}
	}
	printf("%d %d\n", lie, hang);
}
