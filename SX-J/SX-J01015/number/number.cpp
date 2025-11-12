#include <bits/stdc++.h>
using namespace std;
string st;
int a[1000010], s = 1, sum = 0;

bool cmp(int x, int y ) {
	return x > y;
}

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] >= '0' && st[i] <= '9') {
			a[s] = st[i] - '0';
			s++;
		}
	}
	s--;
	sort(a + 1, a + s + 1, cmp);
	for (int i = 1; i <= s; i++) {
		printf("%d", a[i]);
	}
	return 0;
}
