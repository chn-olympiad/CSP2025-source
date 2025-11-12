#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int sum = 0, s[10];
	cin >> s[10] ;
	for (int i = 1; i <= 9; i++) {
		if (s[i] % s[10] == 0) {
			sum = s[i];
		}
		cout << sum;
	}
}
