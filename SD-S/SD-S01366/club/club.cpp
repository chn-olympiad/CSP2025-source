#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int hg1,hg2,hg3,maxx,cha;
}a[100005];
int t;
long long ans[6];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,ren1=0,ren2=0,ren3=0,minn1=0,minn2=0,minn3=0,flag=0;
		ans[i]=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			cin>>a[i].hg1>>a[i].hg2>>a[i].hg3;
			a[i].maxx=max(max(a[i].hg1,a[i].hg2),a[i].hg3);
			if(a[i].maxx==a[i].hg1)
			{
				a[i].cha=min(a[i].hg1-a[i].hg2,a[i].hg1-a[i].hg3);
				if(ren1<n/2)
				{
					ren1++;
					ans[i]+=a[i].maxx;
					if(a[i].cha<minn1)
					{
						minn1=a[i].cha;
						flag=i;
					}
				}
				else
				{
					if(minn1<a[i].cha)
					{
						ans[i]=ans[i]-minn1+a[i].maxx;
						minn1=a[i].cha;
						flag=i;
					}
					else
					{
						ans[i]=ans[i]+a[i].hg1-a[i].cha;
					}
				}
			}
			else if(a[i].maxx==a[i].hg2)
			{
				a[i].cha=min(a[i].hg2-a[i].hg1,a[i].hg2-a[i].hg3);
				if(ren2<n/2)
				{
					ren2++;
					ans[i]+=a[i].maxx;
					if(a[i].cha<minn2)
					{
						minn2=a[i].cha;
						flag=i;
					}
				}
				else
				{
					if(minn2<a[i].cha)
					{
						ans[i]=ans[i]-minn2+a[i].maxx;
						minn2=a[i].cha;
						flag=i;
					}
					else
					{
						ans[i]=ans[i]+a[i].hg2-a[i].cha;
					}
				}
			}
			else if(a[i].maxx==a[i].hg3)
			{
				a[i].cha=min(a[i].hg3-a[i].hg2,a[i].hg3-a[i].hg1);
				if(ren3<n/2)
				{
					ren3++;
					ans[i]+=a[i].maxx;
					if(a[i].cha<minn3)
					{
						minn3=a[i].cha;
						flag=i;
					}
				}
				else
				{
					if(minn3<a[i].cha)
					{
						ans[i]=ans[i]-minn3+a[i].maxx;
						minn3=a[i].cha;
						flag=i;
					}
					else
					{
						ans[i]=ans[i]+a[i].hg3-a[i].cha;
					}
				}
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
