#include <bits/stdc++.h> 
#define rep(i, a, b) for(int i = a; i <= b; i++) 
#define per(i, a, b) for(int i = a; i >= b; i--)
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0); 
#define int long long 
#define endl "\n" 
const int N = 10 + 7; 
int mp[N][N]; 
int a[N * N]; 
void solve() { 
	int n, m; 
	std::cin >> n >> m; 
	int C = 0; 
	rep(i, 1, n * m) {
		std::cin >> a[i]; 
	}
	C = a[1]; 
	std::sort(a + 1, a + 1 + n * m, std::greater<int>()); 
	int cnt = 0; 
	rep(i, 1, m) {
		if(i % 2 == 1) {
			rep(j, 1, n) {
				mp[j][i] = a[++cnt];
			}
		} else if(i % 2 == 0){
			per(j, n, 1) {
				mp[j][i] = a[++cnt]; 
			}
		}
	
	}
//	
//	rep(i, 1, m) {
//		rep(j, 1, n) {
//			std::cout << mp[i][j] << " "; 
//		}
//		std::cout << endl; 
//	}
//	
	rep(i, 1, m) {
		rep(j, 1, n){
			if(mp[i][j] == C) {
				std::cout << j << " " << i << endl; 
				return ;
			}
		}
	}
}

signed main() {
	freopen("seat.in", "r", stdin); 
	freopen("seat.out", "w", stdout); 
	IOS; 
	solve();
	return 0;  
}

/*
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98

*/
