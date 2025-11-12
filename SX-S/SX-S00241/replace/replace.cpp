#include <bits/stdc++.h>
#define ll long long
#define P pair<long long,long long>

using namespace std;
const int N = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f;

struct stu {
	string a, b;
} arr[N];
ll n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i].a >> arr[i].b;
	}
	while (q--) {
		ll ans = 0;
		string a, b;
		cin >> a >> b;
		for (ll i = 1; i <= n; i++) {
			ll id, len;
			//cout << arr[i].a[0] << endl;
			for (ll j = 0; j < a.size(); j++) {
				if (a[j] == arr[i].a[0]) {
					bool f = 0;
					ll l = 0;
					for (ll k = j; k < arr[i].a.size() + j; k++) {
						if (a[k] != arr[i].a[l]) {
							f = 1;
							break;
						}
						l++;
					}
					if (!f) {
						id = j;
						//cout << id << endl;
						break;
					}
				}
			}
			//cout << id << " " << id + arr[i].a.size() << endl;
			bool flag = 0;
			for (ll j = 0; j < id; i++) {
				if (a[j] != b[j])
					flag = 1;
				break;
			}
			ll tot = 0;
			for (ll j = id; j < id + arr[i].a.size(); j++) {
				if (arr[i].b[tot++] != b[j]) {
					flag = 1;
				}
			}
			for (ll j = id + arr[i].a.size(); j < a.size(); j++) {
				if (a[j] != b[j]) {
					flag = 1;
					break;
				}
			}
			if (!flag)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
