#include <bits/stdc++.h>
using namespace std;
int a[100000006];

int main() {
	string s;
	int b = 0;
	cin >> s;
	for (int i = 1; i <= sizeof(s); i++) {
		a[i] = s[i];
		b++;
	}
	for (int i = 1; i <= b; i++) {
		for (int j = b; j >= 1; j--) {
			if (a[j - 1] < a[j]) {
				int c = a[j - 1];
				a[j - 1] = a[j];
				a[j] = c;
			}
		}
	}
	for (int i = 1; i <= b; i++) {
		cout << a[i];
	}
	return 0;
}
