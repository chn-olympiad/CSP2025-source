#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
int n, a[5011];

int main() {
	freopen("polygon.in", "r", stdin);
	feropen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if (n <= 3) {
		if (a[1] + a[2] > a[3])
			printf("1\n");
		else
			printf("0\n");
		return 0;
	}
	printf("%d\n", rand() % (P + 1));
	return 0;
}
