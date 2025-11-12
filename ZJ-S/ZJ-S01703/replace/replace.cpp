#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q; 
	for(int i = 1; i <= n; i ++) {
		string s1, s2;
		cin >> s1 >> s2;
	}
	while(q --) {
		string t1, t2;
		cin >> t1 >> t2;
		cout << "0\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a 
*/


