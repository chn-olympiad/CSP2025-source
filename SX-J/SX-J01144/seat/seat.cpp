#include <bits/stdc++.h>
using namespace std;
int x, y, in, in2, ans1, ans2;
priority_queue <int> a;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d %d", &y, &x, &in);
	a.push(in);
	in2 = in;
	for (int i = 0; i < x * y - 1 ; i++) {
		scanf("%d", &in);
		a.push(in);
	}
	int i = 1;
	while ((!a.empty())) {
		if (in2 == a.top()) {
			if (i % x != 0) {
				ans1 = i / x + 1;
				ans2 = i % x;
			} else {
				ans1 = i / x;
				ans2 = (i - 1) % x;
			}
			break;
		}
		a.pop();
		i++;
	}
	if (ans1 % 2 == 0)
		ans2 = abs(ans2 - y) + 1;
	printf("%d %d", ans1, ans2);
	return 0;
}
