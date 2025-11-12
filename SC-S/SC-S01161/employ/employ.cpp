#include <bits/stdc++.h> 
#define ll long long 
#define pii pair < int, int > 
#define fir first 
#define sec second 

using namespace std; 

const int N = 505; 

int n, m; 
char ch; 
int s[N]; 
int vis[N]; 
int ans; 
int c[N]; 
int CNT; 

void dfs(int x, int cnt) {
	CNT++; 
	if (x > n) {
		if (n - cnt >= m) ans++; 
		return ; 
	}
//	if (CNT >= 500000000) return ; 
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1; 
			if (s[x] && cnt < c[i]) dfs(x + 1, cnt); 
			else dfs(x + 1, cnt + 1); 
			vis[i] = 0; 
		}
	}
}

signed main() {
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 
	
	scanf("%d%d", &n, &m); 
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &ch); 
		s[i] = ch - '0'; 
	}
	for (int i = 1; i <= n; i++) scanf("%d", c + i); 
	
	dfs(1, 0); 
	
	printf("%d\n", ans); 
	
	return 0; 
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/