#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 12;
struct P{
	string s1, s2;
}arr[N];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].s1 >> arr[i].s2;
	}
	while(q--) {
		string a, b, c, d;
		cin >> a >> b;
		c = a, d = b;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < a.length(); ++j) {
				bool flag = true;
				for (int k = 0; k < arr[i].s1.length(); ++k) {
					if(arr[i].s1[k] != a[j + k]) {
						flag = false;
						break;
					}
				}
				if(!flag) continue;
				//cout << i << ' ' << j << endl;
				for (int k = 0; k < arr[i].s2.length(); ++k) {
					a[j + k] = arr[i].s2[k];
				}
				break;
			}
			if(a == b) cnt++;
			a = c, b = d;
		}
		cout << cnt << endl;
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
*/