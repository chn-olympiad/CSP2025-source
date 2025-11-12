#include <bits/stdc++.h>
using namespace std;
char s[10086];
char b[10086];
int k;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.lenth();
	for (int i = 1; i <= strlen(s); i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '9') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '8') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '7') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '6') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '5') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '4') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '3') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '2') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '1') {
			b[k] = s[i];
			k++;
		}
	}
	for (int i = 1; i <= strlen(s); i++) {
		if (s[i] == '0') {
			b[k] = s[i];
			k++;
		}
	}
	cout << b[k];
	return 0;
}
