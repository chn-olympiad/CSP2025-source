#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int t, n;
int siz[4];
long long ans;
struct node {
	int maxn, next, minn;
	int id1, id2, id3;
	friend bool operator < (node a, node b) {
		if (a.minn == b.minn) {
			if (a.next == b.next) 
				return a.maxn > b.maxn;
			return a.next > b.next;
		}
		return a.minn < b.minn;
	}
};
vector<node> stu;
void ini() {
	ans = 0;
	stu.clear();
	memset(siz, 0, sizeof(siz));
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		ini();
		scanf("%d", &n);
		for (int i = 1, a, b, c; i <= n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (a >= b && b >= c) stu.push_back({a, b, c, 1, 2, 3});
			else if (a >= c && c >= b) stu.push_back({a, c, b, 1, 3, 2});
			else if (b >= a && a >= c) stu.push_back({b, a, c, 2, 1, 3});
			else if (b >= c && c >= a) stu.push_back({b, c, a, 2, 3, 1});
			else if (c >= a && a >= b) stu.push_back({c, a, b, 3, 1, 2});
			else if (c >= b && b >= a) stu.push_back({c, b, a, 3, 2, 1});
		}
		sort(stu.begin(), stu.end());
		for (int i = 0; i < n; i++)
			cerr << stu[i].maxn << ' ' << stu[i].next << ' ' << stu[i].minn << ' ' << stu[i].id1 << ' ' << stu[i].id2 << ' ' << stu[i].id3 << '\n';
		cerr << '\n';
		for (int i = 0; i < n; i++) {
			if (siz[stu[i].id1] >= n / 2) {
				if (siz[stu[i].id2] >= n / 2) {
					if (siz[stu[i].id3] >= n / 2) continue;
					siz[stu[i].id3] ++;
					ans += stu[i].minn;
				} else {
					siz[stu[i].id2] ++;
					ans += stu[i].next;
				}
			} else {
				siz[stu[i].id1] ++;
				ans += stu[i].maxn;
			}
			cerr << ans << ' ' << siz[1] << ' ' << siz[2] << ' ' << siz[3] << '\n';
		}
		printf("%lld\n", ans);
	}
	return 0;
}
