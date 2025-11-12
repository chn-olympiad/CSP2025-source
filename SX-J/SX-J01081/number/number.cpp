#include <bits/stdc++.h>
using namespace std;
string s;
int t[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			t[s[i] - '0']++;
	}
	for (int i = 1; i <= t[9]; i++)
		cout << "9";
	for (int i = 1; i <= t[8]; i++)
		cout << "8";
	for (int i = 1; i <= t[7]; i++)
		cout << "7";
	for (int i = 1; i <= t[6]; i++)
		cout << "6";
	for (int i = 1; i <= t[5]; i++)
		cout << "5";
	for (int i = 1; i <= t[4]; i++)
		cout << "4";
	for (int i = 1; i <= t[3]; i++)
		cout << "3";
	for (int i = 1; i <= t[2]; i++)
		cout << "2";
	for (int i = 1; i <= t[1]; i++)
		cout << "1";
	for (int i = 1; i <= t[0]; i++)
		cout << "0";
	return 0;
}
