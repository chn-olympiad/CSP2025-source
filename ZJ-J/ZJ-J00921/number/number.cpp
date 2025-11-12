#include<bits/stdc++.h>
//#define int long long
using namespace std;
string s;
int cnt[15];
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(auto c : s) if(isdigit(c)) cnt[c - '0'] ++;
	for(int i = 9; i >= 0; i --)
		while(cnt[i] --) cout << i;
	cout << "\n";
	return 0;
}