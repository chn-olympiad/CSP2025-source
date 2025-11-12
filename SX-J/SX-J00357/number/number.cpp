#include <bits/stdc++.h>
using namespace std;
//#define int long long
string s;
int v[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			v[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (v[i]--) {
			cout << i;
		}
	}
	return 0;
}