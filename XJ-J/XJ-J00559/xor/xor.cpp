#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353;
int n;
int a[5010];
int ma = 0;
ll ans = 0;

int main() {
	fropen("ploygon", "r", stdin);
	fropen("ploygon", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), ma = max(ma, a[i]);
	sort(a + 1, a + n + 1);
	if(ma == 1){
		for(int i = 3; i <= n; i++){
			ll p = 1;
			for(int j = 2; j <= i; j++)
				p *= j, p %= mod;
			ans += (p % mod);
		}
		cout << ans << '\n';
		return 0;
	}
	if(n <= 10) {
		for(int S = 1; S < (1 << n); S++) {
			int m = 0, num = 0;
			int row[11];
			for(int i = 1; i <= n; i++)
				if(S & (1 << i))
					row[i] = 1, m = max(m, i), num += a[i];
			if(num > 2 * m)
				++ans;
		}
		cout << ans << '\n';
	}
}
