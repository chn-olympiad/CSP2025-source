#include<bits/stdc++.h>
const int MAXN=(1e5+5);
typedef long long LL;
const LL inf=1e15;
int n;
bool ok[MAXN];
LL ans;
struct Point
{
	int x,y,z,m1,m2,m3,x1,x2,x3;
	inline friend bool operator<(const Point x,const Point y)
	{
		if(x.x1!=y.x1) return x.x1>y.x1;
		else if(x.x2!=y.x2) return x.x2>y.x2;
		else return x.x3>y.x3;
	}
};
Point a[MAXN];
inline bool cmp1(Point x,Point y)
{
	return x.x>y.x;
}
inline bool cmp2(Point x,Point y)
{
	return x.y>y.y;
}
inline bool cmp3(Point x,Point y)
{
	return x.z>y.z;
}
inline void dfs(int x,LL sum,int c1,int c2,int c3)
{
	if(x==n+1)
	{
		ans=std::max(ans,sum);
		return;
	}
	if(c1+1<=n/2) dfs(x+1,sum+a[x].x,c1+1,c2,c3);
	if(c2+1<=n/2) dfs(x+1,sum+a[x].y,c1,c2+1,c3);
	if(c3+1<=n/2) dfs(x+1,sum+a[x].z,c1,c2,c3+1);
}
inline bool cmp(const Point x,const Point y)
{
	return std::max({x.x,x.y,x.z})>std::max({y.x,y.y,y.z});
}
inline void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	if(n<=30)
	{
		ans=-inf;
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
		return;
	}
	for(int i=1;i<=n;i++)
		a[i].m1=a[i].x*2-a[i].y-a[i].z,a[i].m2=a[i].y*2-a[i].x-a[i].z,a[i].m3=a[i].z*2-a[i].x-a[i].y;
	for(int i=1;i<=n;i++)
	{
		std::vector<int> v;
		v.push_back(a[i].m1);
		v.push_back(a[i].m2);
		v.push_back(a[i].m3);
		std::sort(v.begin(),v.end());
		a[i].x1=v[2],a[i].x2=v[1],a[i].x3=v[0];
	}
	std::sort(a+1,a+n+1);
	int c1=0,c2=0,c3=0;
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].m1==a[i].x1&&c1+1<=n/2) c1++,ans+=a[i].x;
		else if(a[i].m2==a[i].x1&&c2+1<=n/2) c2++,ans+=a[i].y;
		else if(a[i].m3==a[i].x1&&c3+1<=n/2) c3++,ans+=a[i].z;
		else if(a[i].m1==a[i].x2&&c1+1<=n/2) c1++,ans+=a[i].x;
		else if(a[i].m2==a[i].x2&&c2+1<=n/2) c2++,ans+=a[i].y;
		else if(a[i].m3==a[i].x2&&c3+1<=n/2) c3++,ans+=a[i].z;
		else if(a[i].m1==a[i].x3&&c1+1<=n/2) c1++,ans+=a[i].x;
		else if(a[i].m2==a[i].x3&&c2+1<=n/2) c2++,ans+=a[i].y;
		else c3++,ans+=a[i].z;
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;std::cin>>T;
	while(T--) solve();
	return 0;
}
