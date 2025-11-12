#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int a[100];
	int c = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
			c++;
		}
	}
	sort(a[0], a[c]);
	for (int i = 0; i < c; i++)
		cout << a[i];
	cout << endl;
	return 0;
}
