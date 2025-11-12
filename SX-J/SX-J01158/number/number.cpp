#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int b[1000010];
long long n ;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.getline(s, 1000010);
	for (int i = 0; i < 1000010; i++) {
		if ((int)s[i] > 47 && (int)s[i] < 58) {
			b[n] = s[i] - 48;
			n++;
		}
	}
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (b[j] < b[j + 1])
				swap(b[j], b[j + 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << b[i];
	}
	cout << endl;
	return 0;
}
