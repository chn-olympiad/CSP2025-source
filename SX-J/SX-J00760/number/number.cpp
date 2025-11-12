#include <bits/stdc++.h>
#define int long long
using namespace std;
int a8 = 0, a7 = 0, a6 = 0, a5 = 0, a4 = 0, a3 = 0, a2 = 0, a1 = 0, a0 = 0;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	getline(cin, a);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			if (a[i] == '9')
				cout << 9;
			else if (a[i] == '8')
				a8++;
			else if (a[i] == '7')
				a7++;
			else if (a[i] == '6')
				a6++;
			else if (a[i] == '5')
				a5++;
			else if (a[i] == '4')
				a4++;
			else if (a[i] == '3')
				a3++;
			else if (a[i] == '2')
				a2++;
			else if (a[i] == '1')
				a1++;
			else if (a[i] == '0')
				a0++;
		}
	}
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
	for (int i = 1; i <= a0; i++) {
		cout << 0;
	}
	return 0;
}
