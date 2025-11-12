#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number3.in", "r", stdin);
	freopen("number3.out", "w", stdout);
	char s[1000000];
	string num;
	long n = 0;
	cin >> s;
	int m = strlen(s);
	for (int i = 0; i < m; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			num[n] = s[i];
			n++;
		}
	}
//	for (int i = 0; i < n; i++) {
//		ou[i] = int(num[i]);
//	}
	bool T = true;
	while (T) {
		T = false;
		for (int i = 0; i < n; i++) {
			if (num[i] <= num[i + 1]) {
				swap(num[i], num[i + 1]);
				T = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << num[i] ;
	}
	return 0;
}





