#include <bits/stdc++.h>
using namespace std;
struct A {
	int a[4];
}x[500060];
bool cmp(A x1 , A x2) {
	return x1.a[2] > x2.a[2];
}
void once() {
	int n , ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i].a[1] >> x[i].a[2] >> x[i].a[3];
		ans += x[i].a[1];
		x[i].a[2] -= x[i].a[1];
	}
	sort(x + 1 , x + n + 1 , cmp);
	for(int i = 1; i <= n / 2; i++) {
		ans += x[i].a[2];
	}
	cout << ans << "\n";
	return ;
}
int main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)once();
}
