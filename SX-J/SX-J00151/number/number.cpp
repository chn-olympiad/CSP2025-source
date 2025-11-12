#include<bits/stdc++.h>
using namespace std;
string s;
int st[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			st[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
  		if(st[i]!=0)
		{
			for(int j=0;j<st[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}