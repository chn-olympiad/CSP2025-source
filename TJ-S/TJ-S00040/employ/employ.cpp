#include <bits/stdc++.h>
using namespace std;

const int N = 510;
bool vis[N];
int c[N], x[N];
string s;
int n, m, ans;

void dfs(int step, int num) {
	if (step > n) {
		if (n-num >= m) ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		if (num < c[i] && s[step] == '1')
			dfs(step+1,num);
		else
			dfs(step+1,num+1);
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = '?' + s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n <= 18) {
		dfs(1,0);
		cout << ans << "\n";	
	} else {
		cout << 0;
	}
	return 0;
}
//28·Ö°æ 
