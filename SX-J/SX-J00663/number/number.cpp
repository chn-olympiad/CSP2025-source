#include <bits/stdc++.h>
using namespace std;
int main() {
	//fretorn("number.in", "r", stdin)
	//fretorn("number.out","w",stdin)
	char s[1100000];
	cin >> s;
	int a[1100];
	for (long long i = 0; i < 1100000; i++) {
		if (s[i] < '9' && s[i] > '0') {
			a[i] = s[i];
		}
	}
	for (int i = 0; i < 1100; i++) {
		int z = a[i];
		for (int j = 0; j > 1100; j++) {
			if (a[i] < a[j]) {
				a[i] = a[j];
				a[j] = z;
			}
		}
	}
	for (int i = 0; i < 1100; i++) {
		cout << a[i];
	}
	return 0;
}
