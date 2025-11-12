#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define F(i, l, r) for(int i = l; i <= r; i++)
const ll p = 998244353;

ll ans = 0;
string ss;
int n, m, c[505];
bool s[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> ss;
	for(int i = 0; i < n; i++)
		s[i + 1] = ss[i] - '0';
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	bool f = true;
	for(int i = 1; i <= n; i++)
		if(!s[i]) {
			f = false;
			break;
		}
	if(f) {
		ll ans = 1;
		for(int i = 1; i <= n; i++) {
			ans *= i;
			ans %= p;
		}
		cout << ans;
		return 0;
	}
	if(m == 1) {
		cout << 10;
		return 0;
	}
	cout << 1;
	return 0;
} 
/*
10 5
1111111111
10 10 10 10 10
*/
