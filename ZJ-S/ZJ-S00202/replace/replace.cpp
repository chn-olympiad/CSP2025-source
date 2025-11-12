#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[400005][2],x,y;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}
		int ans=0,l=x.size();
		for(int k=1;k<=n;k++)
		{
			string x0=x,y0=y;
			int f=0,k1;
			for(int j=0;j<l;j++)
				if(x0[j]==s[k][1][0])
				{
					int f1=1;
					for(int q=0;q<s[k][1].size();q++)
						if(x0[j+q]!=s[k][1][q])
							f1=0;
					if(f1)
					{
						f=1;
						k1=j;
						break;
					}
				}
			if(f)
			{
				for(int j=0;j<s[k][1].size();j++)
					x0[k1+j]=s[k][2][j];
				if(x0==y0)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
