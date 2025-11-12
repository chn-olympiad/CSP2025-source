#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int p=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++p]=s[i]-'0';
		}
	}
	sort(a+1,a+p+1,cmp);
	bool lead0=1;
	for(int i=1;i<=p;i++)
	{
		if(a[i]==0&&lead0)
		{}
		else
		{
			cout<<a[i];
			lead0=0;
		}
	}
	if(lead0)
	{
		cout<<0;
	}
	return 0;
}