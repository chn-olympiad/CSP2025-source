#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
struct node {
	int to, joy;
}num[100005];
int mp[20005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, res[5] = {}, ans = 0;
		cin >> n;
		FOR(i, 1, n, ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			int cnt = max(a, max(b, c));
			if (cnt == a) {
				num[i].to = 1;
				num[i].joy = a - max(b, c);
				res[1]++;
			} else if (cnt == b) {
				num[i].to = 2;
				num[i].joy = b - max(a, c);
				res[2]++;
			} else {
				num[i].to = 3;
				num[i].joy = c - max(a, b);
				res[3]++;
			}
			ans += cnt;
		}
		FOR(i, 1, 3, ++i) {
			if (res[i] > n / 2) {
				FOR(j, 1, n, ++j) {
					if (num[j].to == i) {
						mp[num[j].joy]++;
					}
				}
				int cnt = res[i] - n / 2;
				FOR(j, 0, 20003, ++j) {
					if (cnt < mp[j]) {
						ans -= cnt * j;
						break;
					}
					ans -= mp[j] * j;
					cnt -= mp[j];
				}
				break;
			}
		}
		memset(mp, 0, sizeof(mp));
		cout << ans << endl;
	}
	return 0;
}