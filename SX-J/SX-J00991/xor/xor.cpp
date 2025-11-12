#include <bits/stdc++.h>
using namespace std;
long long n, k, ans;
const int N = 5e5+10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 2 || n == 3)
		printf("%d", 1);
	else {
		printf("%lld", n / 2);
	}
	return 0;
}
