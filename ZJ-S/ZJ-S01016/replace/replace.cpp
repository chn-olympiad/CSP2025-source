#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pli pair<ll, int> 
#define fi first
#define se second
const int N = 1e3+10;
struct Node {
	string s;
	string t;
	int len;
};
Node a[N];
int p[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	rep(i, 1, n) {
		cin >> a[i].s >> a[i].t;
		a[i].len = a[i].s.size();
	}
	
	while (q --) {
		ll ans = 0;
		string s;
		cin >> s;
		string t;
		cin >> t;
		int m = s.size();
//		int m = t.size();
//		s = " " + s;
//		t = " " + t;
//		vector <int> p(N);
//		rep(i, 0, m-1) if (i > 0) p[i] = p[i-1] + (s[i]!=t[i]) else p[i] = (s[i]!=t[i]);
		rep(i, 0, m-1) {
			rep(j, 1, n) {
//				string p = a[j].s;
//				string q = a[j].t;
				int len = a[j].len;
				if (i + len - 1 > m-1) {
					continue;
				}
				
//				string ss = s;
				bool flag = 0;
				rep(k, i, i+len-1) {
					if (s[k] != a[j].s[k-i]) {
						flag = 1;
						break;
					}
//					ss[k] = a[j].t[k-i];
					if (a[j].t[k-i] != t[k]) {
						flag = 1;
						break;
					}
				}
				rep(k, 0, i-1) {
					if (s[k]!=t[k]) {
						flag = 1;
						break;
					}
				}
				rep(k, i+len, m-1) {
					if (s[k]!=t[k]) {
						flag = 1;
						break;
					}
				}
				if (!flag) {
//					if (!q) cout << i << ' ' << j << '\n';
					ans ++;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
