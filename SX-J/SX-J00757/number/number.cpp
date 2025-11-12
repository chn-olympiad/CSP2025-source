#include <bits/stdc++.h>
#define NOI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
string s, a[11];

int main() {
	NOI("number")
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[s[i] - '0'] += s[i];
		}
	}
	for (int i = 9; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
