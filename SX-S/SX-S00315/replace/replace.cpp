#include<bits/stdc++.h>
using namespace std;
int n,q,l,r;
string s[200005][3],ss,sss;
bool f(string s1,string s2)
{
	int b=0,l,l2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==ss[0])
		{
			b=1,l=i;
			for(int j=0;j<ss.size();j++)
			{
				b=2;
				if(s1[i]!=ss[i])	break;
			}
		}
	}
	if(b!=1)	return 0;
	b=0;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]==sss[0])
		{
			b=1,l2=i;
			for(int j=0;j<ss.size();j++)
			{
				b=2;
				if(s2[i]!=sss[i])	break;
			}
		}
	}
	if(b!=1||l!=l2)	return 0;
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		int ans=0;
		string t,tt;
		cin>>t>>tt;
		if(t.size()!=tt.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t.size();i++)
			if(t[i]!=tt[i])
			{
				l=i;
				break;
			}
		for(int i=t.size()-1;i>=0;i--)
			if(t[i]!=tt[i])
			{
				r=i;
				break;
			}
		for(int i=l;i<=r;i++)
		{
			ss+=t[i];
			sss+=tt[i];
		}	
		for(int i=1;i<=n;i++)
		{
			if(f(s[i][1],s[i][2]))	ans++;
		}	
		cout<<ans<<endl;
	}
	return 0;
}
