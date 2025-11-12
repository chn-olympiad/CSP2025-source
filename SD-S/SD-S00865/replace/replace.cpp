#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200010];
map<string,string> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string t;
		cin>>a[i]>>t;
		mp[a[i]]=t;
	}
	while(m--)
	{
		string t,tt;
		cin>>t>>tt;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int tmp=t.find(a[i]);
			//cout<<mp[a[i]]<<'\n';
			if(tmp<=t.size()&&tmp>=0)
			{
				string tp=t.substr(0,tmp)+mp[a[i]]+t.substr(tmp+mp[a[i]].size(),t.size()-tmp-mp[a[i]].size());
				if(tp==tt)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}

