#include<bits/stdc++.h>
using namespace std;
int a[10];
bool cmp(int x1,int x2)
{
	if(x1==x2)
	{
		return x1;
	}
	return x1>x2;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<=s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int m=s[i]-'0';
			a[m]++;
		}
	}
	for(int j=9;j>=0;j--)
	{
		for(int i=0;i<a[j];i++)
		{
			cout<<j;
		}
	}
	return 0;
}
