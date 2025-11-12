#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353,S=13131;
map<pair<int,int>,int>v;
inline int ha(string s)
{
	int p=0;
	for(int i=0;i<(int)s.size();i++)
		p=(p*S+s[i])%mod;
	return p;
}
int n,q;
string s1,s2,t1,t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		v[make_pair(ha(s1),ha(s2))]++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		int m=t1.size(),ans=0;
		int l=0,r=m-1;
		while(l<m&&t1[l]==t2[l])l++;
		while(r>=0&&t1[r]==t2[r])r--;
		if(l==m)l--;
		if(r==-1)r++;
		for(int j=0;j<=l;j++)
		{
			int p1=0,p2=0;
			for(int k=j;k<r;k++)
			{
				p1=(p1*S+t1[k])%mod;
				p2=(p2*S+t2[k])%mod;
			}
			for(int k=r;k<m;k++)
			{
				p1=(p1*S+t1[k])%mod;
				p2=(p2*S+t2[k])%mod;
				if(v.count(make_pair(p1,p2)))
					ans+=v[make_pair(p1,p2)];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
aa bb
ab cd
bc de
xabcx xadex
aaaa bbbb
*/
