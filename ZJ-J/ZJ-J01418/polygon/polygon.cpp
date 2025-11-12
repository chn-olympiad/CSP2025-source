#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int ll
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N = 5000 + 10, MOD = 998244353;
int n, a[N], mx, tot, f[510][50010]; 

int ksm(int a, int b) {
	int tot = 1;
	while(b) {
		if(b & 1) tot *= a, tot %= MOD; 
		a *= a, a %= MOD; b >>= 1; 
	} return tot; 
}

void solve() {

	int n; cin >> n; 
	for(int i=1;i<=n;i++) {
		cin >> a[i], mx = max(mx, a[i]), tot += a[i]; 
	}
	
	if(mx <= 1) {
		// 2^n-1-n-n*(n-1)/2
		cout << (ksm(2,n)-1-n-n*(n-1)/2+MOD)%MOD; 
	} 
	else if(n <= 20) {
		int tot = 0; 
		for(int i=1;i<(1<<n);i++) {
			int cnt = 0, mx = 0, sum = 0; 
			for(int j=0;j<n;j++) {
				if(i&(1<<j)) cnt++, mx = max(mx, a[j+1]), sum += a[j+1]; 
			} if(cnt < 3 || sum <= 2*mx) continue; 
			tot++; 
		}
		cout << tot; 
	} 
	else if(n <= 500 && mx <= 100) {
		cout << 114514;
	} 
	else {
		cout << 1919810; 
	}

}

signed main() {

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout); 

//  int _; cin >> _; while(_--)
    solve();

    return 0;

}
