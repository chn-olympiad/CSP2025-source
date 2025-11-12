#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	//freopen("number", "r", stdin);
	//freopen("number", "w", stdout);
	cin >> s;
	int l = s.size();
	int max = 0;
	int sum = 0;
	sort(a + 1; a + n + 1);
	for (int i = 0; i <= l; i++) {
		if (s[i + 1] > s[i])
			sum = s[i];
		s[i] = s[i + 1];
		s[i + 1] = sum;
	}
	for (int i = 1; i < l; i++) {
		cout << s[i];
	}
	return 0;
}
