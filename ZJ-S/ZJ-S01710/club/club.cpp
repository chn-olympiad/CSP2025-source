#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,x,y,z,s1,s2,s3;
struct BYM
{
	long long shu,maxn,cha;
}a[1000100];
bool cmp(BYM x,BYM y)
{
	return x.cha<y.cha;
}
int main( )
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//cin.tie(0);
	//cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		long long s=n/2;
		s1=s2=s3=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			if(x>=y&&x>=z)
			{
				a[i].maxn=x;
				a[i].shu=1;
				if(y>=z)
				{
					a[i].cha=x-y;
				}
				else
				{
					a[i].cha=x-z;
				}
				s1+=1;
				continue;
			}
			if(y>=x&&y>=z)
			{
				a[i].maxn=y;
				a[i].shu=2;
				if(x>=z)
				{
					a[i].cha=y-x;
				}
				else
				{
					a[i].cha=y-z;
				}
				s2+=1;
				continue;
			}
			if(z>=x&&z>=y)
			{
				a[i].maxn=z;
				a[i].shu=3;
				if(x>=y)
				{
					a[i].cha=z-x;
				}
				else
				{
					a[i].cha=z-y;
				}
				s3+=1;
				continue;
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans=ans+a[i].maxn;
		}
		sort(a+1,a+1+n,cmp);
		if(s1>s)
		{
			for(int i=1;i<=n;i++)
			{
				if(s1==s)
				{
					break;
				}
				if(a[i].shu==1)
				{
					ans=ans-a[i].cha;
					s1-=1;
				}
			}
		}
		if(s2>s)
		{
			for(int i=1;i<=n;i++)
			{
				if(s2==s)
				{
					break;
				}
				if(a[i].shu==2)
				{
					ans=ans-a[i].cha;
					s2-=1;
				}
			}
		}
		if(s3>s)
		{
			for(int i=1;i<=n;i++)
			{
				if(s3==s)
				{
					break;
				}
				if(a[i].shu==3)
				{
					ans=ans-a[i].cha;
					s3-=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//I LOVE BYM    QwQ
//cha dian zha le
