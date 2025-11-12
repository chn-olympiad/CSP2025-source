#include <bits/stdc++.h>
using namespace std;
int t, n;

struct stu {
	int a, b, c;
} s[100005];

bool cmp(stu x, stu y) {
	return max(x.a, max(x.b, x.c)) > max(y.a, max(y.b, y.c));
}

int main() {

	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
	cin >> t;
	while (t--) {
		int ans = 0
	}
	return 0;
}
