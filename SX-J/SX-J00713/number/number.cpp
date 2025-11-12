#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
vector <char> g;

signed main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0' ||
		        s[i] == '1' ||
		        s[i] == '2' ||
		        s[i] == '3' ||
		        s[i] == '4' ||
		        s[i] == '5' ||
		        s[i] == '6' ||
		        s[i] == '7' ||
		        s[i] == '8' ||
		        s[i] == '9'
		   ) {
			g.push_back(s[i]);
		}
	}

	sort(g.rbegin(), g.rend());
	for ( auto i : g) {
		cout << i;
	}
	return 0;
}