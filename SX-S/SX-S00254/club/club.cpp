#include <bits/stdc++.h>
using namespace std;
int t, n, book[100001], cnt[5], sum;

struct f {
	int id, zu, num;
} a[300005];

bool cmp(f x, f y) {
	return x.num > y.num;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		sum = 0;
		memset(a, 0, sizeof(a));
		memset(book, 0, sizeof(book));
		cnt[1] = cnt[2] = cnt[3] = 0;
		cin >> n;
		int p = n / 2;
		for (int i = 1; i <= n; i++) {
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			a[i * 3 - 2] = {i, 1, t1};
			a[i * 3 - 1] = {i, 2, t2};
			a[i * 3] = {i, 3, t3};
		}
		sort(a + 1, a + 3 * n + 1, cmp);
		for (int i = 1; i <= 3 * n; i++) {
			if (book[a[i].id] == 0 and cnt[a[i].zu] <= p - 1) {
				sum += a[i].num;
				book[a[i].id] = 1;
				cnt[a[i].zu]++;
			}

		}
		cout << sum << "\n";;
	}

	return 0;
}
