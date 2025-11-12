#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10];
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
