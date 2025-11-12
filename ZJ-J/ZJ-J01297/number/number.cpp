#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b) { return a > b; }

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, a;
	cin >> s;
	for (int i = 0;i < s.length();i++) {
		if (isdigit(s[i])) a += s[i];
	}
	sort(a.begin(), a.end(), cmp);
	cout << a;
	return 0;
} 
