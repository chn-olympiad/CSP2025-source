#include <bits/stdc++.h>
using namespace std;
int t,n,ans,maxn,x,y,z;
struct node
{
	int a,b,c;
}a[100005];
bool cmp(node a,node b)
{
	return a.a>b.a;
}
void dfs(int dep)
{
	if(x>n/2||y>n/2||z>n/2)return;
	if(dep==n+1)
	{
		maxn=max(maxn,ans);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)ans+=a[dep].a,x++;
		if(i==2)ans+=a[dep].b,y++;
		if(i==3)ans+=a[dep].c,z++;
		dfs(dep+1);
		if(i==1)ans-=a[dep].a,x--;
		if(i==2)ans-=a[dep].b,y--;
		if(i==3)ans-=a[dep].c,z--;	
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxn=0;
		ans=0;
		x=0;
		y=0;
		z=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0)f1=1;
			if(a[i].c!=0)f2=1;
		}
		if(n<=30)
		{
			dfs(1);
			cout<<maxn;			
		}
		else if(f1==0&&f2==0)
		{
			sort(a+1,a+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++)
				sum+=a[i].a;
			cout<<sum;
		}
	}
	return 0;
}
