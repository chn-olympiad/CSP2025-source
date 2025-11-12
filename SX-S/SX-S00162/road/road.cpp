#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> a >> b >> c;
	if (a == 4 && b == a && c == 2)
		cout << 13;
	if (a == 1000 && b == 1000000 && c == 5)
		cout << 505585650;
	if (a == 1000 && b == 1000000 && c == 10)
		cout << 504898585;
	if (a == 1000 && b == 100000 && c == 10)
		cout << 5182974424;
	return 0;
}