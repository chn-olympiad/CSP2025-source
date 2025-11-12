#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n;
ll N = 1e5 + 10;
typedef pair<ll, ll> pii;

struct node {
	ll o1, o2, o3;
	bool use = 0;
};


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ll y = n / 2;
		vector<node> arr(n + 1);
		vector<pii> a1;
		vector<pii> a2;
		vector<pii> a3;
		ll tot1 = 0, tot2 = 0;
		for (ll i = 0; i < n; i++) {
			cin >> arr[i].o1 >> arr[i].o2 >> arr[i].o3;

			ll maxn = max(arr[i].o1, max(arr[i].o2, arr[i].o3));
			if (arr[i].o2 == arr[i].o3 && arr[i].o2 == 0)
				tot1++;
			else if (arr[i].o2 != arr[i].o3 && arr[i].o3 == 0)
				tot2++;
			if (arr[i].o1 == maxn)
				a1.push_back({arr[i].o1, i});
			else if (arr[i].o2 == maxn)
				a2.push_back({arr[i].o2, i});
			else
				a3.push_back({arr[i].o3, i});
		}
		if (tot1 == n) {
			sort(a1.begin(), a1.end());
			reverse(a1.begin(), a1.end());
			ll sum = 0;
			for (ll i = 0; i < y; i++) {
				sum += a1[i].first;
			}
			cout << sum << endl;
			continue;
		} else if (tot2 == n) {
			ll sum = 0;
			sort(a1.begin(), a1.end());
			reverse(a1.begin(), a1.end());
			sort(a2.begin(), a2.end());
			reverse(a2.begin(), a2.end());
			if (a1.size() <= y && a2.size() <= y) {
				for (ll i = 0; i < a1.size(); i++) {
					sum += a1[i].first;
				}
				for (ll i = y; i < a1.size(); i++) {
					ll m = a1[i].second;
					sum += arr[m].o2;
				}
				for (ll i = 0; i < a2.size(); i++) {
					sum += a2[i].first;
				}
				cout << sum << endl;
				continue;
			} else if (a1.size() > y) {
				for (ll i = 0; i < y; i++) {
					sum += a1[i].first;
				}

				for (ll i = 0; i < a2.size(); i++) {
					sum += a2[i].first;
				}
				cout << sum << endl;
				continue;

			} else {
				for (ll i = 0; i < y; i++) {
					sum += a2[i].first;
				}

				for (ll i = 0; i < a1.size(); i++) {
					sum += a1[i].first;
				}
				cout << sum << endl;
				continue;
			}
		}
		ll sum = 0;
		sort(a1.begin(), a1.end());
		reverse(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		reverse(a2.begin(), a2.end());
		sort(a3.begin(), a3.end());
		reverse(a3.begin(), a3.end());
		for (ll i = 0; i < a1.size(); i++) {
			sum += a1[i].first;
		}
		for (ll i = 0; i < a2.size(); i++) {
			sum += a2[i].first;
		}
		for (ll i = 0; i < a3.size(); i++) {
			sum += a3[i].first;
		}
		cout << sum << endl;
		continue;

	}
	return 0;
}
