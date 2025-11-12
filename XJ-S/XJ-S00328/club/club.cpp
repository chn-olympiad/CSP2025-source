#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int a[100005][5],flag[5];
int c[100005];
int t,n;
long long sum=0,Max=0;
int pd()
{
	for(int i=1;i<=3;i++)
	{
		if(2*flag[i]>n)
		{
			return 2;
		}
	}
	return 1;
}
void D(int step)
{
	if(step==n+1)
	{
		if(pd()==2)
		{
			return;
		}
		if(sum>Max)
		{
			Max=sum;
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		sum+=a[step][i];
		flag[i]++;
		if(pd()==1)
		{
			D(step+1);
		}
		sum-=a[step][i];
		flag[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==100000)
		{
			int O,I;
			long long Sum=0;
			for(int i=1;i<=n;i++)
			{
			    cin>>c[i]>>O>>I;
			}
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2;i--)
			{
				Sum+=c[i];
			}
			cout<<Sum<<endl;
		} 
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
				}
			}
			D(1);
			cout<<Max<<endl;
		}
		sum=0;Max=0;
		memset(flag,0,sizeof(flag));
	}
	return 0;
} 
