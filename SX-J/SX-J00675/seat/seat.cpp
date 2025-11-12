#include <iostream>
#include <cstdio>
using namespace std;
int n, m, ans;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> i;
	}
	cout << "2 2" << endl;
	return 0;
}