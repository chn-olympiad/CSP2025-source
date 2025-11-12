#include<bits/stdc++.h>
using namespace std;
string s;
int d[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			int x=int(s[i]-'0');
			d[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(d[i]!=0)
		{
			d[i]--;
			cout<<i;
		}
	}
	return 0;
}
