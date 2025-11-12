#include<bits/stdc++.h>
#define inf LLONG_MAX
using namespace std;
typedef long long ll;
typedef __int128 llong;
const ll N=2e5+5;
operator == (string a,string b)
{
	if(a.size()!=b.size())
	{
		return a.size()==b.size();
	}
	for(int i=0;i<int(a.size());i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
string s[N][2],y,h;
ll n,q,ans;
unordered_map<string,ll> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		mp[s[i][0]]=i;
	}
	while(q--)
	{
		cin>>y>>h;
		ans=0;
		for(int i=0;i<y.size();i++)
		{
			string o="";
			for(int j=0;j+i<y.size();j++)
			{
				string u=y;
				o+=y[i+j];
//				cerr<<i<<' '<<j<<' '<<mp[o]<<' '<<o<<"\n";
				if(mp[o])
				{
					for(int l=0;l<=j;l++)
					{
						u[i+l]=s[mp[o]][1][l];
					}
//					cerr<<'*'<<u<<' '<<h<<"\n";
					if(u==h)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

