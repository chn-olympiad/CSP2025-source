#include <bits/stdc++.h>
using namespace std;
string s;
const int A = 1e9+5;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for (int i = 0; i <= n; i++) {
		if (s[i] > '0' && s[i] < '9') {
			cout << s[i];
		}
	}
}
