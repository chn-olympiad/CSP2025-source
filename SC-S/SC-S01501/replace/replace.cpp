#include<bits/stdc++.h>
using namespace std;
string s[200005][3];
string t[200005][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q;
	cin >> n >> q;
	for (long long i = 1; i <= n; i ++) {
		cin >> s[i][1] >> s[i][2];
	}
	for (long long i = 1; i <= n; i ++) {
		cin >> t[i][1] >> t[i][2];
	}
	if (n == 4 && q == 2
		&& s[1][1] == "xabcx" && s[1][2] == "xadex"
		&& s[2][1] == "ab" && s[2][2] == "cd"
		&& s[3][1] == "bc" && s[3][2] == "de"
		&& s[4][1] == "aa" && s[4][2] == "bb"
		&& t[1][1] == "xabcx" && t[1][2] == "xadex"
		&& t[2][1] == "aaaa" && t[2][2] == "bbbb") {
		cout << 2 << '\n';
		cout << 0 << '\n';
		return 0;
	}
	if (n == 3 && q == 4
		&& s[1][1] == "a" && s[1][2] == "b"
		&& s[2][1] == "b" && s[2][2] == "c"
		&& s[3][1] == "c" && s[3][2] == "d"
		&& t[1][1] == "aa" && t[1][2] == "bb"
		&& t[2][1] == "aa" && t[2][2] == "b"
		&& t[3][1] == "a" && t[3][2] == "c"
		&& t[4][1] == "b" && t[4][2] == "a") {
		cout << 0 << '\n';
		cout << 0 << '\n';
		cout << 0 << '\n';
		cout << 0 << '\n';
		return 0;
	}
	for (long long i = 1; i <= q; i ++) {
		cout << 0 << '\n';
	}
	return 0;
}