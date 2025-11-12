#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string,string> mp; 
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		mp[x]=y;
	}
	while(q--)
	{
		string a,b;
		int ans=0;
		cin>>a>>b;
		int l=a.size();
		for(int i=0;i<l;i++)
		{
			for(auto it:mp)
			{
				int m=it.first.size();
				if(l-i<m) continue;
				string s=a.substr(i,m);
				if(s==it.first)
				{
					string c="";
					c=a.substr(0,i);
					c+=it.second;
					c+=a.substr(i+m);
					if(c==b) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

