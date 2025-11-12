#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,q,s[200005],wsx[200005];
string x[200005],y[200005];
unordered_map<int,unordered_map<int,int>> mp,mm,mc;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		for(int j=0;j<x[i].size();j++)
		{
			if(x[i][j]!=y[i][j])
			{
				mp[i][++s[i]]=j;
			}
		}
		mc[s[i]][++wsx[s[i]]]=i;
	}
	for(int i=1;i<=q;i++)
	{
		string xx,yy;
		cin>>xx>>yy;
		int sss=0,ss=0;
		if(xx.size()!=yy.size())
		{
			cout<<0<<'\n';
			continue;
		}
		for(int j=0;j<xx.size();j++)
		{
			if(xx[j]!=yy[j])
			{
				mm[i][++sss]=j;
			}
		}
		for(int j=1;j<=wsx[sss];j++)
		{
			int l=mc[sss][j];
			if(mm[i][1]>=mp[l][1]&&mm[i][sss]-mm[i][1]==mp[l][sss]-mp[l][1]&&xx.size()-mm[i][sss]>=x[l].size()-mp[l][sss])
			{
				bool bb=1;
				for(int k=0;k<x[l].size();k++)
				{
					if(x[l][k]!=xx[k-mp[l][1]+mm[i][1]]||y[l][k]!=yy[k-mp[l][1]+mm[i][1]])
					{
						bb=0;
						break;
					}
				}
				ss+=bb;
			}
		}
		cout<<ss<<'\n';
	}
}
