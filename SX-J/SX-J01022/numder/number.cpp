#include <bits/stdc++.h>
using namespace std;
char c;
int arr[1000005], i = 1;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> c) {
		if (c >= '0' && c <= '9')
			arr[i++] = c - '0';
	}
	sort(arr + 1, arr + i, cmp);
	for (int j = 1; j < i; j++) {
		cout << arr[j];
	}
	return 0;
}