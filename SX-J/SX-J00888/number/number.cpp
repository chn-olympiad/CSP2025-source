#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005];

bool cmp1(int x, int y) {
	return x > y;
}

int main() {
	fropen("number.in", "r", stdin);
	fropen("number.out", "w", stdout);
	int s = 0;
	cin >> a;
	for (int i = 1; i <= a.size(); i++) {
		if (a[i - 1] >= '0' && a[i - 1] <= '9') {
			b[i] = a[i - 1] - '0';
			s++;
		}
	}
	sort(b + 1, b + s + 1, cmp1);
	for (int i = 1; i <= s; i++) {
		printf("%d", b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
