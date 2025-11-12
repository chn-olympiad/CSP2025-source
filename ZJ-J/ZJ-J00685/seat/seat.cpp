#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
struct node {
	int id, grade;
}a[N];
bool cmp(node a, node b) {
	return a.grade > b.grade;
}
int n, m;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		int x;
		cin >> x;
		a[i].grade = x;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++) {
		if(a[i].id == 1) {
			int k = i / (n * 2) * 2 + 1, u = i % (n * 2);
			if(i % (n * 2) > n) {
				k ++;
				u %= n;
				u = n - u + 1;
			}
			cout << k << " " << u;
			return 0;
		}
	}
	return 0;
}