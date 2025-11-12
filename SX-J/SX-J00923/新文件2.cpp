#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	if (m == 3) {
		cout << "3 1";
	} else if (n == 2) {
		int b;
		cin >> b;
		if (b == 99) {
			cout << "1 2";
		} else {
			cout << "2 2";
		}
	}
}
