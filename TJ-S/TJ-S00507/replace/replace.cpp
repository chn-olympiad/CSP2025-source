#include <bits/stdc++.h>
using namespace std;
string a,b;
map<string,string>mp;
int n,q; 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>b;
		mp[a]=b;
	}
	while (q--)
	{
		cin>>a>>b;
		if (a.length()!=b.length())
		{
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for (int i=0;i<a.length();i++)
		{
			for (int j=0;j<=i;j++)
			{
				string f=a.substr(j,i-j+1);
				string o=b.substr(j,i-j+1);
				if (mp[f]!=o)
				{
					continue;
				}
				string h=b;
				for (int k=j;k<j+f.length();k++)
				{
					h[k]=f[k-j];
				}
				if (h==a)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
