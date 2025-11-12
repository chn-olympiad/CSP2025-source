#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a, b;
string xx1[200010], yy1[200010];
string xx2[200010], yy2[200010];
string qw[200010], er[200010];
string qw2[200010], er2[200010];
string ans100[200010], ans200[200010];
string ans300[200010], ans400[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> a >> b;
	for (ll i = 1; i <= a; i++) {
		cin >> xx1[i] >> yy1[i];
		bool f = 1;
		ll len2 = xx1[i].size();
		ll lt = -1, rt = -1;
		for (ll j = 0; j < len2; j++) {
			if (f && (xx1[i][j] != yy1[i][j])) {
				f = 0;
				lt = j;
			}
			if (xx1[i][j] != yy1[i][j]) {
				rt = j;
			}
			if (lt != -1) {
				qw[i] += xx1[i][j];
				er[i] += yy1[i][j];
			}
		}
		if (rt == -1) {
			continue;
		}
		for (ll j = len2 - 1; j > rt; j--) {
			qw[i][j - lt] = ' ';
			er[i][j - lt] = ' ';
		}
	}
	for (ll i = 1; i <= b; i++) {
		cin >> xx2[i] >> yy2[i];
		ll len2 = xx2[i].size();
		bool f = 1;
		ll lt = -1, rt = -1;
		for (ll j = 0; j < len2; j++) {
			if (f && xx2[i][j] != yy2[i][j]) {
				f = 0;
				lt = j;
			}
			if (xx2[i][j] != yy2[i][j]) {
				rt = j;
			}
			if (lt != -1) {
				qw2[i] += xx2[i][j];
				er2[i] += yy2[i][j];
			}
		}
		if (rt == -1) {
			continue;
		}
		for (ll j = len2 - 1; j > rt; j--) {
			qw2[i][j - lt] = ' ';
			er2[i][j - lt] = ' ';
		}
	}
	ll len2;
	for (ll i = 1; i <= b; i++) {
		len2 = qw2[i].size();
		for (ll j = 0; j < len2; j++) {
			if (qw2[i][j] == ' ') {
				break;
			}
			ans100[i] += qw2[i][j];
		}
	}
	for (ll i = 1; i <= a; i++) {
		len2 = qw[i].size();
		for (ll j = 0; j < len2; j++) {
			if (qw[i][j] == ' ') {
				break;
			}
			ans200[i] += qw[i][j];
		}
	}
	for (ll i = 1; i <= b; i++) {
		len2 = er2[i].size();
		for (ll j = 0; j < len2; j++) {
			if (er2[i][j] == ' ') {
				break;
			}
			ans300[i] += er2[i][j];
		}
	}
	for (ll i = 1; i <= a; i++) {
		len2 = er[i].size();
		for (ll j = 0; j < len2; j++) {
			if (er[i][j] == ' ') {
				break;
			}
			ans400[i] += er[i][j];
		}
	}
	for (ll i = 1; i <= b; i++) {
		ll sum = 0;
		for (ll j = 1; j <= a; j++) {
			if (ans100[i] == ans200[j] && ans300[i] == ans400[j]) {
				sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
