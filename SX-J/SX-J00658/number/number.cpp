#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	long long b[a.size() + 3] = {};
	long long j = 0;
	for (long long i = 0; i < a.size(); i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
			j++;
			b[j] = a[i] - '0';

//			cout << a[i] - '0' << " ";
		}
	}
//	cout << endl;
//	cout << j << endl;
//	for (int i = 1; i <= j; i++) {
//		cout << b[i];
//	}
//	cout << endl;
	sort(b + 1, b + j + 1);
	for (long long i = j; i >= 1; i--) {
		cout << b[i];
	}
	return 0;
}
