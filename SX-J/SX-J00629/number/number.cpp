#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char a[N];
long long ans;
int b[N];
int ai = 1;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a + 1;
	long long len = strlen(a + 1);
	for (int i = 1; i <= len; i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
			b[ai] = a[i] - '0';
			ai++;
		}
	}
	sort(b + 1, b + 1 + (ai - 1), cmp);
	for (int i = 1; i <= ai - 1; i++) {
		cout << b[i];
	}
	return 0;
}
