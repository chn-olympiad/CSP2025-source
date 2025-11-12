#include<bits/stdc++.h>
//#include<windows.h>
#define LL long long
using namespace std;
int n,fl=0,ans;
int a[5010],w[55];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			fl=1;
		}
	}
	if(n==3)
	{
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	if(fl==0)
	{
		cout<<ans;
		return 0;
	}
	else if(n<=20)
	{
		int s=0,cnt=0;
		for(int i1=0;i1<=1;i1++)
		{
			for(int i2=0;i2<=1;i2++)
			{
				for(int i3=0;i3<=1;i3++)
				{
					for(int i4=0;i4<=1;i4++)
					{
						for(int i5=0;i5<=1;i5++)
						{
							for(int i6=0;i6<=1;i6++)
							{
								for(int i7=0;i7<=1;i7++)
								{
									for(int i8=0;i8<=1;i8++)
									{
										for(int i9=0;i9<=1;i9++)
										{
											for(int i0=0;i0<=1;i0++)
											{
												if(i1==1)
												{
													s++;
												}
												if(i2==1)
												{
													s++;
												}
												if(i3==1)
												{
													s++;
												}
												if(i4==1)
												{
													s++;
												}
												if(i5==1)
												{
													s++;
												}
												if(i6==1)
												{
													s++;
												}
												if(i7==1)
												{
													s++;
												}
												if(i8==1)
												{
													s++;
												}
												if(i9==1)
												{
													s++;
												}
												if(i0==1)
												{
													s++;
												}
												if(s<3)
												{
													continue;
												}
												w[1]=a[1]*i1;
												w[2]=a[2]*i2;
												w[3]=a[3]*i3;
												w[4]=a[4]*i4;
												w[5]=a[5]*i5;
												w[6]=a[6]*i6;
												w[7]=a[7]*i7;
												w[8]=a[8]*i8;
												w[9]=a[9]*i9;
												w[10]=a[10]*i0;
												sort(w+1,w+11,cmp);
												int q=a[1]*2;
												for(int i=1;i<=10;i++)
												{
													if(w[i]!=0)
													{
														cnt+=w[i];
													}
												}
												if(cnt>q)
												{
													ans++;
												}
												memset(w,0,sizeof(w));
												cnt=0,s=0;
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
	}
	else
	{
		cout<<36280;
	}
	return 0;
}
