#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n, k, a[N], cnt1;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] == 1) ++cnt1;
	}
	
	if (k == 1) printf("%d", cnt1);
	else if (k == 0) printf("%d", cnt1 / 2);
	else puts("0");
	
	return 0;
}
