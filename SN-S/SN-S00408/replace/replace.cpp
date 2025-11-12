//YangRuibin SN-S00408 TYZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,M=5e6+5;
int n,q;
string s1[N],s2[N],t1,t2;
vector<int>nxt1[N],nxt2[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i],s1[i]=" "+s1[i],s2[i]=" "+s2[i];
		nxt1[i].resize(s1[i].size());
		for(int j=1,p=0;j<s1[i].size();j++)
		{
			while(p&&s1[p+1]!=s1[j])p=nxt1[i][p];
			nxt1[i][j]=(s1[p+1]==s1[j]?p+1:p);
		}
		nxt2[i].resize(s2[i].size());
		for(int j=1,p=0;j<s2[i].size();j++)
		{
			while(p&&s2[p+1]!=s2[j])p=nxt2[i][p];
			nxt2[i][j]=(s2[p+1]==s2[j]?p+1:p);
		}
	}
	for(int iii=1;iii<=q;iii++)
	{
		cin>>t1>>t2;
		int l=t2.size(),r=0;
		t1=" "+t1,t2=" "+t2;
		for(int i=1;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				l=i-1;break;
			}
		}
		for(int i=t1.size()-1;i;i--)
		{
			if(t1[i]!=t2[i])
			{
				r=i+1;break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			vector<int>g1,g2;
			for(int j=1,p=0;j<t1.size();j++)
			{
				while(p&&(p==s1[i].size()||s1[i][p+1]!=t1[j]))p=nxt1[i][p];
				if(p<s1[i].size()&&s1[i][p+1]==t1[j])++p;
				if(p==s1[i].size()-1)g1.push_back(j);
			}
			for(int j=1,p=0;j<t2.size();j++)
			{
				while(p&&(p==s2[i].size()||s2[i][p+1]!=t2[j]))p=nxt2[i][p];
				if(p<s2[i].size()&&s2[i][p+1]==t2[j])++p;
				if(p==s2[i].size()-1)g2.push_back(j);
			}
//			cerr<<i<<endl;
			int flag=0;
			for(int i=0,j=0;i<g1.size();i++)
			{
				while(j<g2.size()&&g2[j]<g1[i])++j;
				if(j<g2.size()&&g1[i]==g2[j]&&g1[i]<=l+1&&g1[i]+s1[i].size()-1>=r-1)
				{
					flag=1;break;
				}
			}
			if(flag)++ans;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
