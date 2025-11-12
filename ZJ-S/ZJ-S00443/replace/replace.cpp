#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,cnt1,cnt2;
string d1,d2,p1,p2,s1[200005],s2[200005],t1[200005],t2[200005];
map<pair<string,string>,int> mp1;
map<pair<string,string>,int> mp2;
map<pair<int,int>,int> mp3;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
	    cin>>s1[i]>>s2[i];
	    int l=0,r=0;
		for(int j=0;j<s1[i].size();++j)
		    if(s1[i][j]!=s2[i][j])
		    {
		    	l=j;
				break;	
			}
		for(int j=0;j<s2[i].size();++j)
		    if(s1[i][j]!=s2[i][j])
		    {
		    	r=j;
			}
		d1="";
		d2="";
		for(int j=l;j<=r;++j)
		{
			d1+=s1[i][j];
			d2+=s2[i][j];
		}
		if(!mp1[{d1,d2}]) mp1[{d1,d2}]=++cnt1;
		int x=mp1[{d1,d2}];
		p1="";
		p2="";
		for(int j=0;j<=l-1;++j)
		    p1+=s1[i][j];
		for(int j=r+1;j<s1[i].size();++j)
		    p2+=s1[i][j];
		if(!mp2[{p1,p2}]) mp2[{p1,p2}]=++cnt2;
		int y=mp2[{p1,p2}];
		mp3[{x,y}]++;
	}
	for(int i=1;i<=q;++i)
	{
		cin>>t1[i]>>t2[i];
		int l=0,r=0;
		for(int j=0;j<t1[i].size();++j)
		    if(t1[i][j]!=t2[i][j])
		    {
		    	l=j;
				break;	
			}
		for(int j=0;j<t1[i].size();++j)
		    if(t1[i][j]!=t2[i][j])
		    {
		    	r=j;
			}
		d1="";
		d2="";
		for(int j=l;j<=r;++j)
		{
			d1+=t1[i][j];
			d2+=t2[i][j];
		}
		int x=mp1[{d1,d2}];
		int ans=0;
		string p1="";
		for(int j=l;j>=0;--j)
		{
			if(j!=l) p1=t1[i][j]+p1;
			p2="";
			for(int k=r;k<t1[i].size();++k)
			{
				if(k!=r) p2=p2+t1[i][k];
				if(!mp2[{p1,p2}]) mp2[{p1,p2}]=++cnt2;
				int y=mp2[{p1,p2}];
				ans+=mp3[{x,y}];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
