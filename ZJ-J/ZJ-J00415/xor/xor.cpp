#include <bits/stdc++.h>
using namespace std; 
long long n, k, t, a[(long long)1e6 + 10], s[(long long)1e6 + 10], f[(long long)1e6 + 10]; 
long long g[4400000]; 
int main () {
	ios :: sync_with_stdio(0); 
	cin.tie (0); cout.tie(0); 
	freopen("xor.in", "r", stdin); 
	freopen("xor.out", "w", stdout); 
	cin >> n >> k; 
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i], s[i] = s[i - 1] ^ a[i]; 
//		cnt[s[i]].push_back(i); 
	}
	memset(g, -1, sizeof(g)); g[0] = 0; 
	for(int i = 1; i <= n; ++ i) {
		t = k ^ s[i];   //s[j - 1] ^ s[i] = k    k ^ s[i] = s[j - 1]
		f[i] = g[t] + 1; f[i] = max(f[i], f[i - 1]); 
		g[s[i]] = max(g[s[i]], f[i]); 
	} 
	cout << f[n]; 
	return 0; 
}
