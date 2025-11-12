#include <bits/stdc++.h>
using namespace std;
string s;
int a[20];
bool p=false;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]<='9' && s[i]>='0')
		{
			a[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		while ((i>0 || p) && a[i]>0)
		{
			p=true;
			cout<<i;
			a[i]--;
		}
	}
	if (!p)
	{
		cout<<0;
	}
}
