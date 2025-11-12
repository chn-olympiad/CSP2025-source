#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int a1,a2,a3,flag;
};
int n;
node a[10005];
bool cmp1(node x,node y)
{
	return x.a1>y.a1;
}
int ans=0,maxi=0;
//void mj(int x)
//{
//	if(x==n)
//	{
//		if(ans>maxi)
//		{
//			cout<<ans<<endl;
//			maxi=ans;
//		}
//		return ;
//	}
//	for(int i=1;i<=3;i++)
//	{
//		if(x==1)
//		{
//			ans=0;
//		}
//		if(cnt1>n/2||cnt2>n/2||cnt3>n/2) continue;
//		if(i==1)
//		{
//			cnt1++;
//			ans+=a[x].a1;
//		}
//		else if(i==2)
//		{
//			cnt2++;
//			ans+=a[x].a2;
//		}
//		else
//		{
//			cnt3++;
//			ans+=a[x].a3;
//		}
//		mj(x+1);
//		if(i==1)
//		{
//			cnt1--;
//			ans-=a[x].a1;
//		}
//		else if(i==2)
//		{
//			cnt2--;
//			ans-=a[x].a2;
//		}
//		else
//		{
//			cnt3--;
//			ans-=a[x].a3;
//		}
//	}
//}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int flagA=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=a[i].a3||a[i].a2!=0)
				flagA=1;
		}
		if(flagA==0)
		{
			ans=0;
			int l=n/2;
			sort(a+1,a+n+1,cmp1);
			for(i=1;i<=l;i++)
			{
				ans+=a[i].a1;
			}
			continue;
		}
		if(n==2)
		{
			maxi=0;
			ans=0;
			for(i=1;i<=3;i++)
			{
				ans=0;
				if(i==1)
				{
					ans+=a[1].a1;
				}
				if(i==2)
				{
					ans+=a[1].a2;
				}
				if(i==3)
				{
					ans+=a[1].a3;
				}
				for(j=1;j<=3;j++)
				{
					if(i==j) continue;
					if(j==1)
					{
						ans+=a[2].a1;
					}
					if(j==2)
					{
						ans+=a[2].a2;
					}
					if(j==3)
					{
						ans+=a[2].a3;
					}
					if(ans>maxi)
					{
						maxi=ans;
					}
				}
			}
			cout<<maxi<<endl;
			continue;
		}
		if(n==4)
		{
			maxi=0;
			int m,k;
			for(i=1;i<=3;i++)
			{
				int cnt[5]={0};
				cnt[i]++;
				ans=0;
				if(i==1)
				{
					ans+=a[1].a1;
				}
				if(i==2)
				{
					ans+=a[1].a2;
				}
				if(i==3)
				{
					ans+=a[1].a3;
				}
				for(j=1;j<=3;j++)
				{
					cnt[j]++;
					if(j==1)
					{
						ans+=a[2].a1;
					}
					if(j==2)
					{
						ans+=a[2].a2;
					}
					if(j==3)
					{
						ans+=a[2].a3;
					}
					for(m=1;m<=3;m++)
					{
						if(cnt[m]>=n/2) continue;
						cnt[m]++;
						if(m==1)
						{
							ans+=a[3].a1;
						}
						if(m==2)
						{
							ans+=a[3].a2;
						}
						if(m==3)
						{
							ans+=a[3].a3;
						}
						for(k=1;k<=3;k++)
						{
							if(cnt[k]>n/2) continue;
							cnt[k]++;
							if(k==1)
							{
								ans+=a[4].a1;
							}
							if(k==2)
							{
								ans+=a[4].a2;
							}
							if(k==3)
							{
								ans+=a[4].a3;
							}
							if(ans>maxi)
							{
								maxi=ans;
							}
							if(k==1)
							{
								ans-=a[4].a1;
							}
							if(k==2)
							{
								ans-=a[4].a2;
							}
							if(k==3)
							{
								ans-=a[4].a3;
							}
						}
						if(m==1)
						{
							ans-=a[3].a1;
						}
						if(m==2)
						{
							ans-=a[3].a2;
						}
						if(m==3)
						{
							ans-=a[3].a3;
						}
					}
					cnt[j]--;
					if(j==1)
					{
						ans-=a[2].a1;
					}
					if(j==2)
					{
						ans-=a[2].a2;
					}
					if(j==3)
					{
						ans-=a[2].a3;
					}
				}
				cnt[i]--;
			}
			cout<<maxi<<endl;
			continue;
		}
	}
	return 0;
}
