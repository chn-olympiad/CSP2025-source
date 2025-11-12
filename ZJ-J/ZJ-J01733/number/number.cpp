#include <bits/stdc++.h> 
#define rep(i, a, b) for(int i = a; i <= b; i++) 
#define per(i, a, b) for(int i = a; i >= b; i--)
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0); 
#define int long long 
#define endl "\n" 
const int N = 1e6 + 7; 
int a[N]; 

void solve() { 
	std::string s; std::cin >> s; 
	int len = 0; 
	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[++len] = s[i] - '0'; 
		}
	}
	std::sort(a + 1, a + 1 + len, std::greater<int>()); 
	
	rep(i, 1, len) { 
		std::cout << a[i]; 
	}
	std::cout << endl; 
}

signed main() {
	freopen("number.in", "r", stdin); 
	freopen("number.out", "w", stdout); 
	IOS; 
	solve();
	return 0;  
}
