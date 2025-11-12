#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1000000];

void sc(int n, int m) {
	for (int i = 0; i < m; i++) {
		if (a[i] == n) {
			cout << a[i];
			a[i] = 10;
		}

	}
}

//#Shang4Shan3Ruo6Shui4
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	getline(cin, s);
	int b = 0, c = 9;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 48 && s[i] < 58) {
			a[b] = s[i] - '0';
			b++;
		}
	}
	for (; c >= 0; c--) {
		sc(c, b);
	}



	return 0;
}
