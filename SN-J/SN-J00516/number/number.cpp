#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ll ans[100010];
	string s;
	cin >> s;
	for (ll i = 0; i < s.size(); i++){
		if (isdigit(s[i]) && s[i] != 0) ans[i] = s[i] - 48;
		if (s[i] == '0') ans[i] = -1;
	}
	sort (ans, ans + s.size());
	for (ll i = s.size(); i >= 0; i--) {
		if (ans[i] != 0 && ans[i] != -1) cout << ans[i];
		if (ans[i] == -1) cout << '0';
	}
}
