#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q,ans;
string s1[N],s2[N],s,e;
signed main()
{
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>s>>e;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s.size();j++)
			{
				int k=s1[i].size()+j-1;
				if(k>=s.size())	break;
				if((s.substr(j,s1[i].size())==s1[i])&&(s.substr(0,j)+s2[i]+s.substr(k+1)==e))
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
 	return 0;
}
