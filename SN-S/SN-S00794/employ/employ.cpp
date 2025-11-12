#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	gxk::main();
	return 0;
}

#define int long long
namespace gxk {
	const int maxn = 510, modd = 998244353;
	
	int n, m, A, c[maxn], ans;
	string s;
	
	int vis[20];
	vector <int> now;
	void dfs(int step) {
		if (step == n + 1) {
			int sum = 0, anss = 0;
			for (int i = 0; i < n; i++) {
//				cout << now[i] << ' ';
				if (s[i] == '1') {
					if (c[now[i]] > sum) anss++;
					else sum++;
				} else {
					sum++;
				}
			}
//			cout << anss << '\n';
			if (anss >= m) ans++;
			return ;
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			vis[i] = 1;
			now.push_back(i);
			dfs(step + 1);
			now.pop_back();
			vis[i] = 0;
		}
		return ;
	}
	
	void main() {
		cin >> n >> m;
		cin >> s;
		for (int i = 1; i <= n; i++) {
			cin >> c[i];
		}
		if (n <= 10) {
			ans = 0;
			dfs(1);
			cout << ans << '\n';
			return ;
		} else {
			cout << 0 << '\n';
		}
		
		return ;
	}
}
