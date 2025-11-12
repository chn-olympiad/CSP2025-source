#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t,n,m,f[4],k,vis[100005],ans=0;
struct node
{
	int i,a,j;
}a[300005];
bool cmp(node a,node b)
{
	return a.a>b.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int i,j;
	while(t--)
	{
		ans=0;
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		k=0;
		cin>>n;
		m=n/2;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[++k].a);
			a[k].i=1;a[k].j=i;
			scanf("%d",&a[++k].a);
			a[k].i=2;a[k].j=i;
			scanf("%d",&a[++k].a);
			a[k].i=3;a[k].j=i;
		}
		sort(a+1,a+1+3*n,cmp);
		for(i=1;i<=3*n;i++)
		{
			if(f[a[i].i]<=m&&vis[a[i].j]!=1)
			{	
				vis[a[i].j ]=1;
				f[a[i].i]++;
				ans+=a[i].a;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
