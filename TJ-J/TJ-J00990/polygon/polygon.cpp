#include<bits/stdc++.h>
using namespace std;
int a[100010];
int ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int sum=a[i]+a[j]+a[k];
					int cnt=max(a[i],max(a[j],a[k]));
					cnt*=2;
					if(sum>cnt) ans++;
				}
			}
		}
	}
	if(n==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int sum=a[i]+a[j]+a[k];
					int cnt=max(a[i],max(a[j],a[k]));
					cnt*=2;
					if(sum>cnt) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						int sum=a[i]+a[j]+a[k]+a[z];
						int cnt=max(a[i],max(a[j],max(a[k],a[z])));
						cnt*=2;
						if(sum>cnt) ans++;
					}
				}
			}
		}
	}
	if(n==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int sum=a[i]+a[j]+a[k];
					int cnt=max(a[i],max(a[j],a[k]));
					cnt*=2;
					if(sum>cnt) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						int sum=a[i]+a[j]+a[k]+a[z];
						int cnt=max(a[i],max(a[j],max(a[k],a[z])));
						cnt*=2;
						if(sum>cnt) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							int sum=a[i]+a[j]+a[k]+a[z]+a[l];
							int cnt=max(a[i],max(a[j],max(a[k],max(a[z],a[l]))));
							cnt*=2;
							if(sum>cnt) ans++;
						}
					}
				}
			}
		}
	}
	if(n==6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int sum=a[i]+a[j]+a[k];
					int cnt=max(a[i],max(a[j],a[k]));
					cnt*=2;
					if(sum>cnt) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						int sum=a[i]+a[j]+a[k]+a[z];
						int cnt=max(a[i],max(a[j],max(a[k],a[z])));
						cnt*=2;
						if(sum>cnt) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							int sum=a[i]+a[j]+a[k]+a[z]+a[l];
							int cnt=max(a[i],max(a[j],max(a[k],max(a[z],a[l]))));
							cnt*=2;
							if(sum>cnt) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p];
								int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],a[p]))))));
								cnt*=2;
								if(sum>cnt) ans++;
							}
						}
					}
				}
			}
		}
	}
	if(n==7)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int sum=a[i]+a[j]+a[k];
					int cnt=max(a[i],max(a[j],a[k]));
					cnt*=2;
					if(sum>cnt) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						int sum=a[i]+a[j]+a[k]+a[z];
						int cnt=max(a[i],max(a[j],max(a[k],a[z])));
						cnt*=2;
						if(sum>cnt) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							int sum=a[i]+a[j]+a[k]+a[z]+a[l];
							int cnt=max(a[i],max(a[j],max(a[k],max(a[z],a[l]))));
							cnt*=2;
							if(sum>cnt) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p];
								int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],a[p]))))));
								cnt*=2;
								if(sum>cnt) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								for(int q=p+1;q<=n,q++)
								{
									int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p]+a[q];
									int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(a[p],a[q]))))));
									cnt*=2;
									if(sum>cnt) ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==8)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int sum=a[i]+a[j]+a[k];
					int cnt=max(a[i],max(a[j],a[k]));
					cnt*=2;
					if(sum>cnt) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						int sum=a[i]+a[j]+a[k]+a[z];
						int cnt=max(a[i],max(a[j],max(a[k],a[z])));
						cnt*=2;
						if(sum>cnt) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							int sum=a[i]+a[j]+a[k]+a[z]+a[l];
							int cnt=max(a[i],max(a[j],max(a[k],max(a[z],a[l]))));
							cnt*=2;
							if(sum>cnt) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p];
								int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],a[p]))))));
								cnt*=2;
								if(sum>cnt) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								for(int q=p+1;q<=n,q++)
								{
									int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p]+a[q];
									int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(a[p],a[q]))))));
									cnt*=2;
									if(sum>cnt) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								for(int q=p+1;q<=n,q++)
								{
									for(int e=q+1;e<=n;e++)
									{
										int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p]+a[q]+a[e];
										int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(a[p],max(a[q],a[e])))))));
										cnt*=2;
										if(sum>cnt) ans++;
									} 
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==9)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int sum=a[i]+a[j]+a[k];
					int cnt=max(a[i],max(a[j],a[k]));
					cnt*=2;
					if(sum>cnt) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						int sum=a[i]+a[j]+a[k]+a[z];
						int cnt=max(a[i],max(a[j],max(a[k],a[z])));
						cnt*=2;
						if(sum>cnt) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							int sum=a[i]+a[j]+a[k]+a[z]+a[l];
							int cnt=max(a[i],max(a[j],max(a[k],max(a[z],a[l]))));
							cnt*=2;
							if(sum>cnt) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p];
								int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],a[p]))))));
								cnt*=2;
								if(sum>cnt) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								for(int q=p+1;q<=n,q++)
								{
									int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p]+a[q];
									int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(a[p],a[q]))))));
									cnt*=2;
									if(sum>cnt) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								for(int q=p+1;q<=n,q++)
								{
									for(int e=q+1;e<=n;e++)
									{
										int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p]+a[q]+a[e];
										int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(a[p],max(a[q],a[e])))))));
										cnt*=2;
										if(sum>cnt) ans++;
									} 
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int p=l+1;p<=n;p++)
							{
								for(int q=p+1;q<=n,q++)
								{
									for(int e=q+1;e<=n;e++)
									{
										for(int c=e+1;c<=n;c++)
										{
											int sum=a[i]+a[j]+a[k]+a[z]+a[l]+a[p]+a[q]+a[e]+a[c];
											int cnt=max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(a[p],max(a[q],max(a[e],a[c]))))))));
											cnt*=2;
											if(sum>cnt) ans++;
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
	ans%=998244353;
	cout<<ans;
	return 0; 
}
