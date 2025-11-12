#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct node
{
	string qian,hou;
};
int n,q,ans;
node huan[200005];
bool check(string s,string cs,int wei)
{
	for(int i=wei;i<cs.size()+wei;i++)
	{
		if(s[i]!=cs[i-wei])
		{
			return false;
		}
	}
	return true;
}
bool check1(string s,string cs,int wei,string ss)
{
	for(int i=0;i<wei;i++)
	{
		if(s[i]!=ss[i])
		{
			return false;
		}
	}
	for(int i=wei;i<wei+cs.size();i++)
	{
		if(cs[i-wei]!=ss[i])
		{
			return false;
		}
	}
	for(int i=wei+cs.size();i<s.size();i++)
	{
		if(s[i]!=ss[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>huan[i].qian>>huan[i].hou;
	}
	while(q--)
	{
		ans=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(huan[i].qian.size()>s1.size())
			{
				continue;
			}
			for(int j=0;j<=s1.size()-huan[i].qian.size();j++)
			{
				if(check(s1,huan[i].qian,j)==true)
				{
					if(check1(s1,huan[i].hou,j,s2)==true)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
*/
