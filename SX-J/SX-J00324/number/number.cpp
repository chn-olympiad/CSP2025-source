#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10] = {0};
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int t;
			t = s[i] - '0';
			a[t]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (a[i] != 0) {
			cout << i;
			a[i]--;
		}
	}
	return 0;
}
