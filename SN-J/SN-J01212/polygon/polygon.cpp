//SN-J01212 Æë¾ýºÀ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int P = 998244353;

const int N = 5010;

int n, a[N], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < (1 << n); i++) {
		ll s = 0, mx = 0;
		for(int j = 0; j < n; j++)
			if((i >> j) & 1)
				s += a[j + 1], mx = max(mx, 1LL * a[j + 1]);
		if(s > 2 * mx)
			ans++, ans %= P;
	}
	printf("%d\n", ans);
	return 0;
}
