#include <bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
string s;
ll cnt[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;s = ' '+s;
	for (ll i = 1;i < s.size();i++) if ('0' <= s[i] && s[i] <= '9')
		cnt[s[i]-'0']++;
	for (ll i = 9;i >= 0;i--)
		for (ll j = 1;j <= cnt[i];j++) cout << i;
	return 0;
}
