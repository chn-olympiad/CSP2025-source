#include <bits/stdc++.h>
using namespace std;

bool cmp(int  a, int b) {
	return a > b;
}

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	int k = 0, max = 0, g, s1, a[10005];
	string s;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			k++;
			if (k == 1) {
				cout << s[i];
			} else if (k == 2) {
				cout << "11";
			}

		}
	}
	return 0;
}