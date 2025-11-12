#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, a[100009][3], t, cnt[3];

void _main() {
	priority_queue<int> q;
	cin >> n;
	cnt[0] = cnt[1] = cnt[2] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
			cnt[0]++;
		if (a[i][0] <= a[i][1] && a[i][1] >= a[i][2])
			cnt[1]++;
		if (a[i][2] >= a[i][1] && a[i][0] <= a[i][2])
			cnt[2]++;
	}
	if (max(max(cnt[0], cnt[1]), cnt[2]) <= (n / 2)) {
		for (int i = 1; i <= n; i++)
			ans += max(a[i][0], max(a[i][1], a[i][2]));
		cout << ans;
	} else {
		if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
			for (int i = 1; i <= n; i++) {
				if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
					q.push((max(a[i][2], a[i][1]) - a[i][0]));
				ans += max(a[i][0], max(a[i][1], a[i][2]));
			}
			for (int i = 1; i <= cnt[0] - (n / 2); i++) {
//				cout << q.top() << endl;
				ans += q.top();
				q.pop();
			}
			cout << ans;
		} else if (cnt[2] > cnt[1] && cnt[0] < cnt[2]) {
			for (int i = 1; i <= n; i++) {
				if (a[i][2] >= a[i][1] && a[i][0] <= a[i][2])
					q.push((max(a[i][0], a[i][1]) - a[i][2]));
				ans += max(a[i][0], max(a[i][1], a[i][2]));
			}
			for (int i = 1; i <= cnt[2] - (n / 2); i++) {
				ans += q.top();
//				cout << q.top() << endl;
				q.pop();
			}
			cout << ans;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i][2] <= a[i][1] && a[i][0] <= a[i][1])
					q.push((max(a[i][0], a[i][2]) - a[i][1]));
				ans += max(a[i][0], max(a[i][1], a[i][2]));
			}
			for (int i = 1; i <= cnt[1] - (n / 2); i++) {
				ans += q.top();
//				cout << q.top() << endl;
				q.pop();
			}
			cout << ans;
		}
	}
	cout << endl;
}

int main() {
	freopen("club5.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
		_main();
	return 0;
}