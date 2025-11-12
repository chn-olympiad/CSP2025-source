#include<bits/stdc++.h>
using namespace std;
long long t,n,m[100010],q[100010],l=1,r=0,sum,mx[100010],p,ans[4];
struct node
{
	long long a,b,c;
}a[100010];
long long vis[4][100010];
bool cmp(long long x,long long y)
{
	return mx[x]-m[x]>mx[y]-m[y];
}
long long mid(long long x1,long long x2,long long x3)
{
	long long mx=max(x1,max(x2,x3));
	long long mi=min(x1,min(x2,x3));
	if(x1!=mx && x1!=mi) return x1;
	else if(x2!=mx && x2!=mi) return x2;
	else return x3;
}	
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			m[i]=mid(a[i].a,a[i].b,a[i].c);
			mx[i]=max(max(a[i].a,a[i].b),a[i].c);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].a>=a[i].b && a[i].a>=a[i].c) vis[1][++ans[1]]=i;
			else if(a[i].b>=a[i].a && a[i].b>=a[i].c) vis[2][++ans[2]]=i;
			else vis[3][++ans[3]]=i;
		}
		p=(n>>1);
		if(ans[1]>p)
		{
			sort(vis[1]+1,vis[1]+ans[1]+1,cmp);
			for(int i=ans[1];i>p;i--)
				sum+=m[vis[1][i]];
			for(int i=1;i<=p;i++) sum+=mx[vis[1][i]];
			for(int i=ans[2];i>0;i--) sum+=mx[vis[2][i]];
			for(int i=ans[3];i>0;i--) sum+=mx[vis[3][i]];
		}
		else if(ans[2]>p)
		{
			sort(vis[2]+1,vis[2]+ans[2]+1,cmp);
			for(int i=ans[2];i>p;i--)
				sum+=m[vis[2][i]];
			for(int i=1;i<=p;i++) sum+=mx[vis[2][i]];
			for(int i=ans[1];i>0;i--) sum+=mx[vis[1][i]];
			for(int i=ans[3];i>0;i--) sum+=mx[vis[3][i]];
		}
		else if(ans[3]>p)
		{
			sort(vis[3]+1,vis[3]+ans[3]+1,cmp);
			for(int i=ans[3];i>p;i--)
				sum+=m[vis[3][i]];
			for(int i=1;i<=p;i++) sum+=mx[vis[3][i]];
			for(int i=ans[1];i>0;i--) sum+=mx[vis[1][i]];
			for(int i=ans[2];i>0;i--) sum+=mx[vis[2][i]];
		}
		else
		{
			for(int i=ans[1];i>0;i--) sum+=mx[vis[1][i]];
			for(int i=ans[2];i>0;i--) sum+=mx[vis[2][i]];
			for(int i=ans[3];i>0;i--) sum+=mx[vis[3][i]];
		}
		cout<<sum<<endl;
		sum=0;
		for(int i=1;i<=3;i++)
			ans[i]=0;
	}
	return 0;
}