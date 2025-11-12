#include<bits/stdc++.h>
using namespace std;
int t,n,maxx=-1,flag=1,sum=0;
int a[100005][5];
int b[100005];
int tou[5];
int suan(int ren)
{
	if(ren==0)
	{
		return maxx;
	}
	for(int i=1;i<=3;i++)
	{
		if(sum>maxx)
		{
			maxx=sum;
		}
		if(tou[i]<(n*1.0/2))
		{
			tou[i]++;
			sum+=a[n-ren][i];
			suan(ren-1);
		}
		else
		{
			continue;
		}
	}
	return maxx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxx=-1;
		sum=0;
		flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 or a[i][3]!=0)
			{
				flag=0;
			}
		}
		if(n==2)
		{
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j)
					{
						sum=a[1][i]+a[2][j];
						if(sum>maxx)
						{
							maxx=sum;
						}
					}
					
				}
			}
			cout<<maxx<<"\n";
			continue;
		}
		if(flag==1)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>(n*1.0/2);i--)
			{
				sum+=b[i];
			}
			cout<<sum<<"\n";
		}
		else
		{
			tou[1]=0;
			tou[2]=0;
			tou[3]=0;
			cout<<suan(n)<<"\n";
		}
	}
	return 0;
}
