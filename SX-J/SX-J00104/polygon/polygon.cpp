#include<bits/stdc++.h>//T3_30 fuckCCf fuckCSP-J
using namespace std;
const int N=1e4+10;
#define ll long long
ll n,ans;
int a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3)
	{
		if(a[1]+a[2]>a[3]) cout<<'1';
		else cout<<'0';
	}
	else
	{
		//3
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		//4
		for(int q=1;q<=n-3;q++)
		{
			for(int i=q+1;i<=n-2;i++)
			{
				for(int j=i+1;j<=n-1;j++)
				{
					for(int k=j+1;k<=n;k++)
					{
	     				if(a[i]+a[j]+a[q]>a[k]) ans++;
					}
				}
			}
		}
		//5
		for(int w=1;w<=n-4;w++)
		{
			for(int q=w+1;q<=n-3;q++)
			{
				for(int i=q+1;i<=n-2;i++)
				{
					for(int j=i+1;j<=n-1;j++)
					{
						for(int k=j+1;k<=n;k++)
						{
		     				if(a[w]+a[i]+a[j]+a[q]>a[k]) ans++;
						}
					}
				}
			}
		}
		//6
  		for(int e=1;e<=n-5;e++)
  		{
			for(int w=e+1;w<=n-4;w++)
			{
				for(int q=w+1;q<=n-3;q++)
				{
					for(int i=q+1;i<=n-2;i++)
					{
						for(int j=i+1;j<=n-1;j++)
						{
							for(int k=j+1;k<=n;k++)
							{
			     				if(a[e]+a[w]+a[i]+a[j]+a[q]>a[k]) ans++;
							}
						}
					}
				}
			}
		}
		//7
		for(int r=1;r<=n-6;r++)
		{
			for(int e=r+1;e<=n-5;e++)
	  		{
				for(int w=1;w<=n-4;w++)
				{
					for(int q=w+1;q<=n-3;q++)
					{
						for(int i=q+1;i<=n-2;i++)
						{
							for(int j=i+1;j<=n-1;j++)
							{
								for(int k=j+1;k<=n;k++)
								{
				     				if(a[r]+a[e]+a[w]+a[i]+a[j]+a[q]>a[k]) ans++;
								}
							}
						}
					}
				}
			}
		}
		//8
		for(int t=1;t<=n-7;t++)
		{
			for(int r=t+1;r<=n-6;r++)
			{
				for(int e=r+1;e<=n-5;e++)
		  		{
					for(int w=1;w<=n-4;w++)
					{
						for(int q=w+1;q<=n-3;q++)
						{
							for(int i=q+1;i<=n-2;i++)
							{
								for(int j=i+1;j<=n-1;j++)
								{
									for(int k=j+1;k<=n;k++)
									{
					     				if(a[t]+a[r]+a[e]+a[w]+a[i]+a[j]+a[q]>a[k]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		//9
		for(int y=1;y<=n-8;y++)
		{
			for(int t=y+1;t<=n-7;t++)
			{
				for(int r=t+1;r<=n-6;r++)
				{
					for(int e=r+1;e<=n-5;e++)
			  		{
						for(int w=1;w<=n-4;w++)
						{
							for(int q=w+1;q<=n-3;q++)
							{
								for(int i=q+1;i<=n-2;i++)
								{
									for(int j=i+1;j<=n-1;j++)
									{
										for(int k=j+1;k<=n;k++)
										{
						     				if(a[y]+a[t]+a[r]+a[e]+a[w]+a[i]+a[j]+a[q]>a[k]) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//10
		for(int u=1;u<=n-9;u++)
		{
			for(int y=1;y<=n-8;y++)
			{
				for(int t=y+1;t<=n-7;t++)
				{
					for(int r=t+1;r<=n-6;r++)
					{
						for(int e=r+1;e<=n-5;e++)
				  		{
							for(int w=1;w<=n-4;w++)
							{
								for(int q=w+1;q<=n-3;q++)
								{
									for(int i=q+1;i<=n-2;i++)
									{
										for(int j=i+1;j<=n-1;j++)
										{
											for(int k=j+1;k<=n;k++)
											{
							     				if(a[u]+a[y]+a[t]+a[r]+a[e]+a[w]+a[i]+a[j]+a[q]>a[k]) ans++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%998244353;
	}
	return 0;
}