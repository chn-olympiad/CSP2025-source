#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int f1=0,f2=0;
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				f1=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--)
		{
			if(t1[i]!=t2[i])
			{
				f2=i;
				break;
			}
		}
		int ans=0;
		for(int i=f1;i>=0;i--)
		{
			string sum=t1.substr(i,f2-i);
			string sum1=t2.substr(i,f2-i);
			for(int j=f2;j<t1.size();j++)
			{
				sum+=t1[j];
				sum1+=t2[j];
				if(mp[sum]==sum1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		continue;
	}
	return 0;
}