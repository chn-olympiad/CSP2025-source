#include <bits/stdc++.h>
using namespace std;
string a;
int sum = 0;

int cmp(int x, int y) {
	return x > y;
}

int b[1000010] = {0};
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, a);
	int n = a.size();
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[flag] = a[i] - '0';
			flag++;
		}
	}
	sort(b, b + flag, cmp);
	for (int i = 0; i < flag; i++) {
		cout << b[i];
	}
	cout << endl;
	return 0;
}
