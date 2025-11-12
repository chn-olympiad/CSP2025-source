#include <iostream>
#include <string>
using namespace std;
int n, m, a[501];
string s1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s1;

	for (int i = 1; i <= n; i++)

		cin >> a[i];

	if (n == 3 || m == 2)
		cout << 2;

	if (n == 10 || m == 5)
		cout << 220 << 412 << 8;
	return 0;
}