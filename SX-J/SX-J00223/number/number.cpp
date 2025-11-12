#include <bits/stdc++.h>
using namespace std;
string a;
int num[10], q;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			num[a[i] - '0']++;
			if (a[i] > '0')
				q++;
		}
	}
	for (int i = 9; i >= 0;) {
		if (num[i]) {
			printf("%d", i);
			num[i]--;
			if (q == 0 && i == 0)
				break;
		} else
			i--;
	}
	return 0;
}
