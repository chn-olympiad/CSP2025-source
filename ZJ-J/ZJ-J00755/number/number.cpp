#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, a[N];
string s;
bool flag;

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	for(int i = 0; i < s.size(); i ++) a[s[i] - '0'] ++;
	for(int i = 9; i >= 0; i --)
	{
		for(int j = 1; j <= a[i]; j ++)
		{
			flag = 1;
			cout << i;
		}
	}
	if(!flag) cout << 0;
	return 0;
}
