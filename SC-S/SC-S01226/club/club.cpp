#include<bits/stdc++.h>
using namespace std;
long long t,i,n,j,ans1,ans2,ans3;
long long a2[10010][4];
long long b2[10010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (i=1;i<=t;i++)
	{
		cin>>n;
		long long mx=n/2,erl=0,sanl=0;
		for (j=1;j<=n;j++)
		{
			cin>>a2[j][1]>>a2[j][2]>>a2[j][3];
			if (a2[j][2]==0)
			{
				erl++;
			}
			if (a2[j][3]==0)
			{
				sanl++;
			}
		}
		if (n==2)
		{
			long long ans=0;
			ans=max(ans,a2[1][1]+a2[2][2]);
			ans=max(ans,a2[1][1]+a2[2][3]);
			ans=max(ans,a2[1][2]+a2[2][1]);
			ans=max(ans,a2[1][2]+a2[2][3]);
			ans=max(ans,a2[1][3]+a2[2][2]);
			ans=max(ans,a2[1][3]+a2[2][1]);
			cout<<ans;
			continue;
		}
		else if (n==4)
		{
			long long ans=0;
			for (long long s1=1;s1<=3;s1++)
			{
				for (long long s2=1;s2<=3;s2++)
				{
					for (long long s3=1;s3<=3;s3++)
					{
						for (long long s4=1;s4<=3;s4++)
						{
							long long f=0,g=0,h=0;
							if (s1==1)
							{
								f++;
							}
							else if (s1==2)
							{
								g++;
							}
							else
							{
								h++;
							}
							
							
							if (s2==1)
							{
								f++;
							}
							else if (s2==2)
							{
								g++;
							}
							else
							{
								h++;
							}
							
							
							if (s3==1)
							{
								f++;
							}
							else if (s3==2)
							{
								g++;
							}
							else
							{
								h++;
							}
							
							
							if (s4==1)
							{
								f++;
							}
							else if (s4==2)
							{
								g++;
							}
							else
							{
								h++;
							}
							
							if (f<=n/2 && g<=n/2 && h<=n/2)
							{
								ans=max(ans,a2[1][s1]+a2[2][s2]+a2[3][s3]+a2[4][s4]);
							}
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		else if (n==10)
		{
			long long ans=0;
			for (long long s1=1;s1<=3;s1++)
			{
				for (long long s2=1;s2<=3;s2++)
				{
					for (long long s3=1;s3<=3;s3++)
					{
						for (long long s4=1;s4<=3;s4++)
						{
							for (long long s5=1;s5<=3;s5++)
							{
								for (long long s6=1;s6<=3;s6++)
								{
									for (long long s7=1;s7<=3;s7++)
									{
										for (long long s8=1;s8<=3;s8++)
										{
											for (long long s9=1;s9<=3;s9++)
											{
												for (long long s10=1;s10<=3;s10++)
												{
													long long f=0,g=0,h=0;
													if (s1==1)
													{
														f++;
													}
													else if (s1==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													
													if (s2==1)
													{
														f++;
													}
													else if (s2==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													
													if (s3==1)
													{
														f++;
													}
													else if (s3==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													
													if (s4==1)
													{
														f++;
													}
													else if (s4==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													if (s5==1)
													{
														f++;
													}
													else if (s5==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													if (s6==1)
													{
														f++;
													}
													else if (s6==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													if (s7==1)
													{
														f++;
													}
													else if (s7==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													if (s8==1)
													{
														f++;
													}
													else if (s8==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													if (s9==1)
													{
														f++;
													}
													else if (s9==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													
													if (s10==1)
													{
														f++;
													}
													else if (s10==2)
													{
														g++;
													}
													else
													{
														h++;
													}
													if (f<=n/2 && g<=n/2 && h<=n/2)
													{
														ans=max(ans,a2[1][s1]+a2[2][s2]+a2[3][s3]+a2[4][s4]+a2[5][s5]+a2[6][s6]+a2[7][s7]+a2[8][s8]+a2[9][s9]+a2[10][s10]);
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
			continue;
		}
		if (sanl==n)
		{
			if (erl==n)
			{
				for (j=1;j<=n;j++)
				{
					b2[j]=a2[j][1];
				}
				sort(b2+1,b2+n+1);
				long long ans=0;
				for (j=n;j>n/2;j--)
				{
					ans+=b2[j];
				}
				cout<<ans<<endl;
				continue;
			}
		}
		for (j=1;j<=n;j++)
		{
			long long a,b,c,zd;
			a=a2[j][1];
			b=a2[j][2];
			c=a2[j][3];
			zd=max(ans1,max(ans2,ans3));
			if (j==1)
			{
				ans1=a;
				ans2=b;
				ans3=c;
			}
			else if (j<=mx)
			{
				long long x,y,z;
				x=zd+a;
				y=zd+b;
				z=zd+c;
				if (x>=y && x>=z)
				{
					ans1=x;
				}
				if (y>=x && y>=z)
				{
					ans2=y;
				}
				if (z>=y && z>=x)
				{
					ans3=z;
				}
			}
			else
			{
				long long x,y,z;
				x=max(ans2+a,ans3+a);
				y=max(ans1+b,ans3+b);
				z=max(ans2+c,ans1+c);
				if (x>=y && x>=z)
				{
					ans1=x;
				}
				if (y>=x && y>=z)
				{
					ans2=y;
				}
				if (z>=y && z>=x)
				{
					ans3=z;
				}
			}
		}
		cout<<max(ans1,max(ans2,ans3))<<endl;
	}
	return 0;
}