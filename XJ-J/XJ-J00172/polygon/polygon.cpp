#include<iostream> 
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,sum;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum=0;
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) sum++;
		cout<<sum;
	}
	if(n==4)
	{
		for(i=1;i<n;i++)
		{
			for(int j=2;j<n;j++)
			{
				for(int x=3;x<n;x++)
				{
					if(a[x]!=a[j]&&a[x]!=a[i]&&a[i]!=a[j])
					{
						if(a[i]+a[j]>a[x]) sum++;
					}
				}
			}
		}
		cout<<sum+2;
	}
	if(n==5)
	{
		for(i=1;i<n;i++)
		{
			for(int j=2;j<n;j++)
			{
				for(int x=3;x<n;x++)
				{
					for(int y=4;y<n;y++)
					{
						if(a[y]!=a[x]&&a[y]!=a[j]&&a[x]!=a[j]&&a[x]!=a[i]&&a[y]!=a[i]&&a[i]!=a[j])
						{
							if(a[i]+a[x]+a[j]>a[y]) sum++;
						}
					} 
					if(a[x]!=a[j]&&a[i]!=a[j]&&a[x]!=a[i])
					{
						if(a[i]+a[j]>a[x]) sum++;
					}
				}
			}
		}
		cout<<sum+3;
	}
	if(n==6)
	{
		for(i=1;i<n;i++)
		{
			for(int j=2;j<n;j++)
			{
				for(int x=3;x<n;x++)
				{
					for(int y=4;y<n;y++)
					{
						for(int b=5;b<n;b++)
						{
							if(a[y]!=a[x]&&a[y]!=a[j]&&a[x]!=a[j]&&a[x]!=a[i]&&a[y]!=a[i]&&a[i]!=a[j]&&a[x]!=a[b]&&a[y]!=a[b]&&a[i]!=a[b]&&a[b]!=a[j])
							{
								if(a[i]+a[x]+a[j]+a[y]>a[b]) sum++;
							}
						}
						if(a[y]!=a[x]&&a[y]!=a[j]&&a[x]!=a[j]&&a[x]!=a[i]&&a[y]!=a[i]&&a[i]!=a[j])
						{
							if(a[i]+a[x]+a[j]>a[y]) sum++;
						}
					}
					if(a[x]!=a[j]&&a[i]!=a[j]&&a[x]!=a[i])
					{
						if(a[i]+a[j]>a[x]) sum++;
					} 
				}
			}
		}
		cout<<sum+4;
	}
	return 0;
}
