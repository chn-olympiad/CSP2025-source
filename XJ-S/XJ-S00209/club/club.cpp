#include<bits/stdc++.h>
using namespace std;
int ans=0,a[100005][5],n,f[100005][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,k,maxx=-1;
	cin>>k;
	while(k--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
	 	}
	 	int t1,t2,t3;
	 	t1=1;t2=1;t3=1;
	 	for(i=1;i<=n;i++)
	 	{
	 		for(j=1;j<=3;j++)
	 		{
	 			f[i][j]=0;
			 }
		 }
	 	for(i=1;i<=n;i++)
	 	{
	 		for(j=1;j<=3;j++)
	 		{
	 			
 				if(j==1)
				{
					if(t1==n/2)
	 				{
	 					f[i][j]=max(f[i-1][2]+a[i][j],f[i-1][3]+a[i][j]);
	 				} 
	 				if(t1<n/2)
					{
						f[i][j]=max(f[i-1][2]+a[i][j],f[i-1][3]+a[i][j]);
			 			//f[i][j]=max(f[i][j],f[i-1][2]+a[i][j]);
						if(f[i-1][1]+a[i][j]>f[i][j])
		 				{
		 					f[i][j]=f[i-1][1]+a[i][j];
		 					t1++;
						}
					} 
				}
 				if(j==2)
				{
				 	if(t2==n/2)
				 	{
				 		f[i][j]=max(f[i-1][1]+a[i][j],f[i-1][3]+a[i][j]);
					
					}
					if(t2<n/2)
					{
						f[i][j]=max(f[i-1][3]+a[i][j],f[i-1][1]+a[i][j]);
		 				//f[i][j]=max(f[i][j],f[i-1][2]+a[i][j]);
		 				if(f[i-1][2]+a[i][j]>f[i][j])
		 				{
		 					f[i][j]=f[i-1][2]+a[i][j];
		 					t2++;
						}
					}
				 	
				}
 				if(j==3)
				{
					if(t3==n/2)
					{
						f[i][j]=max(f[i-1][2]+a[i][j],f[i-1][1]+a[i][j]);
					}
					if(t3<n/2)
					{
					 	f[i][j]=max(f[i-1][2]+a[i][j],f[i-1][1]+a[i][j]);
		 				//f[i][j]=max(f[i][j],f[i-1][3]+a[i][j]);
		 				if(f[i-1][3]+a[i][j]>f[i][j])
		 				{
		 					f[i][j]=f[i-1][3]+a[i][j];
		 					t3++;
						}
					}
				}
			}
		}
		maxx=-1;
		for(i=1;i<=n;i++)
		{
			maxx=max(maxx,f[n][i]);
		}
		
		cout<<maxx;
	}
	return 0;
 } 
