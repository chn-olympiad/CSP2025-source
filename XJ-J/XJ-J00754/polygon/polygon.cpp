#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

typedef long long ll;
typedef double db;

typedef vector <int> vi; 

const int mod = 998244353;

int n, a[10000], b[10000];
ll ans;

void mpow(const int &x, const int &y) {
	ans = 1;
	for (int i = 0; i < n; i++)
	    ans = (ans * x) % mod;
	
	ans -= 1 + n + n * (n - 1) / 2;
}

inline void dfs(const int &x, const int &l, const int &s) {
	if (x > n) {
		if (s > l * 2)
		    ans = (ans + 1) % mod;
		
		return;
	}
	if (s + b[x] <= l * 2)
	    return;
	
	dfs(x + 1, l, s);
	dfs(x + 1, max(l, a[x]), s + a[x]);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	    cin >> a[i];
	for (int i = n; i; i--)
	    b[i] = b[i + 1] + a[i];
	
	if (b[1] == n)
	    mpow(2, n);
	else
	    if (n < 100) 
	        dfs(1, 0, 0);
	    else 
	        cout << mpow(2, n);
	
	cout << ans << endl; 
	
	return 0;
}  
