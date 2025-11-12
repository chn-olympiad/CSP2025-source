#include <bits/stdc++.h>
using namespace std;
int a[100005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int sum = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	int s1 = 1, s2 = 0;
	for (int i = 1; i <= n * m; i++) {
		if (s1 % 2 == 1)
			s2++;
		else
			s2--;
		if (s2 == 0) {
			s2 = 1;
			s1++;
		}
		if (s2 == n + 1) {
			s2 = n;
			s1++;
		}
		if (a[i] == sum) {
			break;
		}
	}
	cout << s1 << " " << s2 << endl;
	return 0;
}