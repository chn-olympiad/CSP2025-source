#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,map<string,int> > mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		string h1="",h2="";
		int l,r;
		for(l=0;l<a.size() && l<b.size() && a[l]==b[l];l++);
		if(a.size()!=b.size())
			r=max(a.size(),b.size());
		else
			for(r=a.size()-1;r>=0 && a[r]==b[r];r--);
		for(int i=l;i<a.size() && i<=r;i++)
			h1+=a[i];
		for(int i=l;i<b.size() && i<=r;i++)
			h2+=b[i];
		mp[h1][h2]++;
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		string h1="",h2="";
		int l,r;
		for(l=0;l<s1.size() && l<s2.size() && s1[l]==s2[l];l++);
		if(s1.size()!=s2.size())
			r=max(s1.size(),s2.size());
		else
			for(r=s1.size()-1;r>=0 && s1[r]==s2[r];r--);
		for(int i=l;i<s1.size() && i<=r;i++)
			h1+=s1[i];
		for(int i=l;i<s2.size() && i<=r;i++)
			h2+=s2[i];
		cout<<mp[h1][h2]<<"\n";
	}
	return 0;
}
