#include<cstdio>
#include<algorithm>
#include<cstring>
#define man 200005
using std::max;
struct club
{
	int x,y,z,id;
	bool operator <(const club b)const
	{
		return x<b.x;
	}
}a[man];
bool mp[man];
int n,T,cnta,cntb,cntc;
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof a);
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].id=i;
		}
		for(int i=1;i<=n/2;i++) ans+=a[i].x;
		printf("%lld\n",ans);
	}
	return 0;
}
