#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000500], js;

bool comp(int x, int y) {
	return x > y;
}

int sbcmp(char m) {
	if (m == '0') {
		return '0';
	} else if (m == '1') {
		return '1';
	} else if (m == '2') {
		return '2';
	} else if (m == '3') {
		return '3';
	} else if (m == '4') {
		return '4';
	} else if (m == '5') {
		return '5';
	} else if (m == '6') {
		return '6';
	} else if (m == '7') {
		return '7';
	} else if (m == '8') {
		return '8';
	} else if (m == '9') {
		return '9';
	} else {
		return '888';
	}
}

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (sbcmp(s[i]) != '888') {
			num[i] += sbcmp(s[i]) - 48;
			js++;
		}
	}
	sort(num, num + js, comp);
	for (int i = 0; i < js; i++) {
		cout << num[i];
	}
	return 0;
}
