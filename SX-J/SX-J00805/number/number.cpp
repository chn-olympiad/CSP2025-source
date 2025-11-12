#include <bits/stdc++.h>
using namespace std;
int a[100005];

bool ans(char q, char w) {
	return q > w;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s, b;
	int c = -1;
	cin >> b;
	int l = s.size();
	if (l == 1 && b[0] >= '0' && b[0] <= '9') {
		cout << b;
	}
	for (int i = 0; i < l; i++) {
		if (b[0] >= '0' && b[0] <= '9') {
			c++;
			s[c] = b[i];
		}
	}
	int sum = c ;
	sort(a + 1, a + 1 + sum, ans);
	for (int i = 1; i <= sum; i++) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
