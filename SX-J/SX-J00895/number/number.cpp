#include <bits/stdc++.h>
using namespace std;
int b[1000005];

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {

		if (a[i] == '0') {
			b[i] = -2;
		}

		else if (a[i] == '1')
			b[i] = 1;
		else if (a[i] == '2')
			b[i] = 2;
		else if (a[i] == '3')
			b[i] = 3;
		else if (a[i] == '4')
			b[i] = 4;
		else if (a[i] == '5')
			b[i] = 5;
		else if (a[i] == '6')
			b[i] = 6;
		else if (a[i] == '7')
			b[i] = 7;
		else if (a[i] == '8')
			b[i] = 8;
		else if (a[i] == '9')
			b[i] = 9;

	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 9)
			cout << 9;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 8)
			cout << 8;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 7)
			cout << 7;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 6)
			cout << 6;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 5)
			cout << 5;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 4)
			cout << 4;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 3)
			cout << 3;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 2)
			cout << 2;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 1)
			cout << 1;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == -2)
			cout << 0;
	}
	return 0;
}
