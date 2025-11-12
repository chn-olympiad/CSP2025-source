#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int tong[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int x = s[i] - '0';
		if (x >= 0 && x <= 9)
			tong[x]++;
	}
	for (int i = 9; i >= 0; i--) {
		if (tong[i] != 0) {
			while (tong[i]--) {
				printf("%d", i);
			}
		}
	}



	return 0;
}