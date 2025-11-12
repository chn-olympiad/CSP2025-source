#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],c;
bool b = 1;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld",&a[i]);
		if(b && a[i] != 1) b = 0;
		c += a[i];
	}
	if(b) {
		int res = 1;
		for(int i = 1; i <= n; ++i) res = (res * 2) % 998244353;
		printf("%lld",(res - 1 - n - n * (n - 1) / 2) % 998244353);
	} else {
		int res = 0;
		sort(a + 1,a + n + 1);
		for(int j = 0; j < (1 << n); ++j) {
			int tmp = c,cnt = n,maxn = 0;
			for(int k = 1; k <= n; ++k) {
				if((j >> (k - 1)) & 1) tmp -= a[k],--cnt;
				else maxn = max(maxn,a[k]);
			}
			if(tmp > 2 * maxn && cnt >= 3) res = (res + 1) % 998244353;
		}
		printf("%lld",res);
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],c[5001];
bool b = 1;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld",&a[i]);
		if(b && a[i] != 1) b = 0;
		c[i] = c[i - 1] + a[i];
	}
	if(b) {
		int res = 1;
		for(int i = 1;i <= n;++i){
			res = (res * 2) % 998244353;
		}
		printf("%lld",(res - n - n * (n - 1) / 2) % 998244353);
	} else {
		int res = 0;
		sort(a + 1,a + n + 1);
		for(int i = 3; i <= n; ++i) {
			if(c[i] <= 2 * a[i]) continue;
			int idx = upper_bound(a + 1,a + i + 1,c[i] - 2 * a[i] - 1) - a - 1;//1 ~ idx can delete
			if(idx == i) --idx;
			for(int j = 0; j < (1 << idx); ++j) {
				int tmp = c[i],cnt = i;
				for(int k = 1; k <= idx; ++k) {
					if((j >> (k - 1)) & 1) {
						tmp -= a[k],--cnt;
						if(tmp <= 2 * a[i] || cnt < 3) break;
					}
				}
				if(tmp > 2 * a[i] && cnt >= 3) {
					res = (res + 1) % 998244353;
				}
			}
		}
		printf("%lld",res);
	}
	return 0;
}
*/