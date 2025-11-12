#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 8;
int t, n, used[4], ans, flag;
struct node {
	int x, y, z;
} a[maxn];
bool cmp(node u, node v) {
	if (u.x != v.x) return u.x > v.x;
	if (u.y != v.y) return u.y > v.y;
	return u.z > v.z;
}
void func1() {
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i].x;
		cnt++;
		if (cnt == n / 2) {
			cout << sum << "\n";
			break;
		}
	} 
}
int dfs(int idx, int step, int res) {
	if (step == n) {
		return res;
	}
	for (int i = idx + 1; i <= n; i++) {
		if ((used[1] + 1) <= (n / 2)) {
			used[1]++;
			dfs(i, step + 1, res + a[i].x);
			used[1]--;
		}
		if ((used[2] + 1) <= (n / 2)) {
			used[2]++;
			dfs(i, step + 1, res + a[i].y);
			used[2]--;
		}
		if ((used[3] + 1) <= (n / 2)) {
			used[3]++;
			dfs(i, step + 1, res + a[i].z);
			used[3]--;
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		flag = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y == a[i].z && a[i].y == 0) flag++;
		}
		sort(a + 1, a + n + 1, cmp);
		if (flag == n) {
			func1();
			continue;
		}
		used[1]++;
		ans = max(ans, dfs(1, 0, a[1].x));
		used[1]--;
		used[2]++;
		ans = max(ans, dfs(1, 0, a[1].y));
		used[2]--;
		used[3]++;
		ans = max(ans, dfs(1, 0, a[1].z));
		used[3]--;
		cout << ans << "\n";
	}
	return 0;
} 
