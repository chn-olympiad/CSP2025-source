#include <bits/stdc++.h>
using namespace std;
int a[15];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - '0']++;
		}
	}
	//10^6;
	for (int i = 9; i >= 0; i--) {
		if (a[i] != 0) {
			for (int j = a[i]; j > 0; j--) {
				cout << i;
			}
		}
	}
	//10^6
	return 0;
}
