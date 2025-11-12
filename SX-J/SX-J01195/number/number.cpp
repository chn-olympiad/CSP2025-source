#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
string s;
int a[50];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	fast;
	getline(cin, s);
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int b = s[i] - '0';
			a[b]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}