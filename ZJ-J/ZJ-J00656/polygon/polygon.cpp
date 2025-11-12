#include<bits/stdc++.h>
using namespace std;
int n,a[10001],ans,cnt=1,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		for(int i=3;i<=n;i++)
		{
			for(int j=n;j>=n-i+1;j--)
			{
				cnt*=j;
				cnt%=998244353;
			}
			for(int j=1;j<=i;j++)
			{
				cnt/=j;
				cnt%=998244353;
			}
			sum+=cnt;
			cnt=1;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]>a[k])
				{
					ans++;
					ans%=998244353;
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
				for(int x=k+1;x<=n;x++)
				{
					if(a[i]+a[j]+a[k]>a[x])
					{
						ans++;
						ans%=998244353;
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
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						if(a[i]+a[j]+a[k]+a[x]>a[y])
						{
							ans++;
							ans%=998244353;
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
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							if(a[i]+a[j]+a[k]+a[x]+a[y]>a[z])
							{
								ans++;
								ans%=998244353;
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
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]>a[o])
								{
									ans++;
									ans%=998244353;
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
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]>a[v])
									{
										ans++;
										ans%=998244353;
									}
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
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]>a[u])
										{
											ans++;
											ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]>a[s])
											{
												ans++;
												ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]>a[b])
												{
													ans++;
													ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]>a[c])
													{
														ans++;
														ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]>a[d])
														{
															ans++;
															ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														for(int e=d+1;e<=n;e++)
														{
															if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]+a[d]>a[e])
															{
																ans++;
																ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														for(int e=d+1;e<=n;e++)
														{
															for(int f=e+1;f<=n;f++)
															{
																if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]+a[d]+a[e]>a[f])
																{
																	ans++;
																	ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														for(int e=d+1;e<=n;e++)
														{
															for(int f=e+1;f<=n;f++)
															{
																for(int g=f+1;g<=n;g++)
																{
																	if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]+a[d]+a[e]+a[f]>a[g])
																	{
																		ans++;
																		ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														for(int e=d+1;e<=n;e++)
														{
															for(int f=e+1;f<=n;f++)
															{
																for(int g=f+1;g<=n;g++)
																{
																	for(int h=g+1;h<=n;h++)
																	{
																		if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>a[h])
																		{
																			ans++;
																			ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														for(int e=d+1;e<=n;e++)
														{
															for(int f=e+1;f<=n;f++)
															{
																for(int g=f+1;g<=n;g++)
																{
																	for(int h=g+1;h<=n;h++)
																	{
																		for(int l=h+1;l<=n;l++)
																		{
																			if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>a[l])
																			{
																				ans++;
																				ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														for(int e=d+1;e<=n;e++)
														{
															for(int f=e+1;f<=n;f++)
															{
																for(int g=f+1;g<=n;g++)
																{
																	for(int h=g+1;h<=n;h++)
																	{
																		for(int l=h+1;l<=n;l++)
																		{
																			for(int m=l+1;m<=n;m++)
																			{
																				if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]>a[m])
																				{
																					ans++;
																					ans%=998244353;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						for(int z=y+1;z<=n;z++)
						{
							for(int o=z+1;o<=n;o++)
							{
								for(int v=o+1;v<=n;v++)
								{
									for(int u=v+1;u<=n;u++)
									{
										for(int s=u+1;s<=n;s++)
										{
											for(int b=s+1;b<=n;b++)
											{
												for(int c=b+1;c<=n;c++)
												{
													for(int d=c+1;d<=n;d++)
													{
														for(int e=d+1;e<=n;e++)
														{
															for(int f=e+1;f<=n;f++)
															{
																for(int g=f+1;g<=n;g++)
																{
																	for(int h=g+1;h<=n;h++)
																	{
																		for(int l=h+1;l<=n;l++)
																		{
																			for(int m=l+1;m<=n;m++)
																			{
																				for(int p=m+1;p<=n;p++)
																				{
																					if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[o]+a[v]+a[u]+a[s]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]>a[p])
																					{
																						ans++;
																						ans%=998244353;
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
	}
	cout<<ans;
	return 0;
}
