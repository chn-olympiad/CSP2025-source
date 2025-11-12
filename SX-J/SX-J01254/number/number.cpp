#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int i1 = 1;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] >= '0' && s[i] <= '9') {
			a[i1] = s[i] - '0';
			i1++;
		}
	i1--;
	sort(a + 1, a + i1 + 1, cmp);
	for (int i = 1; i <= i1; ++i)
		printf("%d", a[i]);
	return 0;
}