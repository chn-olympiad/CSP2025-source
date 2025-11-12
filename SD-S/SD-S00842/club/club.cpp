#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 6;
struct Node {
	int a, b, c;
};
int t, n, ans;
Node m[N];
bool flaga = 1;
bool cmp(Node a, Node b) {
	return a.a > b.a;
}
void dfs(int step, int x, int y, int num) {
	int z = n - x - y;
	if (step > n) {
		if (x > n / 2 || y > n / 2 || z > n / 2) return ;
		ans = max(num, ans);
		return ;
	}
	dfs(step + 1, x + 1, y, num + m[step].a);
	dfs(step + 1, x, y + 1, num + m[step].b);
	dfs(step + 1, x, y, num + m[step].c);
}
int main() {
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a >> m[i].b >> m[i].c;
			if (m[i].b != 0 && m[i].c != 0) flaga = 0;
		}
		if (n <= 30) {
			dfs(1, 0, 0, 0);
		} else if (flaga) {
			sort(m + 1, m + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += m[i].a; 
			} 
		} 
		cout << ans << '\n';
	}
	return 0;
}
