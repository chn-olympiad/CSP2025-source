#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int vis[1000009];
map<int, string>mp;
map<int, string>mp1;
int mpt1 = 1;
int mpt = 1;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace,out", "w", stdout);
	int n, q;
	cin >> n >> q;
	s1 = " ", s2 = " ";
	for (int i = 1; i <= n; i++) {
		string x;
		cin >> x;
		mp[mpt] = x;
		mpt++;
	}
	for (int i = 1; i <= n; i++) {
		string x;
		cin >> x;
		mp1[mpt1] = x;
		mpt1++;
	}
	while (q--) {
		long long cnt = 0;
		string ss1, ss2;
		cin >> ss1 >> ss2;
		ss1 = " " + ss1;
		ss2 = " " + ss2;
		if (ss1 == ss2) {
			cout << 0 << endl;
			break;
		}
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			if (ss1[i] != ss2[i] && s1[i] != ss2[i] && ss1[i] != s2[i]) {
				flag = 0;
			} else {
				vis[i] = 1;
			}
		}
		if (!flag)
			cout << 0 << endl;
		if (flag) {
			for (int i = 1; i <= n; i++) {
				if (vis[i]) {
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
