#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 998244353;
int n, m, a[N], ans = 1;
string s;
signed main(){
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		ans = ans * i % mod;
	}
	cout << ans;
	return 0;
}

