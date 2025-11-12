#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

struct Node {
	string s1, s2;
}a[N];

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		string s1, s2; cin >> s1 >> s2;
		a[i] = {s1, s2};
	}
	while(q --) {
		string t1, t2; cin >> t1 >> t2;
		int cnt = 0;
		
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; j < t1.size(); j ++) {
				if(j + a[i].s1.size() - 1 >= t1.size()) break;
				if(t1.substr(j, a[i].s1.size()) == a[i].s1) {
					string g = t1;
					for(int k = j; k <= j + a[i].s1.size() - 1; k ++) g[k] = a[i].s2[k - j];
					if(g == t2) {
						cnt ++;
						break;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}


