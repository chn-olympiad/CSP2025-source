#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int n, head = 1;
int temp;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.getline(s + 1, 100005);
	for (int i = 1; i <= size(s); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[head++] = s[i] - '0';
		}
	}
	sort(a + 1, a + head);
	for (int i = 1; i <= head / 2; i++) {
		temp = a[i];
		a[i] = a[head - i];
		a[head - i] = temp;
	}
	if (a[1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < head; i++) {
		cout << a[i];
	}
	return 0;
}
