#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,a[100000005],sum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;j<=n;k++)
			{
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))) sum++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;j<=n;k++)
			{
				for(int z=1;z<=n;z++)
				{
					if(a[i]+a[j]+a[k]+a[z]>2*max(a[z],max(a[k],max(a[i],a[j])))) sum++;
				}
			}
		}
	}
	if(n>4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;j<=n;k++)
				{
					for(int z=1;z<=n;z++)
					{
						for(int a=1;a<=n;a++)
						{
							if(a[i]+a[j]+a[k]+a[z]+a[a]>2*max(a[a]max(a[z],max(a[k],max(a[i],a[j])))) sum++;
						}
					}
				}
			}
		}
	}
	if(n>5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;j<=n;k++)
				{
					for(int z=1;z<=n;z++)
					{
						for(int a=1;a<=n;a++)
						{
							for(int b=1;b<=n;b++)
							{
								if(a[i]+a[j]+a[k]+a[z]+a[a]+a[b]>2*max(a[b],max(a[a],max(a[z],max(a[k],max(a[i],a[j]))))) sum++; 
							}
						}
					}
				}	
			}
		}
	}
	if(n>6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;j<=n;k++)
				{
					for(int z=1;z<=n;z++)
					{
						for(int a=1;a<=n;a++)
						{
							for(int b=1;b<=n;b++)
							{
								for(int c=1;c<=n;c++)
								{
									if(a[i]+a[j]+a[k]+a[z]+a[a]+a[b]+a[c]>2*max(a[c],max(a[b],max(a[a],max(a[z],max(a[k],max(a[i],a[j])))))) sum++; 
								}
							}
						}
					}
				}	
			}
		}
	}
	if(n>7)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;j<=n;k++)
				{
					for(int z=1;z<=n;z++)
					{
						for(int a=1;a<=n;a++)
						{
							for(int b=1;b<=n;b++)
							{
								for(int c=1;c<=n;c++)
								{
									for(int d=1;d<=n;d++)
									if(a[i]+a[j]+a[k]+a[z]+a[a]+a[b]+a[c]+a[d]>2*max(a[d],max(a[c],max(a[b],max(a[a],max(a[z],max(a[k],max(a[i],a[j])))))))) sum++; 
								}
							}
						}
					}
				}	
			}
		}
	}
	cout<<sum;
	return 0;
}
