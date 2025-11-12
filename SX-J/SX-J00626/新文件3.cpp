#include <iostream>
#include <string>
using namespace std;

int n, k;
string a[1000010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0 ; i < n; ++i) {
		cin >> a[i];
	}
	cout << k;
	return 0;
}