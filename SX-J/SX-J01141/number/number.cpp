#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int a[100];
	int num = 0;
	int n;
	cin >> s;
	int p = s.size();
	for (int i = 0; i <= p; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num = num + 1;
			a[num] = s[i] - 48;
		}
	}
	for (int i = 1; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			if (a[i] < a[j]) {
				n = a[i];
				a[i] = a[j];
				a[j] = n;
			}
		}
	}
	for (int i = 1; i <= num; i++) {
		cout << a[i];
	}
	return 0;
}
