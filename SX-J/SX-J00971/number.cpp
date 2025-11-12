#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[100005];
	string s;
	cin >> s;
	if (s.size() == 1) {
		cout << s;
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
		a[i] = s[i] - '0';
	sort(a, a + s.size());
	for (int i = s.size() - 1; i >= 0; i--)
		cout << a[i];
	return 0;
}
