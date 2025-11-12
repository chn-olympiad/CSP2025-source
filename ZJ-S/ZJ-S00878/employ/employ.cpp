#include <bits/stdc++.h>
using namespace std;
int n,m;
#define ll long long
string s;
int c[505];
const ll MOD = 998244353;
int a[11];
int main () {
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i ++) {
		cin >> c[i];
	}
	int n1 = 0;
	for (int i = 1;i <= n;i ++) {
		if (c[i] != 0)
			n1 ++ ;
	}
	bool ia = true;
	for (int i = 0;i < n;i ++) {
		if (s[i] != '1') {
			ia = false ;
		}
	}
/*	if (ia) {
		sort (a + 1,a + n + 1);
		
		long long ans = 1;
		for (ll i = 1;i <= n;i ++) {
			ans = ans * i % MOD ;
		}
		if (n1 >= m)
			cout << ans << "\n" ;
		else cout << 0 << "\n" ;
	}*/
	if (m == n) {
		long long ans = 1;
		for (ll i = 1;i <= n;i ++) {
			ans = ans * i % MOD ;
		}
		if (ia && n1 == n)
			cout << ans << "\n" ;
		else cout << 0 << "\n" ;
	}
	else if (n <= 10){
		for (int i = 1;i <= n;i ++) a[i] = i;
		int ans = 0;
		do{
			int s1 = 0,s2 = 0;
			for (int i = 1;i <= n;i ++) {
				if (s1 >= c[a[i]] || s[i - 1] == '0') {
					s1 ++ ;
				}
				else s2 ++ ;
			}
			if (s2 >= m) ans ++ ;
		}while (next_permutation(a + 1,a + n + 1));
		cout << ans << "\n" ;
	}
	return 0;
}