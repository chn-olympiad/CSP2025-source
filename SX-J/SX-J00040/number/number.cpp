#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s[1000010];
	cin >> s[1000010];
	string n;
	int k = 0;
	string x;
	for (int i = 0; i < 1000010; i++) {
		cout << s[i] << endl;
		if ((s[i] > -1) && (s[i] < 10)) {
			k++;
			cout << k << endl;
			n[k] = s[i];
		}
		for (int j = 1; j < k + 1; j++) {
			if (n[j] < n[j + 1]) {
				x[j] = n[j];
				n[j] = n[j + 1];
				n[j + 1] = x[j];
			}
		}
	}
	cout << n << endl;
	return 0;
}
