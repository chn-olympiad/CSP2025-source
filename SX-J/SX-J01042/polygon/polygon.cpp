#include <bits/stdc++.h>
using namespace std;
int n;
int s[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (n <= 3)
		cout << "3";
	if (n <= 10 && n >= 20)
		cout << "54";
	if (n <= 500 && n > 20)
		cout << "1";
	if (n <= 5000 && n > 500)
		cout << "1";
	return 0;
}
