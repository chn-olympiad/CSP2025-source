#include <bits/stdc++.h>
using namespace std;
string s;
map<char, int> ma;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long n;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ma[s[i]]++;
		}
	}
	for (char i = '9'; i >= '0'; i--) {
		for (int j = 1; j <= ma[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
