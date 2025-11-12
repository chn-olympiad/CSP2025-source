#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[1010][2],t[2];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i ++) {
		cin >> s[i][0] >> s[i][1];
	}
	while (q --) {
		cin >> t[0] >> t[1];
		cout << 0 << '\n';
	}
	return 0;
}

