//崔雅欣  SN-S00182  西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010][6],m[6],ma,dy,dr,ds,lin;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n;
		if(n==2)
		{
			int a1=0,a3=0,a2=0,b1=0,b2=0,b3=0,c[]={0,0,0,0,0,0,0,0};
			cin>>a1>>a2>>a3>>b1>>b2>>b3;
			c[1]=a1+b2;
			c[2]=a1+b3;
			c[3]=a2+b1;
			c[4]=a2+b3;
			c[5]=a3+b1;
			c[6]=a3+b2;
			for(int d=1;d<=6;d++)
			{
				if(m[t]<c[d]) m[t]=c[d];
			}
		}
		else
		{
			for(int i=1;i<=n;i++)//输入 
			{
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				if(a[i][2]==0&&a[i][3]==0) lin++;
			}
			if(lin==n)
			{
				int ma[200010];
				for(int j=1;j<=n;j++)//最大 
				{
					for(int r=1;r<=3;r++)
					{
						if(a[j][r]>ma[j]) 
						{
							ma[j]=a[j][r];
						}
					}
				}	
				for(int j=1;j<=n;j++)//最大 
				{
					for(int r=j;r<=n;r++)
					{
						if(ma[r]<ma[r+1]) 
						{
							swap(ma[r],ma[r+1]);
						}
					}
				}
				for(int p=1;p<=n/2;p++)//和 
				{
					m[t]+=ma[p];
				}
			}
			else
			{
				for(int j=1;j<=n;j++)//最大 
				{
				for(int r=1;r<=3;r++)
				{
					if(a[j][r]>a[j][4]) 
					{
						a[j][4]=a[j][r];
						a[j][5]=r;
					}
				}
				//if(a[j][5]==0) dy++;
				//else if(a[j][5]==1) dr++;
				//else ds++;
				//	while(dy>n/2&&dr>n/2&&ds>n/2)
				//{
				//	if(dy>n/2)
				//	{
				//		dy--;
				//		dr++;		
					//}
				//	if(dr>n/2)
					//	if(ds>n/2)
					//}
				}	
				//判断 
				for(int p=1;p<=n;p++)//和 
				{
					m[t]+=a[p][4];
				}
			}
			
		}
		
	}
	for(int q=1;q<=t;q++)
	{
		cout<<m[q]<<endl; 
	}
	return 0;
 } 
