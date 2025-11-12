#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define maxn 1000007
const int INF = 1e9 + 7;
int n, q, ans;
string sa[maxn], sc[maxn];
string qa, qb;
void solve (string qa, int x) {
	cout << qa << " " << x < "\n";
	if (qa == qb) {
		ans ++;
		return ;
	}
	for (int i = 1; i <= n; i ++) {
		string s = qa.substr(x, sa[i].size());
		if (s == sa[i]) {
			solve (qa.substr(0, x) + sc[i] + qa.substr(x + sa[i].size(), qa.size() - x - sa[i].size()), x + sa[i].size());
		}
	}
	if (qa[x] == qb[x]) {
		solve(qa, x + 1);
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;cin.get();
	for (int i = 1; i <= n; i ++) {
		cin >> sa[i] >> sc[i];
	}
	while (q --) {
		cin >> qa >> qb;
		ans = 0;
		solve(qa, 0);
		cout << ans << "\n";
	}
	return 0;
}

