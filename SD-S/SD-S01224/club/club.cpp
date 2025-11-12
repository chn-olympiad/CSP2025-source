#include<bits/stdc++.h>
using namespace std;
const long long imaxn=1e5+10;
long long t,n,a,b,c;
struct mys{
	long long a,b,c,imax,iimax;
}arr[imaxn];
bool cmp(mys q,mys w)
{
	return q.a>w.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(long long i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
		}
		if(n==2)
		{
			int t1,t2;
			arr[0].imax=max(max(arr[0].a,arr[0].b),arr[0].c);
			if(arr[0].imax==arr[0].a)
			{
				arr[0].iimax=max(arr[0].b,arr[0].c);
				t1=0;
			}
			else if(arr[0].imax==arr[0].b)
			{
				arr[0].iimax=max(arr[0].a,arr[0].c);
				t1=1;
			}
			else
			{
				arr[0].iimax=max(arr[0].a,arr[0].b);
				t1=2;
			}
			arr[1].imax=max(max(arr[1].a,arr[1].b),arr[1].c);
			if(arr[1].imax==arr[1].a)
			{
				arr[1].iimax=max(arr[1].b,arr[1].c);
				t2=0;
			}
			else if(arr[1].imax==arr[1].b)
			{
				arr[1].iimax=max(arr[1].a,arr[1].c);
				t2=1;
			}
			else
			{
				arr[1].iimax=max(arr[1].a,arr[1].b);
				t2=2;
			}
			if(t1!=t2) printf("%lld\n",arr[0].imax+arr[1].imax);
			else printf("%lld\n",max(arr[0].imax+arr[1].iimax,arr[0].iimax+arr[1].imax));
		}
		else
		{
			sort(arr,arr+n,cmp);
			long long ans=0;
			for(int i=0;i<n/2;i++)
			{
				ans+=arr[i].a;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
