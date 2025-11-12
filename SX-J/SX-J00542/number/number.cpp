#include <bits/stdc++.h>
using namespace std;
string s;
long long n, m, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '9')
			a9++;
		if (s[i] == '8')
			a8++;
		if (s[i] == '7')
			a7++;
		if (s[i] == '6')
			a6++;
		if (s[i] == '5')
			a5++;
		if (s[i] == '4')
			a4++;
		if (s[i] == '3')
			a3++;
		if (s[i] == '2')
			a2++;
		if (s[i] == '1')
			a1++;
		if (s[i] == '0')
			a0++;
	}
	for (int i = 1; i <= a9; i++)
		cout << 9;
	for (int i = 1; i <= a8; i++)
		cout << 8;
	for (int i = 1; i <= a7; i++)
		cout << 7;
	for (int i = 1; i <= a6; i++)
		cout << 6;
	for (int i = 1; i <= a5; i++)
		cout << 5;
	for (int i = 1; i <= a4; i++)
		cout << 4;
	for (int i = 1; i <= a3; i++)
		cout << 3;
	for (int i = 1; i <= a2; i++)
		cout << 2;
	for (int i = 1; i <= a1; i++)
		cout << 1;
	for (int i = 1; i <= a0; i++)
		cout << 0;
}
