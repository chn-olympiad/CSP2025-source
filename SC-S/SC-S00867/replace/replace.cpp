#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
string x[N],y[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		vector<vector<int>>z(30);
		for(int i=0;i<a.size();i++)
			z[a[i]-'a'].push_back(i);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j:z[x[i][0]-'a'])
			{
				if(j+x[i].size()<=a.size())
				{
					string ta=a.substr(j,x[i].size());
					if(ta==x[i])
					{
						string tb=a.substr(0,j)+y[i];
						if(j+y[i].size()<a.size())tb+=a.substr(j+y[i].size());
						if(tb==b)ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}