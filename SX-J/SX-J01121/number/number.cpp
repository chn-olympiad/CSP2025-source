#include <bits/stdc++.h>
using namespace std;
string s, a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7'
		        || s[i] == '8' || s[i] == '9' || s[i] == '0') {
			a.push_back(s[i]);
		}
	}
	sort(a.begin(), a.end());
	for (int j = a.size() - 1; j >= 0; j--) {
		cout << a[j];
	}

}
