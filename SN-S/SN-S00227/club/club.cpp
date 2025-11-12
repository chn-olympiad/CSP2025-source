#include<bits/stdc++.h>
using namespace std;
int a[3003][3003];
int b1[3030][3000],b2[3000][3003],b3[3003][3003];
int dp[10010];
int t,n;
int f(int a,int b,int c)
{
	if(max(max(a,b),c)==a) return 1;
	if(max(max(a,b),c)==b) return 2;
	if(max(max(a,b),c)==c) return 3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int sum1=0,sum2=0,sum3=0,c[100100],d1,d2;
	int x1=0,x2=0,x3=0;
	int x,y;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}	

		int sum=0;
		for(int j=1;j<=n;j++)
		{
			//for(int k=1;k<=n;k++)
			{
				c[j]=f(a[j][1],a[j][2],a[j][3]);
				//cout<<c[j]<<endl;	
				//cout<<a[j][1]<<" "<<a[j][2]<<" "<<a[j][3]<<endl;
				if(c[j]==1) 
				{
					b1[j][1]=a[j][1];
					sum1=a[j][1]+sum1;
					b1[j][2]=max(a[j][2],a[j][3]);
					x1++;	
				}
				if(c[j]==2) 
				{
					b2[j][1]=a[j][2];
					sum2=a[j][2]+sum2;
					b1[j][2]=max(a[j][1],a[j][3]);
					x2++;
				}
				if(c[j]==3) 
				{
					b3[j][1]=a[j][3];
					sum3=a[j][3]+sum3;	
					b1[j][2]=max(a[j][2],a[j][1]);
					x3++;
				}
				//cout<<b2[j][1];
			}
			
		}	
		d1=max(max(x1,x2),x3);
		sum=sum1+sum2+sum3;
			int l=0;
		//cout<<d1<<" "<<x2;
		if(d1<=n/2) 
		{
			
			l=sum;
		}
		else
		{
		
			if(d1==x1)
			{
				
				while(d1>n/2)
				{
					b1[0][1]=100000;
					for(int j=1;j<=x1;j++)
					{
						
						b1[j][1]=min(b1[j-1][1],b1[j][1]);
						
						x=b1[j][1];
						y=b1[j][2];
					}	
					sum=sum-x+y;
					d1--;
				}
				l=sum;
			}
			if(d1==x2)
			{
				
				while(d1>n/2)
				{
					b2[0][1]=100000;
					for(int j=1;j<=x2;j++)
					{
						
						b2[j][1]=min(b2[j-1][1],b2[j][1]);
						
						x=b2[j][1];
						y=b2[j][2];
					}	
					sum=sum-x+y;
					d1--;
				}
				l=sum;
			}
			if(d1==x3)
			{
				
				while(d1>n/2)
				{
					b3[0][1]=100000;
					for(int j=1;j<=x3;j++)
					{
						
						b3[j][1]=min(b3[j-1][1],b3[j][1]);
						
						x=b3[j][1];
						y=b3[j][2];
					}	
					sum=sum-x+y;
					d1--;
				}
				
				l=sum;
			}
			
		}
		cout<<l<<endl;
		l=0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/
