#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

const int N=1e5+10;
const db eps=1e-8;

int mp[5];
struct node
{
	int f,d;
}a[N][5];
node b[N];
bool cmp(node x,node y)
{
	return x.f<y.f;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(mp,0,sizeof(mp));
		int n;
		scanf("%d",&n);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a[i][1]={x,1};
			a[i][2]={y,2};
			a[i][3]={z,3};
			if(x<y)swap(a[i][1],a[i][2]),swap(x,y);
			if(x<z)swap(a[i][1],a[i][3]),swap(x,z);
			if(y<z)swap(a[i][3],a[i][2]),swap(z,y);
			ans+=a[i][1].f;
			mp[a[i][1].d]++;
			b[i]={a[i][1].f-a[i][2].f,i};
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=3;i++)if(mp[i]>n/2)
		{
			for(int j=1;j<=n;j++)if(a[b[j].d][1].d==i)
			{
				ans-=b[j].f;
				mp[i]--;
				if(mp[i]<=n/2)break;
			}
			break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
