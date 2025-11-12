#include <iostream>
#include <cmath>
using namespace std;
string s, b;
int a[10000000], cnt, sum;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (48 <= s[i] && s[i] <= 57) {
			a[cnt] = int(s[i]) - '0';
			cnt++;
		}
	}
	while (1) {
		int flag = 0;
		for (int i = 0; i < cnt; i++) {
			int w = 0;
			if (a[i] > a[i + 1] && i + 1 != cnt) {
				w = a[i];
				a[i] = a[i + 1];
				a[i + 1] = w;
				flag++;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	for (int i = cnt - 1; i >= 0; i--) {
		b = b + char(a[i] + 48);

	}
	cout << b;
	return 0;
}
