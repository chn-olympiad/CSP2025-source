#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	string s;
	int n, sum = 0;
	cin >> s >> n;
	for (int i = 0; i <= 5; i++) {
		if (i != 0) {
			sum ++;
		}
	}
	cout << sum;
	return 0;
}
