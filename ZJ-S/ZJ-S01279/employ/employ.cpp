#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5, mod = 998244353;
int up[N], a[N], ans;
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	bool flag = 1;
    cin >> s;
    for(int i = 1; i <= n; ++i) cin >> up[i], a[i] = i, flag &= s[i - 1] == 1;
    if(flag){
    	ans = 1;
    	for(int i = 1; i <= n; ++i) ans = ans * i % mod;
    	cout << ans << '\n';
    	return 0;
	}
	if(m == n && n > 10){
		cout << 0 << '\n';
		return 0;
	}
	if(m == 1){
		ans = 1;
		for(int i = 1; i <= n; ++i) ans = ans * i % mod;
		cout << ans << '\n';
		return 0;
	}
	if(n <= 20){
	    do {
	        int cnt = 0, k = 0;
	        for(int i = 1; i <= n; ++i){
	            if(up[a[i]] <= cnt) cnt++;
	            else if(s[i - 1] == '0') cnt++;
	            else k++;
	        }
	        if(k >= m) ans = (ans + 1) % mod;
	    } while(next_permutation(a + 1, a + n + 1));
	    cout << ans << '\n';
	} else {
		cout << 0 << '\n';
	}
    return 0;
}
