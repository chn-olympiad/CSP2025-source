#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,x = "",y = "";
	cin>>s;
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			x += s[i];
		}
	}
	int r = x.length();
	char by = '9';
	for(int j = 1;j <= 10;j++)
	{
		for(int i = 0;i < r;i++)
		{
			if(x[i] == char(by))
			{
				y += x[i];
			}
		}
		by -= 1;
	}
	cout<<y;
	return 0;
}
