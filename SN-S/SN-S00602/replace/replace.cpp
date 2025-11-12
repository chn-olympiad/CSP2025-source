#include <bits/stdc++.h>
using namespace std;
int n,q,sz[200001][3],sizet,sizes;
string zd[200001][3];
string s,t;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>zd[i][1]>>zd[i][2];
		sz[i][1]=zd[i][1].size();
		sz[i][2]=zd[i][2].size();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s>>t;
		int ans=0;
        sizes=s.size();
        sizet=t.size();
        for(int j=0;j<sizes;j++)
        {
        	for(int k=j;k<sizes;k++)
        	{
        		for(int l=1;l<=n;l++)
        		{
        			if(sz[l][1]==k-j+1)
        			{
        				int cnt=k-j+1;
        				bool b=true;
        				for(int r=k;r<sizes;r++)
        				{
        					if(s[r]!=t[r])
        					{
        						b=false;
        						break;
							}
						}
        				for(int r=j;r<=k;r++)
        				{
        					if(s[r]!=zd[l][1][cnt])
        					{
        						break;
							}
							if(r==k)
							{
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
