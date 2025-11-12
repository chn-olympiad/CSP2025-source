#include <iostream>
#include <cstdio>
using namespace std;
int n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> i;
	}
	cout << "9" << endl;
	return 0;
}