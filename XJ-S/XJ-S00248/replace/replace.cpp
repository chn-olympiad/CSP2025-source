#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, q, ans = 0;
set<pair<string, string>> a;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		string x, y;
		cin >> x >> y;
		a.insert({x, y});
	}
	while(q--) {
		ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int l = t1.size();
		for(int d = 1; d < l; d++) {
			for(int i = 1; i <= l; i++) {
				if(i + d > l)
					break;
				string x = "0", y = "0";
				for(int l = i; l <= i + d; l++)
					x = x + t1[l], y = y + t2[l];
				if(a.find({x, y}) != a.end())
					++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
