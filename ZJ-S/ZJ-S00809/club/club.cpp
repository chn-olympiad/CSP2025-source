#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,s,a[100005][4],b[100005],id[100005],gb[100005];
struct node
{
	int x,id;
}c[4];
bool cmp(node a,node b)
{
	return a.x>b.x;
}
void clear()
{
	for(int i=1;i<=n;i++)
		gb[i]=a[i][1]=a[i][2]=a[i][3]=id[i]=b[i]=0;
	for(int i=1;i<=3;i++)
		c[i]={0,0};
	ans=s=0;
}
void solve()
{
	cin>>n;
	clear();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		b[i]=max(max(a[i][1],a[i][2]),a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			id[i]=1;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			id[i]=2;
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
			id[i]=3;
	}
	for(int i=1;i<=n;i++)
		ans+=b[i];
	for(int i=1;i<=n;i++)
		c[id[i]].x++;
	for(int i=1;i<=3;i++)
		c[i].id=i;
	sort(c+1,c+4,cmp);
	if(c[1].x<=n/2)
	{
		cout<<ans<<'\n';
		return;
	}
	int tz=c[1].x-n/2;
	for(int i=1;i<=n;i++)
		if(id[i]==c[1].id)
		{
			int x=0;
			for(int k=1;k<=3;k++)
				if(k!=id[i])
					x=max(x,a[i][k]);
			gb[++s]=a[i][id[i]]-x;
		}
	sort(gb+1,gb+1+s);
	for(int i=1;i<=tz;i++)
		ans-=gb[i];
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
		solve();
}