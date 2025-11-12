#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e5+5;
int n, k, cnt, t;
int a[maxN];
int mmax;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mmax = max(mmax, a[i]);
	}
	printf("%d", mmax - k + 1);
	return 0;
}
