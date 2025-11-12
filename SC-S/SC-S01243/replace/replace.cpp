#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
int n,q;
map<pair<string,string>,int>mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size(),st=0,ed=0;
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j])
			{
				st=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--)
		{
			if(s1[j]!=s2[j])
			{
				ed=j;
				break;
			}
		}
		string ss,sss;
		for(int j=st;j<=ed;j++)
		{
			ss+=s1[j];
			sss+=s2[j];
		}
		mp[make_pair(ss,sss)]++;
	}
	while(q--)
	{
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int len=s1.size(),st=0,ed=0;
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j])
			{
				st=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--)
		{
			if(s1[j]!=s2[j])
			{
				ed=j;
				break;
			}
		}
		string ss,sss;
		for(int j=st;j<=ed;j++)
		{
			ss+=s1[j];
			sss+=s2[j];
		}
		cout<<mp[make_pair(ss,sss)]<<'\n';
	}
	return 0;
}