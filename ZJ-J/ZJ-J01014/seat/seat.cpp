#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[50000];
int mp[300][300];
int x, q;

signed main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n * m; ++i) {
		scanf("%lld", &a[i]);
		if(i == 1)
			x = a[i];
	}
	q = n * m;
	sort(a + 1, a + n * m + 1);
	for(int j = 1; j <= m; ++j) {
		if(j % 2 == 1) {
			for(int i = 1; i <= n; ++i) {
				mp[i][j] = a[q--];
				if(mp[i][j] == x) {
					printf("%lld %lld", j, i);
					return 0;
				}
			}
				
		} else {
			for(int i = n; i >= 1; --i) {
				mp[i][j] = a[q--];
				if(mp[i][j] == x) {
					printf("%lld %lld", j, i);
					return 0;
				}
			}
		}
	}
	return 0;
}