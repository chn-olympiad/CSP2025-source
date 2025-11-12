#include<bits/stdc++.h>
using namespace std;
int n,t,h;
int ji[10005][3],pi[1005][3],da[105],zh[105];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(pi,0,sizeof(pi));
		memset(da,0,sizeof(da));
		h=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>ji[i][j];
				pi[i][ji[i][j]]=j;
				da[i]=max(da[i],ji[i][j]);	
				if(da[i]==ji[i][j]) ji[i][j]=0;
				zh[i]=max(zh[i],ji[i][j]);
			}
			//cout<<da[i]<<zh[i]<<endl;
		}
		if(pi[0][da[0]]==pi[1][da[1]]) 
			{
				int u=da[0]+zh[1];
				int p=da[1]+zh[0];
				//cout<<u<<p;
				h=max(u,p);
			}
			else
			{
				h=da[0]+da[1];
			}
		cout<<h;
	}
	return 0;
	
 } 
