#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
string s[200010];
string c[200010];
int d[5000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>s[i]>>b;
		mp[s[i]]=b;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string a,b;
		cin>>a>>b;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a.find(s[i])!=-1)
			{
				c[++cnt]=s[i];
			}
		}
		cout<<(1+cnt)*cnt/2<<"\n";
	}
	return 0;
}