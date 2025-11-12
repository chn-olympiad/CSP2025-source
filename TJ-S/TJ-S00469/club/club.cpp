#include<bits/stdc++.h>
using namespace std;
int n,t,maxs,sum[4];
long long ans;
bool f1,f2;
struct club{
	int a1,a2,a3,num,num2,num3,num4;
}a[211000];
int d(int x,int w)
{
	int o=max(max(a[x].a1,a[x].a2),a[x].a3);
	int h=min(min(a[x].a1,a[x].a2),a[x].a3);
	if(w==2)
	{
		if(a[x].a1!=o&&a[x].a1!=h) return 1;
		else if(a[x].a2!=o&&a[x].a2!=h) return 2;
		else return 3;
	}
	else if(w==1)
	{
		if(a[x].a1==o) return 1;
		else if(a[x].a2==o) return 2;
		else return 3;
	}
	else 
	{
		if(a[x].a1==h) return 1;
		else if(a[x].a2==h) return 2;
		else return 3;
	}
}
bool cmp(club x,club y)
{
	return x.a1>y.a1;
}
bool cmp2(club x,club y)
{
	return x.num>y.num;
}
bool cmp3(club x,club y)
{
	return x.num4>y.num4;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxs=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0) f1=1;
			if(a[i].a3!=0) f2=1;
			a[i].num=abs(a[i].a1-a[i].a2);
			a[i].num2=abs(a[i].a1-a[i].a3);
			a[i].num3=abs(a[i].a2-a[i].a3);
			a[i].num4=a[i].num+a[i].num2+a[i].num3;
		}  
		if(f1==0)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=maxs;i++) ans+=a[i].a1;
			printf("%lld",ans);
			ans=0;
		}
		else if(f2==0)
		{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(a[i].a1>=a[i].a2)
				{
					if(sum[1]+1<=maxs)
					{
						sum[1]++;
						ans+=a[i].a1;
					}
					else 
					{
						sum[2]++;
						ans+=a[i].a2;
					} 
				}
				else
				{
					if(sum[2]+1<=maxs)
					{
						sum[2]++;
						ans+=a[i].a2;
					}
					else 
					{
						sum[1]++;
						ans+=a[i].a1;
					} 	
				}
			}
			printf("%lld",ans);
			sum[1]=0;
			sum[2]=0;
			ans=0;
		}
		else 
		{
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n;i++)
			{
				if(sum[d(i,1)]+1<=maxs)
				{
					sum[d(i,1)]++;
					if(d(i,1)==1) ans+=a[i].a1;
					else if(d(i,1)==2) ans+=a[i].a2;
					else ans+=a[i].a3;
				}
				else if(sum[d(i,2)]+1<=maxs)
				{
					sum[d(i,2)]++;
					if(d(i,2)==1) ans+=a[i].a1;
					else if(d(i,2)==2) ans+=a[i].a2;
					else ans+=a[i].a3;
				}
				else
				{
					sum[d(i,3)]++;
					if(d(i,3)==1) ans+=a[i].a1;
					else if(d(i,3)==2) ans+=a[i].a2;
					else ans+=a[i].a3;
				}
			}
			printf("%lld",ans);
			sum[1]=0;
			sum[2]=0;
			sum[3]=0;
		}
		cout<<endl;
	}
	return 0;
} 
