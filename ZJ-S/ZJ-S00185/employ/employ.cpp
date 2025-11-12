#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
const int N = 510;
int n , m , c[N] , a[N];
char s[N];
ll ans;

int main () {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf ("%d%d%s" , &n , &m , s + 1);
	for (int i = 1;i <= n;i++) scanf ("%d" , &c[i]);
	for (int i = 1;i <= n;i++) a[i] = i;
	bool ok = 1;
	for (int i = 1;i <= n;i++) ok &= (s[i] - '0');
	for (int i = 1;i <= n;i++) ok &= (a[i] != 0);
	if (n == m) {
		ans = 1;
		for (int i = 1;i <= n;i++) ans = (ans * i) % mod;
		printf ("%lld\n" , ans * ok);
	} else {
		do {
			int cnt = 0;
			for (int i = 1;i <= n;i++) 
				if ((s[i] - '0') == 1&&i - cnt - 1 < c[a[i]])
					cnt++;
			ans = (ans + (cnt >= m)) % mod;
		} while(next_permutation(a + 1 , a + n + 1));
		printf ("%lld\n" , ans);
	}
	return 0;
}