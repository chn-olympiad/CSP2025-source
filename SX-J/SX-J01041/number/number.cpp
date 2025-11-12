#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+10;
string a;
char m[N];

char db[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool cmp(ll x, ll y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (ll i = 0; i <= a.size() - 1; i++) {
		for (ll j = 0; j <= 10; j++) {
			if (a[i] == db[j])
				m[i] = db[j];
		}
	}
	sort(m, m + 1 + a.size(), cmp);
	for (ll i = 0; i <= a.size(); i++)
		cout << m[i];
	return 0;
}
