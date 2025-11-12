#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e6 + 5;
long long int n, m, i, ans1, ans2;
struct node {
	long long int x, t;
}k[N];
bool cmp(node a, node b) {
	return a.x > b.x;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (i = 1; i <= n * m; i ++) {
		cin >> k[i].x;
		k[i].t = i;
	}
	sort(k + 1, k + 1 + (n * m), cmp);
	ans1 = 1, ans2 = 0;
	for (i = 1; i <= n * m; i ++) {
		if (ans1 % 2 == 1)
			ans2 ++;
		if (ans1 % 2 == 0)
			ans2 --;
		if (ans2 > n || ans2 < 1) {
			ans1 ++;
			if (ans1 % 2 == 1)
				ans2 = 1;
			else
				ans2 = n;
		}
		if (k[i].t == 1)
			break;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
