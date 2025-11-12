#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
string u,v;
map <pair<string,string>,int> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		u="",v="";
		bool flag=0;
		int l=0,r=s1.size()-1;
		for(l;l<s1.size() && s1[l]==s2[l];l++);
		for(r;r>=0 && s1[r]==s2[r];r--);
		for(int j=l;j<=r;j++)
		{
			u+=s1[j];
			v+=s2[j];
		}
		mp[{u,v}]++;
	}
	string t1,t2;
	while(q--)
	{
		u="",v="";
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int l=0,r=t1.size()-1;
		for(l;l<t1.size() && t1[l]==t2[l];l++);
		for(r;r>=0 && t1[r]==t2[r];r--);
		for(int j=l;j<=r;j++)
		{
			u+=t1[j];
			v+=t2[j];
		}
		cout<<mp[{u,v}]<<endl;
	}
	return 0;
}