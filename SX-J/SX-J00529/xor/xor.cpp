/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll n, k, ans, t = -1, l;
ll a[N],s[N];
bool f[N];

int main() {
	freopen("xor5.in", "r", stdin);
//	freopen("xor.out","w",stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n ; i++ ) {
		scanf("%lld", &a[i]);
		if (a[i] == k) {
			ans++;
			f[i] = true;
		}
		s[i]=s[i-1]^a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (t == -1 && f[i] != true) {
			l = i;
			t = a[i];
		} else if (t != -1 && f[i] != true) {
			t = t ^a[i];
			if (t == k) {
				ans++;
				for (int j = l; j <= i; j++) {
					f[j] = true;
				}
				l = i;
				continue;
			}
		}
		if (f[i] == true || i == n) {
			if (t == -1)
				continue;
			if (t == k && l != i) {
				ans++;
			}
			while (l + 1 < i && l + 1 < n) {
				t = (t ^a[l]);
				if (t == k) {
					ans++;
				}
				l++;
			}
			l = i;
			t = -1;
		}
	}
	cout << ans;
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll n, k, ans, t, cnt;
ll a[N];

struct Node {
	ll s, e;
} s[N];
bool f[N];

bool cmp(Node xx, Node xy) {
	return (xx.e - xx.s < xy.e - xy.s);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n ; i++ ) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		t = a[i];
		if (t == k) {
			ans++;
			f[i] = true;
		}
		for (int j = i + 1; j <= n; j++) {
			t = t ^a[j];
			if (t == k) {
				cnt++;
				s[cnt].s = i;
				s[cnt].e = j;
			}
		}
	}
	sort(s + 1, s + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++) {
		bool flag = false;
		for (int j = s[i].s; j <= s[i].e; j++) {
			if (f[j] == true) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			continue;
		}
		for (int j = s[i].s; j <= s[i].e; j++) {
			f[j] = true;
		}
		ans++;
	}
	cout << ans;
	return 0;
}
