#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,q;
string s[3][N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
	}
	while(q--)
	{
		long long ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<"0\n";
			continue;
		}
		for(long long i=1;i<=n;i++)
		{
			long long x=a.find(s[1][i]);
			long long y=b.find(s[2][i]);
			if(x!=-1&&y!=-1)
			{
				if(x!=y)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
