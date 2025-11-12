#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100000][4],pur1[100000],pur2[100000],num[4],an[100000],ans;
	cin>>t;
	for(int it=1;it<=t;it++)
	{
		a[100000][4],pur1[100000],pur2[100000],num[4],an[100000]={0};
		ans,n=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&a[i][1]>=a[i][3])
			{
				pur1[i]=a[i][3];
				num[2]++;
				if(a[i][2]>=a[i][3])
				{
					pur2[i]=a[i][2];
				}
			}
			else if(a[i][2]>=a[i][3]&a[i][2]>=a[i][1])
			{
				pur1[i]=a[i][3];
				num[1]++;
				if(a[i][1]>=a[i][3])
				{
					pur2[i]=a[i][1];
				}
			}
			else
			{
				pur1[i]=a[i][3];
				num[3]++;
				if(a[i][1]>=a[i][2])
				{
					pur2[i]=a[i][1];
				}
			}
		}
		num[4]=max(max(num[1],num[2]),num[3]);
		if(num[4]-(n/2)>0)
		{
			for(int i=1;i<=3;i++)
			{
				if(num[i]=num[4])
				{
					for(int j=1;j<=n;j++)
					{
						an[j]=a[j][i];
					}
					sort(an,an+1+n);
					for(int j=1;j<=n;j++)
					{
						if(a[j][i]<=an[n/2])
						{
							pur1[j]=pur2[j];
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=pur1[i];
		}
		cout<<ans<<endl;	
	}
	return 0;
} 
