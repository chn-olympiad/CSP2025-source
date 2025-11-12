#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,vector<string>> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		mp[x].push_back(y);
	}
	for(int i=1;i<=q;i++)
	{
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int j=1,l=x.size();j<=l;j++)
		{
			for(int k=0;k+j-1<l;k++)
			{
				int r=k+j-1;
				if(x.substr(0,k) == y.substr(0,k)&&x.substr(r+1,l-1-r) == y.substr(r+1,l-1-r))
				{
					if(mp.count(x.substr(k,l)))
					{
						for(auto it:mp[x.substr(k,l)])
						{
							if(it == y.substr(k,l))
							{
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
