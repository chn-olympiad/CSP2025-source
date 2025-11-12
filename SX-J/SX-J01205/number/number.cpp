#include <bits/stdc++.h>
using namespace std;
string a;
int c[12];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int b = a.size();
	int d = 0;
	for (int i = 0; i <= b; i++) {
		d = 0;
		for (char j = '0'; j <= '9'; j++) {
			if (a[i] == j) {
				c[d]++;
				break;
			}
			d++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = c[i]; j > 0; j--) {
			cout << i;
		}
	}
	return 0;
}