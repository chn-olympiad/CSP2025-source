#include<bits/stdc++.h>
using namespace std;
int ans,n,m;
string s[200010][2],x,y;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(m--)
	{
		ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+s[i][0].size()-1<x.size();j++)
			{
				if(x.substr(j,s[i][0].size())==s[i][0])
				{
					string tmp=x;
					tmp.replace(j,s[i][0].size(),s[i][1]);
					if(tmp==y)
						ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
