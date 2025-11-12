#include<bits/stdc++.h>
using namespace std;
int a[500001];
string s[500001];
string delta[500001];
string change(int n)
{
	string ans="";
	for (int i=n;i>0;i/=2)
	{
		ans=char(i%2+48)+ans;
	}
	return ans;
}
string solve(string s1,string s2)
{
	string ans="";
	if (s1.size()>s2.size())
	{
		for (int i=1;i<=s1.size()-s2.size();i++)
		{
			s2='0'+s2;
		}
	}
	else if (s1.size()<s2.size())
	{
		for (int i=1;i<=s2.size()-s1.size();i++)
		{
			s1='0'+s1;
		}
	}
	for (int i=0;i<s1.size();i++)
	{
		ans=ans+char((s1[i]!=s2[i])+48);
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	bool flaga1=0,flag01=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=change(a[i]);
		delta[i]=solve(s[i],s[i-1]);
		if (a[i]!=1)	flaga1=1;
		if (a[i]!=1 && a[i]!=0)	flag01=1;
	}
	if (!flaga1 && k==0)
	{
		cout<<n/2;
		return 0;
	}
	if (!flag01)
	{
		int cnt=0;
		if (k==1)
		{
			for (int i=1;i<=n;i++)
			{
				if (a[i]==1)
				{
					cnt++;
				}
			}
		}
		else if (k==0)
		{
			for (int i=1;i<=n;i++)
			{
				if (a[i]==0)
				{
					cnt++;
				}
			}	-
		}
		cout<<cnt;
		return 0;
	}
	
}
