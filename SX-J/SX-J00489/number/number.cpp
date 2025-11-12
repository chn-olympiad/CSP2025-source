#include <iostream>
using namespace std;
string s;
long long a[100005], sum, c, n;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum++;
			a[sum] = s[i] - 48;
		}
	}
	for (int i = 1; i <= sum; i++) {
		for (int k = 1; k <= i; k++) {
			if (a[k] < a[i]) {
				n = a[i];
				a[i] = a[k];
				a[k] = n;
			}
		}
	}
	for (int i = 1; i <= sum; i++) {
		cout << a[i];
	}
	return 0;
}
