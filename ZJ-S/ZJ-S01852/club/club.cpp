#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
struct ff{
	int x,y,z,cx,ma;
}a[100010];
int n,T;
bool cmp(ff p,ff q)
{
	return p.cx>q.cx;
}
bool cmp1(ff p,ff q) {return max(p.y,p.z)-min(p.y,p.z)>max(q.y,q.z)-min(p.y,p.z);}
bool cmp2(ff p,ff q) {return max(p.x,p.z)-min(p.x,p.z)>max(q.x,q.z)-min(p.x,p.z);}
bool cmp3(ff p,ff q) {return max(p.y,p.x)-min(p.y,p.x)>max(q.y,q.x)-min(p.y,p.x);}
bool dmp1(ff p,ff q) {return p.z>q.z;}
bool dmp2(ff p,ff q) {return p.y>q.y;}
bool dmp3(ff p,ff q) {return p.x>q.x;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		int sx=0,sy=0,sz=0,k=n/2,ans=0,maxn=-1e9;
		for(int i=1;i<=n;i++) 
		{
			a[i].x=read();a[i].y=read();a[i].z=read();
			a[i].ma=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].ma==a[i].x) a[i].cx=a[i].x-max(a[i].y,a[i].z);
			if(a[i].ma==a[i].y) a[i].cx=a[i].y-max(a[i].x,a[i].z);
			if(a[i].ma==a[i].z) a[i].cx=a[i].z-max(a[i].x,a[i].y);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(sx<k&&sy<k&&sz<k)
			{
				if(a[i].ma==a[i].x) {ans+=a[i].x;sx++;}
				if(a[i].ma==a[i].y) {ans+=a[i].y;sy++;}
				if(a[i].ma==a[i].z) {ans+=a[i].z;sz++;}
			}
			else break;
		}
		if(sx+sy+sz==n) {printf("%d\n",ans);continue;}
		else
		{
			if(sx==k)
			{
				sort(a+sx+sy+sz+1,a+n+1,cmp1);
				for(int i=sx+sy+sz+1;i<=n;i++)
				{
					if(sy<k&&sz<k)
					{
						if(a[i].y>=a[i].z) {ans+=a[i].y;sy++;}
						else {ans+=a[i].z;sz++;}
					}
					else break;
				}
				if(sx+sy+sz==n) {printf("%d\n",ans);continue;}
				else
				{
					if(sy==k) 
					{
						sort(a+sx+sy+sz+1,a+n+1,dmp1);
						for(int i=sx+sy+sz+1;i<=n;i++) ans+=a[i].z;
						printf("%d\n",ans);continue;
					}
					else 
					{
						sort(a+sx+sy+sz+1,a+n+1,dmp2);
						for(int i=sx+sy+sz+1;i<=n;i++) ans+=a[i].y;
						printf("%d\n",ans);continue;
					}
				}
			}
			else if(sy==k)
			{
				sort(a+sx+sy+sz+1,a+n+1,cmp2);
				for(int i=sx+sy+sz+1;i<=n;i++)
				{
					if(sx<k&&sz<k)
					{
						if(a[i].x>=a[i].z) {ans+=a[i].x;sx++;}
						else {ans+=a[i].z;sz++;}
					}
					else break;
				}
				if(sx+sy+sz==n) {printf("%d\n",ans);continue;}
				else
				{
					if(sx==k) 
					{
						sort(a+sx+sy+sz+1,a+n+1,dmp1);
						for(int i=sx+sy+sz+1;i<=n;i++) ans+=a[i].z;
						printf("%d\n",ans);continue;
					}
					else 
					{
						sort(a+sx+sy+sz+1,a+n+1,dmp3);
						for(int i=sx+sy+sz+1;i<=n;i++) ans+=a[i].x;
						printf("%d\n",ans);continue;
					}
				}
			}
			else if(sz==k)
			{
				sort(a+sx+sy+sz+1,a+n+1,cmp3);
				for(int i=sx+sy+sz+1;i<=n;i++)
				{
					if(sy<k&&sx<k)
					{
						if(a[i].y>=a[i].x) {ans+=a[i].y;sy++;}
						else {ans+=a[i].x;sx++;}
					}
					else break;
				}
				if(sx+sy+sz==n) {printf("%d\n",ans);continue;}
				else
				{
					if(sy==k) 
					{
						sort(a+sx+sy+sz+1,a+n+1,dmp2);
						for(int i=sx+sy+sz+1;i<=n;i++) ans+=a[i].y;
						printf("%d\n",ans);continue;
					}
					else 
					{
						sort(a+sx+sy+sz+1,a+n+1,dmp3);
						for(int i=sx+sy+sz+1;i<=n;i++) ans+=a[i].x;
						printf("%d\n",ans);continue;
					}
				}
			}
		}
	}
	return 0;
}
