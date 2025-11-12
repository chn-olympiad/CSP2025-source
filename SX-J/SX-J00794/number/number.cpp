#include <bits/stdc++.h>
using namespace std;
int a[1000001], sum;

int cmp(int A, int B) {
	return A > B;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int ls = s.size();
	for (int i = 0; i < ls; i++) {
		if (s[i] <= '0' || s[i] <= '9') {
			a[i] += s[i] - '0';
			sum++;
		}
	}
	sort(a, a + ls, cmp);
	for (int i = 0; i < sum; i++) {
		cout << a[i];
	}
	return 0;
}