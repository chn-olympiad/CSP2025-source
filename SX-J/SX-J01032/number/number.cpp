#include <bits/stdc++.h>
using namespace std;

char n;
int a[1000005], la, t;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> n) {
		if (n >= '0' && n <= '9') {
			a[++la] = n - '0';
			if (n == '0')
				t++;
		}
	}
	sort(a + 1, a + la + 1, cmp);
	if (t == la)
		cout << 0;
	else
		for (int i = 1; i <= la; i++)
			cout << a[i];
	return 0;
}