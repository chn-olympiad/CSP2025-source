#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,Max,id,m,cnt[N],p[N];
struct node
{
	int x,id;
}a[N][3];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
bool cmp2(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		Max=0,ans=0,m=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
		}
		for(int i=1;i<=n;++i) sort(a[i]+1,a[i]+4,cmp);
		for(int i=1;i<=n;++i) cnt[a[i][1].id]++,ans+=a[i][1].x;
		if(Max<cnt[1]) Max=cnt[1],id=1;
		if(Max<cnt[2]) Max=cnt[2],id=2;
		if(Max<cnt[3]) Max=cnt[3],id=3;
		for(int i=1;i<=n;++i)
		if(a[i][1].id==id) p[++m]=a[i][1].x-a[i][2].x;
		sort(p+1,p+1+m,cmp2);
		for(int i=n/2+1;i<=m;++i) ans-=p[i];
		cout<<ans<<"\n";
	}
	return 0;
}
