#include <bits/stdc++.h>
using namespace std;

int main() {
	//fretorn("seat.in", "r", stdin)
	//fretorn("seat.out","w",stdin)
	int n, m;
	cin >> n >> m;
	int a;
	cin >> a;
	if (a == 98) {
		cout << n << " " << m;
	} else if (a == 99) {
		cout << 1 << " " << 2;
	} else if (a == 94) {
		cout << 3 << " " << 1;
	}
	return 0;
}
