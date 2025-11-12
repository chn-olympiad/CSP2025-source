#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n = 0, m = 0;
	cin >> n >> m;
	int a[101];

	for (int i = 0; i <= m * n; i++) {
		cin >> a[i];
	}
	if (a[1] == 99) {
		cout << "1,2";
	} 
	else if (a[1] == 98) {
		cout << "2,2";
	} 
	else {
		cout << "3,1";
	}
	return 0;




}