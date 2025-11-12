#include <bits/stdc++.h>
using namespace std;
int n, a[5010], s[5010], cnt[5010], ans;

bool cmp(int x, int y){
	return x < y;
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	int j = 1;
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i ++){
		s[i] = s[i - 1] + a[i];
	}
	if(n <= 3){
		if(a[1] + a[2] + a[3] > a[3] * 2){
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	for(int i = 3; i <= n; i ++){
		int c = 1, cc = 1;
		for(int j = 1; j <= n; j ++){
			c *= j;
			c %= 998244353;
		}
		for(int j = 1; j <= i; j ++){
			cc *= j;
			cc %= 998244353;
		}
		for(int j = 1; j <= n - i; j ++){
			cc *= j;
			cc %= 998244353;
		}
		ans += c / cc;
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}
