#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
map<string,string> mp;
int n,q;
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
		int cnt=0;
		string s,ts;
		cin>>s>>ts;
		for(auto ite=mp.begin();ite!=mp.end();ite++)
		{
		    string s1=ite->first,s2=ite->second;
		    if(s.find(s1)<s.end()-s.begin())
		    {
		    	int ex=s.find(s1),sz=ex+s1.size();
		    	string x,z;
		    	for(int i=0;i<ex;i++)
		    	{
		    		x+=s[i];
				}
				for(int i=sz;i<s.size();i++)
				{
					z+=s[i];
				}
				string ans=x+s2+z;
				if(ans==ts)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}