#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int int
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N = 5e5 + 10;
int n, k, a[N], s[N], f[N]; map<int,int> m; 

void solve() {
	
	cin >> n >> k; 
	for(int i=1;i<=n;i++) 
		cin >> a[i], s[i] = (s[i-1]^a[i]); 
	
	m[0] = 0; 
	for(int i=1;i<=n;i++) {
		f[i] = f[i-1]; 
		if(m.count(s[i]^k) > 0) 
			f[i] = max(f[i], f[m[s[i]^k]]+1); 
		m[s[i]] = i; 
	}
	
	cout << f[n]; 
	
}

signed main() {

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout); 

//  int _; cin >> _; while(_--)
    solve();

    return 0;

}
