#include <bits/stdc++.h>
using namespace std;
string s;
multiset< char, greater<> > se;
multiset< char, greater<> > :: iterator it;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			se.insert(s[i]);
		}
	}
	for (it = se.begin(); it != se.end(); it++) {
		cout << *it;
	}
	return 0;
}
