#include <bits/stdc++.h>
using namespace std;
string a;
int n;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	n = a.size();
	for (int i = 0; i < n; i++) {
		if ( n == 1 && a >= "1" && a <= "9") {
			cout << a;
		}
		return 0;
	}
}

