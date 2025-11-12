#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
string s;
int num[maxn], cnt;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "r", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num[i] = s[i] -'0';
			cnt++;
		}
	}
	int beg = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			beg = i;
			break;
		}
	}
	sort(num+beg, num+cnt+1);
	for (int i = cnt; i >= beg+1; i--)
	{
		cout << num[i];
	}
	return 0;
 } 
