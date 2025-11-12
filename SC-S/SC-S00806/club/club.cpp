#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c,la,n,max=0,pa[4][50000],a[100000][4],num[4]={0},ava[100000]={0};

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>c;
	for(int i=1;i<=c;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=0;i<n;i++)
		{
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				num[1]++;
				if(num[1]>n/2)
				{
					if(a[i][1]<pa[1][num[1]-1])
						num[1]--;
					else 
					{
						pa[1][num[1]]=a[i][1];
						ava[i]=1;
						la=i;
						ava[la]=0;
					}
				}
				else 
				{
					pa[1][num[1]]=a[i][1];
					ava[i]=1;
					la=i;
				}
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
			{
				num[2]++;
				if(num[2]>n/2)
				{
					if(a[i][2]<pa[2][num[2]-1])
						num[2]--;
					else 
					{
						pa[2][num[2]]=a[i][2];
						ava[i]=1;
						la=i;
						ava[la]=0;
					}
				}
				else 
				{
					pa[2][num[2]]=a[i][2];
					ava[i]=1;
					la=i;
				}
			}
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])
			{
				num[3]++;
				if(num[3]>n/2)
				{
					if(a[i][3]<pa[3][num[3]-1])
						num[3]--;
					else 
					{
						pa[3][num[3]]=a[i][3];
						ava[i]=1;
						la=i;
						ava[la]=0;
					}
				}
				else 
				{
					pa[3][num[3]]=a[i][3];
					ava[i]=1;
					la=i;
				}
			}
			for(int i=1;i<=3;i++)
			{
				if(num[i]<n/2)
				{	
					for(int i=1;i<=n/2-num[i];i++)
					{
						for(int j=0;j<n;j++)
						{
							if(ava[j]==0&&a[j][i]>max)
							{
								max=a[j][i];
								la=j;
							}
						}
						num[i]++;
						pa[i][num[i]]=max;
						ava[la]=1;
					}
				}
			}
		}
		int max2=0;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=num[i];j++)
			{
				max2+=pa[i][j];
			}
		}
		cout<<max2;
	}
}