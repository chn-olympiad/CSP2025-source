#include <bits/stdc++.h>

#define mod 998244353

#define N ((int)5e2 + 10)

using namespace std;

int n, m;
int s[N], c[N];

int _ans, st[15], vis[15];
inline void dfs(int x) {
	if(x == n + 1) {
		int lst = 0, cnt = 0;
		for(int i = 1;i <= n;i++) {
			if(lst >= c[st[i]]) {
				++lst;
				continue;
			}
			
			if(s[i]) {
				++cnt;
			}
			else {
				++lst;
			}
		}
		if(cnt >= m) {
			_ans = (_ans + 1) % mod;
#ifdef XYX
//			for(int i = 1;i <= n;i++) {
//				cout << st[i] << " ";
//			}
//			cout << endl;
#endif
		}
		return;
	}
	
	for(int i = 1;i <= n;i++) {
		if(vis[i]) continue;
		
		vis[i] = 1;
		st[x] = i;
		dfs(x + 1);
		st[x] = 0;
		vis[i] = 0;
	}
}

int main() {
#ifdef XYX
#else 
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	for(int i = 1;i <= n;i++) {
		cin >> c[i];
	}
	
	if(1||n <= 10) {
		_ans = 0;
		dfs(1);
		cout << _ans;
	}
	
	return 0;
}

/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/