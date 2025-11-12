#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int len = n * m;
	for (int i = 1; i <= len; i++)
		scanf("%d", &a[i]);
	int x = a[1];
	sort(a + 1, a + len + 1);
	int i = 1, j = 1;
	for (int k = len; k >= 1; k--) {
		if (a[k] == x) {
			printf("%d %d", j, i);
			return 0;
		}
		if (j % 2 == 1) {
			if (i == n)
				j++;
			else if (i < n)
				i++;
		} else {
			if (i == 1)
				j++;
			else if (i > 1)
				i--;
		}

	}
	return 0;
}
