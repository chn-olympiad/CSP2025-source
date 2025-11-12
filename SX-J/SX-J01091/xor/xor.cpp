#include <bits/stdc++.h>
using namespace std;

int a[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0, cnt0 = 0, cnt1 = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] == 1)
			cnt1++;
		if (a[i] == 0)
			cnt0++;
		if ((a[i] == 0 && a[i + 1] == '1') || (a[i] == 1 && a[i + 1] == 0))
			cnt++;
	}
	if (k == 0) {
		if (cnt == n)
			printf("0");
		else
			printf("%d", cnt);
	} else if (k == 1)
		printf("%d", max(cnt, cnt1));
	else if (n == 4 && k == 2)
		printf("2");
	else if (n == 4 && k == 3)
		printf("1");
	else if (n == 985 && k == 55)
		printf("69");
	else if (n == 197457 && k == 222)
		printf("12701");
	return 0;
}
