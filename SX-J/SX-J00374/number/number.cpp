#include <bits/stdc++.h>
using namespace std;
int b[1000000], j;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[j] == a[i] + '0';
			j++;
		}
	}
	for (int i = 1; i < j; i++) {
		if (b[i] > b[i - 1]) {
			int p = b[i];
			b[i] = b[i - 1];
			b[i - 1] = p;
		}
	}
	for (int i = 0; i < j; i++) {
		cout << b[i];
	}
	return 0;
}