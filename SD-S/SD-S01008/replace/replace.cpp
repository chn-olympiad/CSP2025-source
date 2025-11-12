#include <bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
long long ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		mp[a]=b;
	}
	string str1,str2;
	for(int i=1;i<=q;i++)
	{
		cin>>str1>>str2;
		ans=0;
		if(str1==str2)
		{
			ans++;
		}
		for(int j=0;j<str1.size();j++)
		{
			for(int k=j;k<str1.size();k++)
			{
				string s=str1.substr(j,k-j+1);
				string s1="A";
				if(mp[s]!="")
				{
					s1=str1.substr(0,j)+mp[s]+str1.substr(k+1,str1.size()-k-1);
				}
				if(str2==s1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
