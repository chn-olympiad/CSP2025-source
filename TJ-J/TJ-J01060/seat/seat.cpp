#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, size, a[N], score, idx, ans1, ans2;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	size = n * m;
	for (int i = 1; i <= size; ++i) {
		scanf("%d", &a[i]);
	}
	score = a[1];
	
	sort(a + 1, a + size + 1, greater<int>());
	
	for (int i = 1; i <= size; ++i) {
		if (a[i] == score) {
			idx = i;
			break;
		}
	}
	
	ans1 = (idx - 1) / n + 1;
	if (ans1 & 1) {  // 奇数列
		ans2 = (idx - 1) % n + 1;
	} else {  // 偶数列
		ans2 = n - (idx - 1) % n;
	}
	printf("%d %d", ans1, ans2);
	
	return 0;
}
