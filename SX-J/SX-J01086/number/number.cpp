#include <bits/stdc++.h>
using namespace std;
long long b[1000009], c1, c2, c3, c4, c5, c6, c7, c8, c9, c0, i;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >> a;
	for (i = 0; i < a.size() ; i++) {
		if (a[i] == '0')
			c0++;
		else if (a[i] == '1')
			c1++;
		else if (a[i] == '2')
			c2++;
		else if (a[i] == '3')
			c3++;
		else if (a[i] == '4')
			c4++;
		else if (a[i] == '5')
			c5++;
		else if (a[i] == '6')
			c6++;
		else if (a[i] == '7')
			c7++;
		else if (a[i] == '8')
			c8++;
		else if (a[i] == '9')
			c9++;
	}
	for (i = 0; i < c9; i++)
		cout << 9;
	for (i = 0; i < c8; i++)
		cout << 8;
	for (i = 0; i < c7; i++)
		cout << 7;
	for (i = 0; i < c6; i++)
		cout << 6;
	for (i = 0; i < c5; i++)
		cout << 5;
	for (i = 0; i < c4; i++)
		cout << 4;
	for (i = 0; i < c3; i++)
		cout << 3;
	for (i = 0; i < c2; i++)
		cout << 2;
	for (i = 0; i < c1; i++)
		cout << 1;
	for (i = 0; i < c0; i++)
		cout << 0;
	return 0;
}
