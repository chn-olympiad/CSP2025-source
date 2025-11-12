#include <bits/stdc++.h>
using namespace std;
int a[200001][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	string c;
	int s1a, s1b, s2a, s2b;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> c;
		for (int j = 0; j < c.size(); j++) {
			if (c[j] == 'b') {
				a[j][1] = j;
				a[j][2] = c.size() - j - 1;
				break;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> c;
		for (int j = 0; j < c.size(); j++) {
			if (c[j] == 'b') {
				s1a = j;
				s1b = c.size() - j - 1;
				break;
			}
		}
		cin >> c;
		for (int j = 0; j < c.size(); j++) {
			if (c[j] == 'b') {
				s2a = j;
				s2b = c.size() - j - 1;
				break;
			}
		}
		int s = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][1] <= s1a && a[j][2] <= s1b && a[j][1] <= s2a && a[j][2] <= s2b)
				s++;
		}
		cout << s << "\n";
	}
	return 0;
}