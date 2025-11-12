// 张洛川 高新第二初级中学 SN-J00375 
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m;
int a[N];

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n*m; i++) {
		scanf("%d", &a[i]);
	}
	int k = a[1], id = -1;
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++) {
		if (a[i] == k) {
			id = i;
		}
	}
	int c, y, r;
	if (id % n == 0) {
		c = id/n;
	} else {
		c = id/n+1;
	} 
	y = id-(c-1)*n;
	if (c % 2 == 1) {
		r = y;
	} else {
		r = n-y+1;
	}
	printf("%d %d\n", c, r);
	return 0;
}
