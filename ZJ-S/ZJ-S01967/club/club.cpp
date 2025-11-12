#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int T;
int n,a[maxn][3];
struct node{
	int id;
	int val;
	bool operator<(const node &b)const
	{
		return this->val<b.val;
	}
}nuu[maxn];
int num[3];

int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		int ans=0;
		num[0]=num[1]=num[2]=0;
		n=read();
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<3;++j)
			{
				a[i][j]=read();
			}
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])++num[0],ans+=a[i][0],nuu[i].val=min(a[i][0]-a[i][1],a[i][0]-a[i][2]),nuu[i].id=0;
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])++num[1],ans+=a[i][1],nuu[i].val=min(a[i][1]-a[i][0],a[i][1]-a[i][2]),nuu[i].id=1;
			else ++num[2],ans+=a[i][2],nuu[i].val=min(a[i][2]-a[i][1],a[i][2]-a[i][0]),nuu[i].id=2;
		}
		sort(nuu+1,nuu+n+1);
		int maxid=-1,maxnum=0;
		for(int i=0;i<3;++i)
		{
			if(num[i]>maxnum)
			{
				maxid=i;
				maxnum=num[i];
			}
		}
		int cnt=0;
		while(maxnum>n/2)
		{
			++cnt;
			while(nuu[cnt].id!=maxid)++cnt;
			ans-=nuu[cnt].val;
			--maxnum;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

