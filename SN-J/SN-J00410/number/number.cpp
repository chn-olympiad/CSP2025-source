#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[10];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	s=" "+s;
	for (int i=1;i<=s.length();i++)
	{
		if (s[i]>=48&&s[i]<=57)
		{
			a[(int(s[i])-48)]++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		if (a[i]==0) continue;
		else
		{
			for (int j=1;j<=a[i];j++) 
			{
				cout << i;
			}
		}
	}
}
