#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, q;
struct node {
	string s, b;
}a[N];
map<string, string> mp;
string x, y;
string jq(string x, int st, int end) {
	string s = "";
	for (int i = st; i <= end; i++) {
		s = s + x[i];
	}
	return s;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		
		cin >> a[i].s>> a[i].b;
		mp[a[i].s] = a[i].b;
	}
	while(q--) {
		int ans = 0;
		cin >> x >> y;
		x = '-' + x;
		y = '-' + y;
		int l = x.size() - 1;
		for (int i = 0; i <= l - 1; i++) {
			if (x[i] != y[i]) {
				break;
			}
			for (int j = i + 2; j <= l + 1; j++) {
				string zj = jq(x, i + 1, j - 1);
				string hm = jq(x, j, l);
				string yd = jq(y, i + 1, l);
				if (mp[zj] != "") {
					zj = mp[zj];
				} else {
					continue;
				}
				string zz = "";
				zz += zj;
				zz += hm;
				if (zz == yd) {
					ans++;
				}
			}
		}
		cout <<ans << "\n";
	}
	return 0;
}	
