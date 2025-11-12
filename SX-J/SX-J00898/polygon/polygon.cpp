#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	int max;
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (a > b > c > d > e) {
		a = max;
	}
	if ((a + b + c + d) > max * 2) {
		cout << "9";
	}



	return 0;

}
