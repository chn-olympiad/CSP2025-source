#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10000008];
ll b[10000008];
ll l[10000008];
ll r[10000008];
int main() {
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	ll n , k , s = 0 , ans = 1;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[i] = (b[i - 1] ^ a[i]);
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(i + j - 1 <= n) {
				if((b[i - 1] ^ b[i + j - 1]) == k) {
					s ++;
					l[s] = i;
					r[s] = i + j - 1;
				}
			}
		}
	}
	if(s == 0) {
		cout << 0 << endl;
	} else if(s == 1) {
		cout << s << endl;
	} else if(n == 2) {
		if(a[1] == k && a[2] == k) {
			cout << 2 << endl;
		} else if(a[1] == k || a[2] == k || (a[1] ^ a[2]) == k) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	} else {
		ll now;
		now = r[1];
		for(int i = 2; i <= s; i ++) {
			if(l[i] > now) {
				ans ++;
				now = r[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
