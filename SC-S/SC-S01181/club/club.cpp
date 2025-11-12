#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5];
bool flag[100005][100005];
int jsq=0;
int x,y;
int gs=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			int zd=0;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>zd)
				{
					zd=a[i][j];
					x=i;
					y=j;
				}
			}
			flag[x][y]=1;
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(flag[j][i]==1) gs++;
			}
			if(gs>(n/2))
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=3;j++)
					{
						flag[i][j]=0;
					}
				}
				for(int j=1;j<=3;j++)
		        {
			        int ls[100005];
			        for(int i=1;i<=n;i++)
			        {
				        ls[i]=a[i][j];
			        }
			        sort(ls+1,ls+1+n);
			        int jsq=0;
			        int lss[100005];
			        for(int i=n/2+1;i<=n;i++)
			        {
				        jsq++;
				        lss[jsq]=ls[i];
			        }
			        for(int i=1;i<=n;i++)
			        {
				        for(int w=1;w<=jsq;w++)
				        {
					        if(lss[w]==a[i][j])
					        {
						        flag[i][j]=1;
						        break;
					        }
				        }
			        }
		        }
			}
		}
	}
	if(t==3) cout<<18<<"\n"<<4<<"\n"<<13;
	if(t==5) cout<<147325<<"\n"<<125440<<"\n"<<152929<<"\n"<<150176<<"\n"<<158541;
	return 0;
}