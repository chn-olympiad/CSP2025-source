#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, tt, dp[500005], ans, cnt1, cnt2, cnt3;

struct node1 {
	int a1, a2, a3;
} p[500005];

struct node2 {
	ll id, w, cnt1, cnt2, cnt3;
} t;
queue<node2> que;

inline bool cmp1(node1 a, node1 b) {
	return a.a1 > b.a1;
}

inline bool cmp2(node1 a, node1 b) {
	return a.a2 > b.a2;
}

inline bool cmp3(node1 a, node1 b) {
	return abs(a.a1 - a.a2) < abs(b.a1 - b.a2);
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> tt;
	while (tt--) {
		cin >> n; //n¸öÈË
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].a1 >> p[i].a2 >> p[i].a3;
		}
		if (n >= 20) {
			stable_sort(p + 1, p + n + 1, cmp1);
			for (int i = 1; i <= n; i++) {
				ans += p[i].a1;
				cnt1++;
			}
			stable_sort(p + 1, p + n + 1, cmp2);
			for (int i = 1; i <= n; i++) {
				if (p[i].a2 >= p[i].a1) {
					ans = ans - p[i].a1 + p[i].a2;
					cnt1--;
					cnt2++;
				}
			}
			stable_sort(p + 1, p + n + 1, cmp3);
			for (int i = 1; i <= n; i++) {
				if (cnt1 == cnt2)
					break;
				if (cnt1 < cnt2 and p[i].a1 < p[i].a2) {
					ans = ans - p[i].a2 + p[i].a1;
					cnt2--;
					cnt1++;
				}

				if (cnt1 > cnt2 and p[i].a1 > p[i].a2) {
					ans = ans - p[i].a1 + p[i].a2;
					cnt1--;
					cnt2++;
				}
			}
			cout << ans << "\n";
			continue;
		}
		t = {1, p[1].a1, 1, 0, 0};
		que.push(t);
		t = {1, p[1].a2, 0, 1, 0};
		que.push(t);
		t = {1, p[1].a3, 0, 0, 1};
		que.push(t);

		while (!que.empty()) {
			ll sum = que.front().w;
			ll id = que.front().id;
			ll cnt1 = que.front().cnt1;
			ll cnt2 = que.front().cnt2;
			ll cnt3 = que.front().cnt3;
			que.pop();
			if (id < n) {
				if (cnt1 < n / 2) {
					t = {id + 1, sum + p[id + 1].a1, cnt1 + 1, cnt2, cnt3};
					que.push(t);
				}
				if (cnt2 < n / 2) {
					t = {id + 1, sum + p[id + 1].a2, cnt1, cnt2 + 1, cnt3};
					que.push(t);
				}
				if (cnt3 < n / 2) {
					t = {id + 1, sum + p[id + 1].a3, cnt1, cnt2, cnt3 + 1};
					que.push(t);
				}
			} else
				ans = max(ans, sum);
		}
		cout << ans << "\n";
	}


	return 0;
}