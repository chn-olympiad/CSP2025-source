#include <bits/stdc++.h>
using namespace std;

int n, m, t, s;
int a[101];
int c = 1, r = 1;

bool cmp (int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in.txt", "r", stdin);
	freopen("seat.out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	t = n * m;
	for (int i = 1;  i <= t; i++) 
		scanf("%d", a[i]);
	s = a[1];
	sort(a + 1, a + t + 1, cmp);
	for (int i = 1; i <= t; i++) {
		if (a[i] == s) {
			r = i;
			break;
		}
	}
	while (r > n || r < 0) {
		c++;
		if (r < 0) 
			r = abs(r) + 1;
		else {
			r = r - n;
			r = n - r + 1;
		}
	}
	printf("%d %d", c, r);
	return 0;
}
