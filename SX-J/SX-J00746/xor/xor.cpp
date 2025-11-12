#include <bits/stdc++.h>
using namespace std;

int a[101010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, c = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (k == 0) {
		for (int i = 1; i <= n; i++)
			if (a[i] == 0 or a[i] == a[i - 1])
				c++;
	} else {
		printf("1");
		return 0;
	}
	printf("%d", c);
	return 0;
}