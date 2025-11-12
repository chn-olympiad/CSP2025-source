#include <bits/stdc++.h>
using namespace std;
int a[1000005];

bool cmp(int m, int n) {
	return m > n;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int size = 0;
	int ss = s.size();
	for (int i = 0; i < ss; i++) {
		if (s[i] >= '0' && s[i] <= '9') {

			a[i] = s[i] - '0';
			size++;

		}
	}
	sort(a, a + size, cmp);
	for (int i = 0; i < size; i++) {
		cout << a[i];
	}

	return 0;
}
