#include <bits/stdc++.h>

using namespace std;

long long n, k;
int a[500001];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (k == 0) {
		bool t = false;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				t = true;
				break;
			}
		}
		if (!t) {
			printf("0");
			return 0;
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0)
				sum++;
		}
		printf("%d", sum);
		return 0;
	} 
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1)
			ans++;
	} 
	printf("%d", ans);
	return 0;
} 
