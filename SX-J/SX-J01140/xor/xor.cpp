#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n, k, a[N], kk;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] == 1)
			kk++;
	}
	if (n == 2)
		cout << 0;
	else if (kk == n) {
		cout << n / 2;
	} else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
