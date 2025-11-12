#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100006];
ll l;
bool vis[100006];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=int(s[i]-'0');
		}
		else a[i]=-1;
	}
	sort(a,a+s.size(),cmp);
	string da;
	for(int i=0; i<s.size(); i++)
	{
		if(a[i]!=-1)
		{
			da+=char(a[i]+'0');
		}
	}
	cout<<da;
	return 0;
}
