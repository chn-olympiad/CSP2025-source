#include<bits/stdc++.h>
using namespace std;
long long n,t,l,sum;
struct liu
{
	long long x,y,z;
	
}a[100005];
int maxx(liu k)
{
	return max(max(k.x,k.y),k.z);
}
int minn(liu k)
{
	return min(min(k.x,k.y),k.z);
}
int man(liu k)
{
	if(maxx(k)==k.y && minn(k)==k.z || maxx(k)==k.z && minn(k)==k.y)
		return k.x;
	if(maxx(k)==k.x && minn(k)==k.z || maxx(k)==k.z && minn(k)==k.x)
		return k.y;
	if(maxx(k)==k.y && minn(k)==k.x || maxx(k)==k.x && minn(k)==k.y)
		return k.z;
}
bool cmp(liu p,liu q)
{
	return maxx(q)-man(q)<maxx(p)-man(p);
}
liu xx[100005],yy[100005],zz[100005];
int xxx,yyy,zzz;
int main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
//	cin>>t;
	scanf("%lld",&t);
	while(t--)
	{
//		cin>>n;
		scanf("%lld",&n);
		xxx=yyy=zzz=0;
		bool okk=1;
		for(int i=1;i<=n;i++)
		{
//			cin>>a[i].x>>a[i].y>>a[i].z;
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y || a[i].z)okk=0;
		}
		if(okk)
		{
			int eee[100005];
			for(int i=1;i<=n;i++)eee[i]=a[i].x;
			sort(eee+1,eee+n+1);
			sum=0;
			for(int i=1;i<=n/2;i++)sum+=eee[i];
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(max(max(a[i].x,a[i].y),a[i].z)==a[i].x)
			{
				xxx++;
				xx[xxx]=a[i];
			}
			if(max(max(a[i].x,a[i].y),a[i].z)==a[i].y)
			{
				yyy++;
				yy[yyy]=a[i];
			}
			if(max(max(a[i].x,a[i].y),a[i].z)==a[i].z)
			{
				zzz++;
				zz[zzz]=a[i];
			}
		}
		if(xxx>n/2)
		{
			sort(xx+1,xxx+xx+1,cmp);
			l=xxx;
			for(int i=n/2+1;i<=l;i++)
			{
				if(man(xx[i])==xx[i].y)
				{
					if(yyy<n/2)
					{
						yyy++;
						yy[yyy]=xx[i];
						xxx--;
					}
					else
					{
						zzz++;
						zz[zzz]=xx[i];
						xxx--;
					}
				}
				else
				{
					if(zzz<n/2)
					{
						zzz++;
						zz[zzz]=xx[i];
						xxx--;
					}
					else
					{
						yyy++;
						yy[yyy]=xx[i];
						xxx--;
					}
				}
			}
		}
		if(yyy>n/2)
		{
			sort(yy+1,yyy+yy+1,cmp);
			l=yyy;
			for(int i=n/2+1;i<=l;i++)
			{
				if(man(yy[i])==yy[i].x)
				{
					if(xxx<n/2)
					{
						xxx++;
						xx[xxx]=yy[i];
						yyy--;
					}
					else
					{
						zzz++;
						zz[zzz]=yy[i];
						yyy--;
					}
				}
				else
				{
					if(zzz<n/2)
					{
						zzz++;
						zz[zzz]=yy[i];
						yyy--;
					}
					else
					{
						xxx++;
						xx[xxx]=yy[i];
						yyy--;
					}
				}
			}
		}
		if(zzz>n/2)
		{
			sort(zz+1,zzz+zz+1,cmp);
			l=zzz;
			for(int i=n/2+1;i<=l;i++)
			{
				if(man(zz[i])==zz[i].y)
				{
					if(yyy<n/2)
					{
						yyy++;
						yy[yyy]=zz[i];
						zzz--;
					}
					else
					{
						xxx++;
						xx[xxx]=zz[i];
						zzz--;
					}
				}
				else
				{
					if(xxx<n/2)
					{
						xxx++;
						xx[xxx]=zz[i];
						zzz--;
					}
					else
					{
						yyy++;
						yy[yyy]=zz[i];
						zzz--;
					}
				}
			}
		}
		sum=0;
		for(int i=1;i<=xxx;i++)sum+=xx[i].x;
		for(int i=1;i<=yyy;i++)sum+=yy[i].y;
		for(int i=1;i<=zzz;i++)sum+=zz[i].z;
		printf("%lld\n",sum);
	}
	return 0;
}

