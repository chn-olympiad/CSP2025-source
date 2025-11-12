#include<bits/stdc++.h>
//#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e5+10,P=998244353,Mod=1e9+7;
int n,q;
string s[5][N];
signed main()
{
	FAST
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[1][i]>>s[2][i];
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			if(s[1][i].size()>t1.size())continue;
			for(int k=0;k<=t1.size()-s[1][i].size();k++)
			{
				if(t1.substr(k,s[1][i].size())==s[1][i])
				{
					string tmp=t1.substr(0,k)+s[2][i]+t1.substr(k+s[1][i].size(),t1.size()-k-s[1][i].size());
					if(tmp==t2)ans++; 
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
