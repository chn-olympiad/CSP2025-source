// I forgot KMP

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll n, q;

struct information {
	ll s1_b, s2_b, len;
} info[200005], question[200005];

char s1[5000005], s2[5000005];

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i ++) {
		cin >> (s1+1) >> (s2+1);
		info[i].len = strlen(s1+1);
		for (int i = 1; i <= info[i].len; i ++) {
			if (s1[i] == 'b') info[i].s1_b = i;
			if (s2[i] == 'b') info[i].s2_b = i;
		}
	}
	
	while (q--) {
		ll ans = 0;
		cin >> (s1+1) >> (s2+1);
		information this_str = {0, 0, 0};
		this_str.len = strlen(s1+1);
		for (int i = 1; i <= this_str.len; i ++) {
			if (s1[i] == 'b') this_str.s1_b = i;
			if (s2[i] == 'b') this_str.s2_b = i;
		}
		for (int i = 1; i <= n; i ++) {
			if (info[i].s1_b - info[i].s2_b == this_str.s1_b - this_str.s2_b) {
				if (this_str.len - this_str.s1_b >= info[i].len - info[i].s1_b) {
					if (this_str.len - this_str.s2_b >= info[i].len - info[i].s2_b) {
						if (this_str.s1_b >= info[i].s1_b && this_str.s2_b >= info[i].s2_b) {
							ans ++;
							// cout << this_str.s1_b << " " << this_str.s2_b << " " << this_str.len << " " << info[i].s1_b << " " << info[i].s2_b << " " << info[i].len << endl;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
