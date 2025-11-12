#include <bits/stdc++.h>
using namespace std;
const long long P=1e5+7,R=65536;
long long T,n,m,k,ans,sum,num,cnt,flag;
long long vis[100050],s[4][100050],ans1,ans2;
long long cnt1[4];

struct freshman
{
	long long a[4];
	long long maxid,midid,minid;
}fm[100050];
bool cmp(const freshman &a,const freshman &b)
{
	if(a.a[a.maxid]==b.a[b.maxid])
	{
		if(a.a[a.midid]==b.a[b.midid])
			return a.a[a.minid]>b.a[b.minid];
		return a.a[a.midid]>b.a[b.midid];
	}
	return a.a[a.maxid]>b.a[b.maxid];
}
long long quick_pow(long long x,long long n)
{
	long long res=1;
	while(n>0)
	{
		if(n&1)
			res*=x;
		x*=x,n>>=1;
//		res%=P,x%=P;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while (T--)
	{
		memset(cnt1,0,sizeof cnt1);
		memset(fm,0,sizeof fm);
		sum=0,cnt=0,k=0,flag=0;
		
		cin>>n;
		num=n/2;
		
		for(int i=1;i<=n;++i)
		{
			cin>>fm[i].a[1]>>fm[i].a[2]>>fm[i].a[3];
			if(fm[i].a[1]>=fm[i].a[2]&&fm[i].a[1]>=fm[i].a[3])
			{
				fm[i].maxid=1;
				if(fm[i].a[2]>=fm[i].a[3]) fm[i].midid=2,fm[i].minid=3;
				else fm[i].midid=3,fm[i].minid=2;
			}
			if(fm[i].a[1]<=fm[i].a[2]&&fm[i].a[2]>=fm[i].a[3])
			{
				fm[i].maxid=2;
				if(fm[i].a[1]>=fm[i].a[3]) fm[i].midid=1,fm[i].minid=3;
				else fm[i].midid=3,fm[i].minid=1;
			}
			if(fm[i].a[1]<=fm[i].a[3]&&fm[i].a[2]<=fm[i].a[3])
			{
				fm[i].maxid=3;
				if(fm[i].a[1]>=fm[i].a[2]) fm[i].midid=1,fm[i].minid=2;
				else fm[i].midid=2,fm[i].minid=1;
			}
		}
		
		sort(fm+1,fm+n+1,cmp);
		for(int i=1;i<=n;++i)
		{
			if(cnt1[fm[i].maxid]<num)
			{
				cnt1[fm[i].maxid]++;
				s[fm[i].maxid][cnt1[fm[i].maxid]]=i;
				sum+=fm[i].a[fm[i].maxid];
				continue;
			}
			ans=0,ans1=0,ans2=0,flag=0;
			for(int d=1;d<=cnt1[fm[i].maxid];++d)
			{
				long long k=s[fm[i].maxid][d];
				if(fm[k].a[fm[k].midid]+fm[i].a[fm[i].maxid]>fm[i].a[fm[i].midid]+fm[k].a[fm[k].maxid])
				{
					if(ans<fm[k].a[fm[k].midid]+fm[i].a[fm[i].maxid]-fm[k].a[fm[k].maxid])
					{
						ans=fm[k].a[fm[k].midid]+fm[i].a[fm[i].maxid]-fm[k].a[fm[k].maxid];
						ans1=k,ans2=d,flag=1;
					}
				}
			}
			if(flag)
			{
				sum+=ans;
				s[fm[i].maxid][ans2]=i;
				cnt1[fm[ans1].midid]++;
				s[fm[ans1].midid][cnt1[fm[ans1].midid]]=ans1;
				continue;
			}
			cnt1[fm[i].midid]++;
			sum+=fm[i].a[fm[i].midid];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
