#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,q;
string a[200005],b[200005];
int ab[1000005],bb[1000005];
map<pair<int,int>,int> ma;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool af=0,bf=0,aaa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]=='b')
			{
				ab[i]=j;
				af++;
			}
			if(a[i][j]!='a'&&a[i][j]!='b')aaa=1;
			if(b[i][j]!='a'&&b[i][j]!='b')aaa=1;
			if(b[i][j]=='b')
			{
				bb[i]=j;
				bf++;
			}
		}
	}
	if(af==bf&&af==n&&aaa==0)
	{
		for(int i=1;i<=n;i++)
		{
			ma[{ab[i],bb[i]}]++;
		}
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		if(af==n&&bf==n&&aaa==0)
		{
			int xb=-1,yb=-1;
			for(int i=0;i<=x.size();i++)
			{
				if(x[i]=='b'&&y[i]!='b')
				{
					xb=i;
				}
				if(y[i]=='b'&&x[i]!='b')
				{
					yb=i;
				}
			}
			cout<<ma[{xb,yb}]<<endl;
		}
		int ans=0;
		bool f=0;
		string s="",t="",s1="",t1="";
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}	
		for(int j=0;j<x.size();j++)
		{
			if(x[j]!=y[j]&&f==1)
			{
				cout<<0<<endl;
				f++;
				break;
			}
			while(x[j]!=y[j])
			{
				f=1; 
				s+=x[j];
				t+=y[j];
				j++;
			}
		}
		if(f==1)
		{
			
			for(int i=1;i<=n;i++)
			{
				f=0;
				for(int j=0;j<a[i].size();j++)
				{
					if(a[i][j]!=b[i][j]&&f==1)
					{
						
						f++;
						break;
					}
					while(b[i][j]!=a[i][j])
					{
						f=1; 
						s1+=a[i][j];
						t1+=b[i][j];
						j++;
					}
				}
				if(s1==s&&t1==t&&f==1)
				ans++;
				s1="";
				t1="";
			}cout<<ans<<endl;
		}
		
	}
	return 0;
}

