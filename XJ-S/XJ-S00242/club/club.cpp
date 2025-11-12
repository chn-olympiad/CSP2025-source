#include<iostream>
#include<algorithm>
using namespace std;
int a[35][35];
int m[35];
int b[35];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,k=0,i,j,sum=0,s;
	cin>>t;
	while(t--)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			m[i]=0;
		}
		cin>>n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>a[i][j];//数据 
			} 
		}
		s=n/2;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				if(a[i][j]>m[i])
				{
					m[i]=a[i][j];//每一横行的最大值 
					b[i]=j;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(b[i]==b[j])
				{
					k++;
				}
			}
		}
		if(k>s)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=3;j++)
				{
					if(j==b[i])
					{
						j++;
					}
					m[i]=a[i][j];
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			sum+=m[i];
		}
		cout<<sum<<endl;
	}
	return 0;	
} 
