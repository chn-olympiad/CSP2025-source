#include <bits/stdc++.h>
using namespace std;
const int A = 998244353;
int a[540];
int main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n , m;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	bool b = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != '1')b = 0;
	}
	if(m == n and !b) {
		cout << 0;
		return 0;
	} 
	if(b) {
		int ans = 1;
		for(int i = n; i >= 1; i--) {
			ans *= i;
			ans %= A;
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
