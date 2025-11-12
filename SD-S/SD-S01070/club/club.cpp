#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<deque>
#include<algorithm> 
using namespace std;
const long long N=100010;
struct an
{
	long long x,y,z,mx,mxx,bh,bhh,pr;
}a[N];
bool cmp(an l,an r)
{
	return l.pr>r.pr; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
//	cin>>T;
	scanf("%lld",&T);
	while(T--)
	{
		long long n;
//		cin>>n;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)
		{
//			cin>>a[i].x>>a[i].y>>a[i].z;
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z); 
			a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
			long long mi=min(a[i].x,min(a[i].y,a[i].z));
			long long sum=a[i].x+a[i].y+a[i].z;
			a[i].mxx=sum-a[i].mx-mi;
			if(a[i].mx==a[i].x)a[i].bh=1;
			else if(a[i].mx==a[i].y)a[i].bh=2;
			else a[i].bh=3;
			if(a[i].mxx==a[i].x&&a[i].bh!=1)a[i].bhh=1;
			else if(a[i].mxx==a[i].y&&a[i].bh!=2)a[i].bhh=2;
			else if(a[i].mxx==a[i].z&&a[i].bh!=3)a[i].bhh=3;
			long long cnt,cntt;
			if(a[i].bh==1)cnt=a[i].x;
			else if(a[i].bh==2)cnt=a[i].y;
			else cnt=a[i].z;
			if(a[i].bhh==1)cntt=a[i].x;
			else if(a[i].bhh==2)cntt=a[i].y;
			else cntt=a[i].z;
			a[i].pr=cnt-cntt;
		}
		sort(a+1,a+1+n,cmp);
		long long ans=0,cntx=0,cnty=0,cntz=0;
		for(long long i=1;i<=n;i++)
		{
			if(a[i].bh==1&&cntx<(n/2))
			{
				ans+=a[i].x;
				cntx++;
				continue;
			}
			if(a[i].bh==2&&cnty<(n/2))
			{
				ans+=a[i].y;
				cnty++;
				continue;
			}
			if(a[i].bh==3&&cntz<(n/2))
			{
				ans+=a[i].z;
				cntz++;
				continue;
			}
			if(a[i].bhh==1)
			{
				ans+=a[i].x;
				cntx++;
			}
			else if(a[i].bhh==2)
			{
				ans+=a[i].y;
				cnty++;
			}
			else
			{
				ans+=a[i].z;
				cntz++;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<"i: "<<i<<" bh: "<<a[i].bh<<" bhh: "<<a[i].bhh<<" pr: "<<a[i].pr<<endl;
//		}
//		cout<<ans<<endl;
		printf("%lld\n",ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
