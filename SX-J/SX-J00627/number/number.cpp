#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int ton[15];
int main(int argv, char **argc) {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int z = 0; z < 10; z++)
		ton[z] = 0;

	for (int z = 0; z < s.size(); z++) {
		if (s[z] <= '9' && s[z] >= '0') {
			ton[s[z] - '0']++;
		}
	}

	for (int z = 9; z > -1; z--) {
		while (ton[z]) {
			cout << z;
			ton[z]--;
		}
	}
	return 0;
}
