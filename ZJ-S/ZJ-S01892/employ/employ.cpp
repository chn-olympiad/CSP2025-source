// HSR Elder UID: I have forgotten
// HSR New UID: 167851258
// Luogu Username: hinin

// Expect: 0pts

#include <bits/stdc++.h>

#define int long long

using namespace std; 

#define pii pair<int, int>
#define x first
#define y second

const int N = 5e2 + 1, MOD = 998244353;
string str;  
int n, m, ans, tns, cnt, a[N]; 

signed main()
{
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 

	cin.tie(nullptr) -> sync_with_stdio(false); 

	cin >> n >> m >> str; 
	for(int i = 1; i <= n; i ++) cin >> a[i]; 

	sort(a + 1, a + n + 1); 

	do {
		int idx = 1; 
		for(char it : str) {
			++ idx; 

			while(a[idx] <= cnt && idx <= n) idx ++; 
			if(idx > n) break;

			if(it == '1') tns ++; 
			else cnt ++; 
		}

		if(tns >= m) ans ++; 
	} while(next_permutation(a + 1, a + n + 1));

	cout << ans << '\n';  

	return 0; 
}