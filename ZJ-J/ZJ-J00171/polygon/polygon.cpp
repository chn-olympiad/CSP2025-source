#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
int n;
ll ans , a[5010] , cnt[500011] , cnt2[500011];
set <int> st , st2;

int main () {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	scanf ("%d" , &n);
	for (int i = 1;i <= n;i++) scanf ("%lld" , &a[i]);
	sort (a + 1 , a + n + 1);
	st.insert(0) , cnt[0]++;
	for (int i = 1;i <= n;i++) {
		if (i >= 3) {
			for (auto x : st) {
				if (x > a[i]) {
					ans = (ans + cnt[x]) % mod;	
				}
			}
		}
		st2.clear();
		for (auto x : st) st2.insert(x + a[i]);
		for (auto x : st2) st.insert(x) , cnt2[x] = cnt[x - a[i]];
		for (auto x : st2) {
			cnt[x] = (cnt[x] + cnt2[x]) % mod;
			cnt2[x] = 0;
		}
	}
	printf ("%lld\n" , ans);
	return 0;
}