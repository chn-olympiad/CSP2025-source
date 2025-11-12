#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
const int INF = 2147483647;

int n, q;
string s[maxn][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1;i <= n;i++) cin >> s[i][0] >> s[i][1];
	
	while (q--) {
		string a, b;cin >> a >> b;
		int Len = a.size(), LEN = b.size(), ans = 0;
		
		if (Len ^ LEN) {
			cout << ans << '\n';
			continue;
		}
		
		int fst = INF, lst = -INF;
		
		for (int i = 0;i < Len;i++) if (a[i] ^ b[i]) fst = min(fst, i), lst = max(lst, i);
		
		for (int i = 1;i <= n;i++) {
			int len = s[i][0].size();
			if (Len == len) ans += a == s[i][0] && b == s[i][1];
			
			for (int j = 0;j < Len - len;j++) {
//				cerr << j << ' ' << fst << ' ' << j + len << ' ' << lst << '\n';
				if (j <= fst && j + len > lst) {
					if (a.substr(j, len) == s[i][0] && b.substr(j, len) == s[i][1]) ans++;
//					cerr << a.substr(j, len) << ' ' << s[i][0] << ' ' << b.substr(j, len) << ' ' << s[i][1] << '\n';
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
