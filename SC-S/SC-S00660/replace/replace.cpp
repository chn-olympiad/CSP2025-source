#include<bits/stdc++.h>
using namespace std;
#define int long long
struct P{
	string s1, s2;
}s[200010];
int n, q;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++ i) {
		cin >> s[i].s1 >> s[i].s2;
	}for(int i = 1; i <= q; i ++) {
		int cnt = 0;
		string s1, s2;
		cin >> s1 >> s2;
		for(int j = 1; j <= n; ++ j) {
			string o = s1;
			if(s1.find(s[j].s1) < s1.size()) {
				for(int k = s1.find(s[j].s1), p = 0; p < s[j].s1.size(); ++ k, ++ p) {
					s1[k] = s[j].s2[p];
				}
			}if(s1 == s2) cnt ++ ;
			s1 = o;
		}cout << cnt << endl;
	}
}//