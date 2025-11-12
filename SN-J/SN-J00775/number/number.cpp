// xianshitieyizhongxue wangzhengqinghe 13891989834 chusan
#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000000
#define infll 1000000000000000000ll
using namespace std;
int aqx;
string s;
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}
void solve()
{
	cin >> s;
	string t;
	for (char i:s) if ((i >= '0') && (i <= '9')) t += i;
	sort(t.begin(), t.end()); reverse(t.begin(), t.end());
	cout << t << "\n";
	return;
}
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) solve();
	return 0;
}
