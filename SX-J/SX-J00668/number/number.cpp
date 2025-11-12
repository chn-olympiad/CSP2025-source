#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+5;
string s;
ll a[N];
ll ans;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' ||
		        s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			a[ans++] = s[i] - '0';
		}
	}
	sort(a, a + ans);
	for (ll i = ans - 1; i >= 0; i--)
		cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
