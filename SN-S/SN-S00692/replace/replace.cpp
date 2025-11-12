#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][3];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		string tl,to;
		cin>>tl>>to;
		if(i>n || tl!=s[i][1] || to!=s[i][2])
		{
			cout<<0<<"\n";
			continue;
		}
		int ans=0,len=tl.size(),t=-1;
		for(int j=0;j<len;j++)
		{
			if(tl[j]=='b')
			{
				t=j;
				break;
			}
		}
		if(t==-1)
		{
			cout<<0<<"\n";
			continue;
		}
		ans=2+t+(len-1-t);
		cout<<ans<<"\n";
	}
	return 0;
}
