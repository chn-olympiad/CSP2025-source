#include <bits/stdc++.h>
using namespace std;
string a;
int s[1005], d, f;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i <= a.size() - 1; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			s[d] = a[i] - '0';
			d++;
		}
	}
	for (int j = 0; j <= d - 1; j++) {
		for (int i = 0; i <= d - 1; i++) {
			if (s[i] < s[i + 1]) {
				f = s[i];
				s[i] = s[i + 1];
				s[i + 1] = f;
			}
		}
	}
	for (int j = 0; j <= d - 1; j++)
		cout << s[j];
	return 0;
}
