#include <bits/stdc++.h>
using namespace std;
bool mode1, mode2;
struct Node {
	long long a, b, c;
} a[100005];
struct Status {
	int mode;/*1:->a 2:->b 3:->c*/
	int cha;
	int id;
	Status() {  ;}
	Status(int A, int B, int C) {
		mode = A, cha = B, id = C;
	}
};
long long n;
bool cmp1(Node a, Node b) {
	if (a.a == b.a) {
		return a.b > b.b;
	}
	return a.a > b.a;
}
bool cmp2(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return ::a[a.first].b > ::a[b.first].b;
	return a.second > b.second;
}
bool cmp3(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return ::a[a.first].a > ::a[b.first].a;
	return a.second > b.second;
}
bool cmp4(Status a, Status b) {
	if (a.cha == b.cha) {
		return ::a[a.id].a > ::a[b.id].a;
	}
	return a.cha > b.cha;
}
void solve() {
	mode1 = mode2 = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].b >> a[i].c;
		if (a[i].b != 0 or a[i].c != 0) mode1 = 0;
		if (a[i].c != 0) mode2 = 0;
	}
	long long ans = 0;
	if (mode1) {
		sort(a + 1, a + 1 + n, cmp1);
		for (int i = 1; i <= n / 2; i++) {
			ans += a[i].a;
		}
		cout << ans << '\n';
		return;
	}
	else if (mode2) {
		vector<int> adab, axiaob;
		for (int i = 1; i <= n; i++) {
			if (a[i].a > a[i].b) {
				adab.push_back(i);
			}
			else axiaob.push_back(i);
		}
		if (adab.size() <= n / 2) {
			for (auto i : adab) {
				ans += a[i].a;
			}
			vector<pair<int, int>> q;
			for (auto i : axiaob) {
				q.push_back(pair<int, int>{i, a[i].b - a[i].a});
			}
			sort(q.begin(), q.end(), cmp2);
			for (int i = 0; i < n / 2; i++) {
				ans += a[q[i].first].b;
			}
			for (int i = n / 2; i < q.size(); i++) ans += a[q[i].first].a;
			cout << ans << '\n';
			return;
		}
		else {
			for (auto i : axiaob) {
				ans += a[i].b;
			}
			vector<pair<int, int>> q;
			for (auto i : adab) {
				q.push_back(pair<int, int>{i, a[i].a - a[i].b});
			}
			sort(q.begin(), q.end(), cmp3);
			for (int i = 0; i < n / 2; i++) {
				ans += a[q[i].first].a;
			}
			for (int i = n / 2; i < q.size(); i++) ans += a[q[i].first].b;
			cout << ans << '\n';
			return;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			ans += max(a[i].a, max(a[i].b, a[i].c));
		}
		cout << ans << '\n';
		return;
	}
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
//20
