#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[100005];
	int n = 0,x =0,m=0;
	for (int i = 0;i < s.length();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[i] = s[i] - '0';
			if (a[i] == 0)
			{
				x++;
			}
		}
		n++;
	}
	int y =0;
	sort(a,a+n);
	for (int i = n;i >= 0;i--)
	{
		if (a[i] == 0)
		{
			if (x != y)
			{
				cout << a[i];
				y++;
			}
		}
		if (a[i] != 0)
		{
			cout << a[i];
		}
	}
	return 0;
}
