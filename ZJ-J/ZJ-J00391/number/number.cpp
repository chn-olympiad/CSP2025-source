#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define io ios::sync_with_stdio(0), cin.tie(), cout.tie()
#define open(_io) freopen(_io".in", "r", stdin), freopen(_io".out", "w", stdout)
const ll _s = 1e6 + 1;
string s;
ll a[_s];
int main(){
	io;
	open("number");
	cin >> s;
	for (ll i = 0; i < s.size(); i++) if (s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	for (ll i = 9; i >= 0; i--) if (a[i]) cout << string(a[i], i + '0');
	return 0;
}

