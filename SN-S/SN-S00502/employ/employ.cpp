#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,ans,flag;
string s;
int a[10010];
int b[10010];
int fac[10010],inv[10010];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	} 
	return res;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[i-1]*qpow(i,mod-2)%mod;
	}
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		a[i]=(int)s[i]-'0';
		if(a[i]!=1)
		{
			flag=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n<=10)
	{
		int cnt=0;
		int shu[11];
		for(int i=1;i<=n;i++)//1
		{
			if(cnt<n)cnt++;
			shu[1]=a[i]; 
			if(cnt==n)
			{
				int cha=0,guo=0;
				for(int u=1;u<=cnt;u++)
				{
					if(a[u]==0) cha++;
					else if(cha<shu[u])guo++;
				}
				if(guo>=m)ans++;
			}
			else
			{
				for(int j=1;j!=i,j<=n;j++)//2
				{
					if(cnt<n)cnt++;
					shu[2]=a[j]; 
					if(cnt==n)
					{
						int cha=0,guo=0;
						for(int u=1;u<=cnt;u++)
						{
							if(a[u]==0) cha++;
							else if(cha<shu[u])guo++;
						}
						if(guo>=m)ans++;
					}
					else
					{
						for(int k=1;k!=i,k!=j,k<=n;k++)//3
						{
							if(cnt<n)cnt++;
							shu[3]=a[k]; 
							if(cnt==n)
							{
								int cha=0,guo=0;
								for(int u=1;u<=cnt;u++)
								{
									if(a[u]==0) cha++;
									else if(cha<shu[u])guo++;
								}
								if(guo>=m)ans++;
							}
							else
							{
								for(int l=1;l!=i,l!=j,l!=k,l<=n;l++)//4
								{
									if(4<n)cnt++;
									shu[cnt]=a[l]; 
									if(cnt==n)
									{
										int cha=0,guo=0;
										for(int u=1;u<=cnt;u++)
										{
											if(a[u]==0) cha++;
											else if(cha<shu[u])guo++;
										}
										if(guo>=m)ans++;
									}
									else
									{
										for(int o=1;o!=i,o!=j,o!=k,o!=l,o<=n;o++)//5
										{
											if(cnt<n)cnt++;
											shu[5]=a[o]; 
											if(cnt==n)
											{
												int cha=0,guo=0;
												for(int u=1;u<=cnt;u++)
												{
													if(a[u]==0) cha++;
													else if(cha<shu[u])guo++;
												}
												if(guo>=m)ans++;
											}
											else
											{
												for(int p=1;p!=o,p!=l,p!=k,p!=i,p!=j,p<=n;p++)//6
												{
													if(cnt<n)cnt++;
													shu[6]=a[p]; 
													if(cnt==n)
													{
														int cha=0,guo=0;
														for(int u=1;u<=cnt;u++)
														{
															if(a[u]==0) cha++;
															else if(cha<shu[u])guo++;
														}
														if(guo>=m)ans++;
													}
													else
													{
														for(int y=1;y!=p,y!=o,y!=l,y!=k,y!=i,y!=j,y<=n;y++)//7
														{
															if(cnt<n)cnt++;
															shu[7]=a[y]; 
															if(cnt==n)
															{
																int cha=0,guo=0;
																for(int u=1;u<=cnt;u++)
																{
																	if(a[u]==0) cha++;
																	else if(cha<shu[u])guo++;
																}
																if(guo>=m)ans++;
															}
															else
															{
																for(int x=1;x!=p,x!=o,x!=l,x!=k,x!=i,x!=j,x!=y,x<=n;x++)//8
																{
																	if(cnt<n)cnt++;
																	shu[8]=a[x]; 
																	if(cnt==n)
																	{
																		int cha=0,guo=0;
																		for(int u=1;u<=cnt;u++)
																		{
																			if(a[u]==0) cha++;
																			else if(cha<shu[u])guo++;
																		}
																		if(guo>=m)ans++;
																	}
																	else
																	{
																		for(int w=1;w!=x,w!=y,w!=p,w!=o,w!=i,w!=j,w!=k,w!=l,w<=n;w++)//9
																		{
																			if(cnt<n)cnt++;
																			shu[9]=a[w]; 
																			if(cnt==n)
																			{
																				int cha=0,guo=0;
																				for(int u=1;u<=cnt;u++)
																				{
																					if(a[u]==0) cha++;
																					else if(cha<shu[u])guo++;
																				}
																				if(guo>=m)ans++;
																			}
																			else
																			{
																				for(int d=1;d!=w,d!=x,d!=y,d!=p,d!=o,d!=i,d!=j,d!=k,d!=l,d<=n;d++)//10
																				{
																					if(cnt<n)cnt++;
																					shu[10]=a[d]; 
																					if(cnt==n)
																					{
																						int cha=0,guo=0;
																						for(int u=1;u<=cnt;u++)
																						{
																							if(a[u]==0) cha++;
																							else if(cha<shu[u])guo++;
																						}
																						if(guo>=m)ans++;
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
		cout<<ans<<endl;
	}
	if(flag==0)
	{
		cout<<fac[n]<<endl;
	}
	else if(m==1)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				flag=2;
			}
			maxx=max(maxx,b[i]);
		}
		if(flag!=2)
		{
			cout<<0<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1&&i-1<maxx)
				{
					flag=3;
					break;
				}
			}
			if(flag==3)
			{
				cout<<fac[n];
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
