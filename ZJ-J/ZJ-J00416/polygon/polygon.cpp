#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005];
bool f1;
int n, ans;
void dfs(int p, int res, int ma) {
	res += a[p];
	ma = max(ma, a[p]);
//	cout << res << ' ' << ma << '\n';
	if(res > 2 * ma) {
		ans++;
//		cout << p << '\n';
	}
	for(int i = p + 1; i <= n; i++) {
//		cout << '\n'<<'\n'<<i <<  '\n';
		dfs(i, res, ma);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    cin >> n;
    if(n < 3) {
    	cout << 0 << '\n';
    	return 0;
	}
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	if(a[i] != 1)f1 = true;
	}
	sort(a + 1, a + n + 1);
	if(!f1) {
		int ans = 0;
		for(int i = 1; i <= n - 2; i++) {
			int r = n - i;
			ans = (ans + (r * (r - 1) / 2 % mod)) % mod;
		}
		cout << ans << '\n';
		return 0;
	}
	if(n == 3) {
		if(a[1] + a[2] > a[3]) {
			cout << 1 << '\n';
			return 0;
		}
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i++) {
	    dfs(i, 0, 0);	
	}
	cout << ans << '\n';
    return 0;
}
//rp++
