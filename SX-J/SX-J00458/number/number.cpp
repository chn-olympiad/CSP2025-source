#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+10;
string s;
ll arr[N], l;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	ll fry = s.size();
	for (ll i = 0; i < fry; i++)
		if (s[i] >= '0' && s[i] <= '9')
			arr[++l] = (ll)(s[i] - '0');
	sort(arr + 1, arr + l + 1);
	for (ll i = l; i >= 1; i--)
		cout << arr[i];
	return 0;
}
