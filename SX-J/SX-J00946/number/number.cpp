#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int a[114514];
	cin >> a[114514];
	int s[114514];
	for (int i = 1; i <= 114514; i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (a[i] > a[j])
				s[i] = a[i - 1];
			for (int k = 0; k <= 114514; k++) {
				cout << s[k];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
