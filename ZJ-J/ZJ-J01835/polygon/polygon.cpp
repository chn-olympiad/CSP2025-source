// HSR Elder ID: I have forgotten it 
// HSR Younger ID: 167851258

// Luogu Username: hinin

// Expect: 64pts

#include <bits/stdc++.h>

#define int long long

using namespace std; 

#define pii pair<int, int>
#define x first
#define y second

const int N = 5e3 + 1, MOD = 998244353; 
int n, ans, a[N]; 

int qpow(int a, int b, int p)
{
	int ret = 1 % p; 
	while(b) {
		if(b & 1) ret = ret * a % p;
		b >>= 1;  
		a = a * a % p; 
	}

	return ret; 
}

inline int dfs(int dep, int l, int sum)
{
	if(dep == n + 1) return 0; 

	int ret = 0;
	if(a[dep] < sum/* && l + 1 >= 3*/) ++ ret;  

	ret += dfs(dep + 1, l + 1, sum + a[dep]); 
	ret %= MOD; 
	ret += dfs(dep + 1, l, sum);
	ret %= MOD; 

	return ret;  
}

signed main()
{
	freopen("polygon.in", "r", stdin); 
	freopen("polygon.out", "w", stdout); 
	
	cin.tie(nullptr) -> sync_with_stdio(false); 

	cin >> n; 
	for(int i = 1; i <= n; i ++) cin >> a[i]; 

	sort(a + 1, a + n + 1); 

	if(a[n] == 1) cout << (qpow(2, n, MOD) - 1 - n - n * (n - 1) / 2 + MOD) % MOD << '\n'; 
	else if(n == 3) 
		if(a[1] + a[2] <= a[3]) cout << "0\n"; 
		else cout << "1\n"; 
	else cout << dfs(1, 0, 0) << '\n'; 

	return 0; 
}