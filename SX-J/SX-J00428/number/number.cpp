#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	char s;
	int sum = 0, max = 0;
	cin >> s;
	if (s >= '0' && s <= '9')
		cout << s;
	return 0;
	if (s >= 'a' && s <= 'z' && s >= '0' && s <= '9') {
		for (int i = 0; i <= s; i++) {
			if (s >= '0' && s <= '9')
				s += sum;
		}
	}
	cout << sum;
	return 0;
}