#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e6+10,M=2e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
const int P=998244353;
int n,q;
map<string,string> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fst
	cin>>n>>q;
	if(n>100)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--)
	{
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++)
		{
			for(int j=i;j<a.size();j++)
			{
				string s="";
				for(int k=i;k<=j;k++)
				{
					s+=a[k];
				}
				if(mp[s]!="")
				{
					string t=a;
					for(int k=i,l=0;k<=j;k++,l++)
					{
						t[k]=mp[s][l];
					}
					if(t==b)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

