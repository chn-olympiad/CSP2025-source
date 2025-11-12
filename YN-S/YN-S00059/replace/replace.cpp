#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, q, ans;
string s1[N], s2[N], s3[N], s4[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> s3[i] >> s4[i];
		for (int j = 1; j <= n; j++) {
			if (s3[i].find(s1[j]) && s4[i].find(s2[j])) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}