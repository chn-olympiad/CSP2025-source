#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 2e2 + 10, MOD = 1e9 + 7;
bool cmp(char q, char h) {
	return q > h;
}
signed main(){

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	char ch;
	while (cin >> ch) {
		if (ch >= '0' && ch <= '9') {
			s += ch;
		}
	}
	
	sort(s.begin(), s.end(), cmp);
	cout << s << '\n';
	return 0;
}

