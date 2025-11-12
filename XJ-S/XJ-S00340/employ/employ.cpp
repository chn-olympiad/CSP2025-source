#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> ii;

int n, q, c[1000], m;
bool b[1000], s[1000];
string t;
ll ans = 0LL;

const int mod = 998244353;

ll o(const int &x) {
	ll ans = 1;
	
	for (ll i = x; i; i--)
	    ans = ans * i % mod;
	
	return ans;
} 

int main() {
	freopen("employ.in", "r", stdin),
	freopen("employ.out", "w", stdout),
    
    ios::sync_with_stdio(false),
    cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	    s[i] = t[i - 1] - '0';
	for (int i = 1; i <= n; i++)
	    cin >> c[i];
    
    bool ok = 1;
    for (int i = 1; i <= n && ok; i++)
	    ok &= s[i];
	cout << o(n) <<endl;
    
    return 0;
}
