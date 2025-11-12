#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out", "w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[int(s[i])-47]++;
		}
	}
	for(int i=10;i>=1;i--)
	{
		if(a[i]==0)
		{
			continue;
		}
		else
		{
			for(int j=1;j<=a[i];j++)
			{
				cout<<i-1;
			}
		}
	}
	return 0;
}
