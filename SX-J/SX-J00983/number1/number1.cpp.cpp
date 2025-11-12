#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i, j, a[10], b = 1, c;
	long long max = 0;
	cin >> s;
	for (i = 0; i <= 9; i++)
		a[i] = 0;
	for (i = 0; i <= 9; i++) {
		for (j = 0; j < s.size(); j++) {
			c = s[j] - 48;
			if (c == i)
				a[i]++;
		}
	}
	for (i = 0; i <= 9; i++) {
		for (j = 1; j <= a[i]; j++) {
			if (i != 0) {
				max += (i *b);
			} else {
				max *= 10;
			}
			b *= 10;
		}
	}
	cout << max;
	return 0;
}
