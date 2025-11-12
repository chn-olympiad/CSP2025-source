#include <bits/stdc++.h>
using namespace std;
char s[1000006];
long long a[1000006], top = 1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (s + 1);
	long long l = strlen(s + 1);
	for (int i = 1; i <= l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[top] = s[i] - '0';
			top++;
		}
	}
	sort(a + 1, a + top + 1, cmp);
	for (int i = 1; i < top; i++) {
		cout << a[i];
	}

	return 0;
}