#include <bits/stdc++.h>
using namespace std; 
long long T, n, a[(long long)1e5 + 10], b[(long long)1e5 + 10], c[(long long)1e5 + 10], ans; 
long long ma[(long long)1e5 + 10]; 
void dfs(long long x, long long sa, long long sb, long long sc, long long s) {
	if(sa > n / 2 || sb > n / 2 || sc > n / 2) return ; 
	if(s + ma[x] <= ans) return ; 
	if(x > n) {
		ans = max(ans, s); 
		return ; 
	}
	if(a[x] >= b[x] && a[x] >= c[x]) {
		dfs(x + 1, sa + 1, sb, sc, s + a[x]); 
		if(b[x] >= c[x]) dfs(x + 1, sa, sb + 1, sc, s + b[x]), 
		dfs(x + 1, sa, sb, sc + 1, s + c[x]); 
		else dfs(x + 1, sa, sb, sc + 1, s + c[x]), 
		dfs(x + 1, sa, sb + 1, sc, s + b[x]); 
	}
	else if(b[x] >= a[x] && b[x] >= c[x]) {
		dfs(x + 1, sa, sb + 1, sc, s + b[x]); 
		if(a[x] >= c[x]) dfs(x + 1, sa + 1, sb, sc, s + a[x]), 
		dfs(x + 1, sa, sb, sc + 1, s + c[x]); 
		else dfs(x + 1, sa, sb, sc + 1, s + c[x]), 
		dfs(x + 1, sa + 1, sb, sc, s + a[x]); 
	}
	else if(c[x] >= a[x] && c[x] >= b[x]) {
		dfs(x + 1, sa, sb, sc + 1, s + c[x]); 
		if(a[x] >= b[x]) dfs(x + 1, sa + 1, sb, sc, s + a[x]), 
		dfs(x + 1, sa, sb + 1, sc, s + b[x]); 
		else dfs(x + 1, sa, sb + 1, sc, s + b[x]), 
		dfs(x + 1, sa + 1, sb, sc, s + a[x]); 
	}
}
long long check() {
	long long sa  = 0, sb = 0, sc = 0, sum = 0; 
	for(int i = 1; i <= n; ++ i) {
		if(a[i] >= b[i] && a[i] >= c[i]) sa ++, sum += a[i]; 
		else if(b[i] >= a[i] && b[i] >= c[i]) sb ++, sum += b[i]; 
		else if(c[i] >= a[i] && c[i] >= b[i]) sc ++, sum += c[i]; 
		if(sa > n / 2 || sb > n / 2 || sc > n / 2) return 0; 
	}
	return sum; 
}
int main () {
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	freopen("club.in", "r", stdin);  
	freopen("club.out", "w", stdout); 
	cin >> T; 
	while(T --) {
		cin >> n; 
		bool flag = 1; 
		for(int i = 1; i <= n; ++ i) cin >> a[i] >> b[i] >> c[i], flag = flag & ((b[i] == 0) && (c[i] == 0)); 
		//qingling 
		if(flag) {
			sort(a + 1, a + n + 1); 
			long long sum = 0; 
			for(int i = n; i >= n / 2 + 1; ++ i) sum += a[i]; 
			cout << sum << "\n"; 
			continue; 
		}
		long long tmp = check(); 
		if(tmp != 0) {
			cout << check() << "\n"; 
		}
		else {
			ans = 0; ma[n + 1] = 0; 
			for(int i = n; i >= 1; -- i) ma[i] = ma[i + 1] + max(max(a[i], b[i]), c[i]); 
			dfs(1, 0, 0, 0, 0); 			
			cout << ans << "\n"; 			
		}
	}
	return 0; 
}
