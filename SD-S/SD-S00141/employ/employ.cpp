#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 998244353;

const int N = 1e5 + 5;

int n, m, c[N];

string s;

bool flag[N];

int ans = 0;

void dfs(int x, int d, int last) { // 面试x人， 录取d人 
	if (x == n) {
		if (d >= m) ans ++;
		ans %= mod;
		return;
	}
	else {
		for (int i = 1; i <= n; i ++) {
			if (! flag[i]) {
				if (c[i] <= x - d || s[x] == '0') {
					flag[i] = 1;
					dfs(x + 1, d, i);
					flag[i] = 0;
				}
				else {
					flag[i] = 1;
					dfs(x + 1, d + 1, i);
					flag[i] = 0;
				}
			}
		}
	}
	flag[last] = 0;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n;i ++) {
		cin >> c[i];
	}
	dfs(0, 0, 0);
	cout << ans << '\n';
	return 0;
}




