#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int a[100005];
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
		        || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			a[i] = s[i];
			if (s[i] < s[i + 1] ) {
				swap(s[i], s[i + 1]);
			}
			if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
			        || s[i] == '7' || s[i] == '8' || s[i] == '9')
				cout << s[i];
		}
	}
	return 0;
}
