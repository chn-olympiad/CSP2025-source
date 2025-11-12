#include<bits/stdc++.h>

using namespace std;

string x[100001],y[100001];
map<char,vector<tuple<string,string,int> > > mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		mp[x[i][0]].push_back(make_tuple(x[i],y[i],x[i].length()));
	}
	while(q--)
	{
		cin>>a>>b;
		int la=a.length(), lb=b.length();
		if(la!=lb) 
		{
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<la;i++)
		{
			for(int j=0;j<mp[a[i]].size();j++)
			{
				int len=get<2>(mp[a[i]][j]);
				if(a.substr(i,len) == get<0>(mp[a[i]][j]) )
				{
					if(a.substr(0,i)+get<1>(mp[a[i]][j])+a.substr(i+len,la-i-len)==b)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
