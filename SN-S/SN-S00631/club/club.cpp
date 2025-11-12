//SN-S00631 ½¯ÓêêØ 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 100005 
using namespace std;
struct node {ll v,id,to;} b[maxn];
ll T,n,a[maxn][5],flag[maxn],vis[maxn],sum[5],ans;
bool cmp(node x,node y) {return x.v>y.v;}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n; for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3],vis[i]=0;
		sum[1]=0,sum[2]=0,sum[3]=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			ll mx=max(max(a[i][1],a[i][2]),a[i][3]);
			if(mx==a[i][1]) sum[1]++,flag[i]=1;
			else if(mx==a[i][2]) sum[2]++,flag[i]=2;
			else sum[3]++,flag[i]=3;
			ans+=mx;
		}
		ll tot=0,id=0;
		if(sum[1]>n/2) id=1;
		if(sum[2]>n/2) id=2;
		if(sum[3]>n/2) id=3;
		if(!id) {cout<<ans<<"\n"; continue;}
		for(int i=1;i<=n;i++)
		{
			if(flag[i]!=id) continue;
			if(id!=1)
			{
				node x; x.v=a[i][1]-a[i][id]; x.id=i; x.to=1;
				b[++tot]=x;
			}
			if(id!=2)
			{
				node x; x.v=a[i][2]-a[i][id]; x.id=i; x.to=2;
				b[++tot]=x;
			}
			if(id!=3)
			{
				node x; x.v=a[i][3]-a[i][id]; x.id=i; x.to=3;
				b[++tot]=x;
			}
		}
		sort(b+1,b+tot+1,cmp); ll num=max(max(sum[1],sum[2]),sum[3])-n/2;
		for(int i=1;i<=tot&&num>0;i++)
		{
			if(vis[b[i].id]||sum[b[i].to]==n/2) continue;
			num--; ans+=b[i].v; sum[b[i].to]++; vis[b[i].id]=1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
