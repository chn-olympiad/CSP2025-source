#include<bits/stdc++.h>
using namespace std;
int n,q,cnt1[200100],cnt2[200100];
string s1[200100],s2[200100],c1[200100],c2[200100];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>s1[i]>>s2[i];
		int l=s1[i].size();
		int st=0,ed=0;
		for(int j=0;j<l;j++)
		{
			if(s1[i][j]!=s2[i][j])
			{
				st=j;
				break;
			}
		}
		for(int j=l-1;j>=0;j--)
		{
			if(s1[i][j]!=s2[i][j])
			{
				ed=j;
				break;
			}
		}
		string sa="",sb="";
		for(int j=st;j<=ed;j++) sa=sa+s1[i][j],sb=sb+s2[i][j];
		c1[i]=sa,c2[i]=sb;
		cnt1[i]=st,cnt2[i]=ed;
	}
	while(q--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2)
		{
			cout<<0<<"\n";
			continue;
		}
		int st=0,ed=0;
		for(int i=0;i<l1;i++)
		{
			if(t1[i]!=t2[i])
			{
				st=i;
				break;
			}
		}
		for(int i=l1-1;i>=0;i--)
		{
			if(t1[i]!=t2[i])
			{
				ed=i;
				break;
			}
		}
		string ta="",tb="";
		for(int i=st;i<=ed;i++) ta=ta+t1[i],tb=tb+t2[i];
		for(int i=1;i<=n;i++)
		{
			if(c1[i]!=ta||c2[i]!=tb) continue;
			int ls=st-cnt1[i];
			int nx=ls+s1[i].size()-1;
			if(ls<0||nx>l1) continue;
			int flag=1;
			for(int j=ls;j<=nx;j++)
			{
				if(s1[i][j-ls]!=t1[j]||s2[i][j-ls]!=t2[j])
				{
					flag=0;
					break;
				}
			}
			if(flag) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}