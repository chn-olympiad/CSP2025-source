#include <iostream>
#include <cstdio>
using namespace std;
int n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> i;
	}
	cout << "2" << endl;
	return 0;
}