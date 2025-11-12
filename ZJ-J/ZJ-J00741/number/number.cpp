#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using namespace std;
string s;
vector<int> v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	for(auto x : s)
		if ('0' <= x && x <= '9')
			v.push_back(x - '0');
	sort(v.begin(), v.end(), greater<char>());
	for(auto x : v) cout << x;
	return 0;
}

