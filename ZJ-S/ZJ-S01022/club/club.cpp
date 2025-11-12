#include<bits/stdc++.h>
using namespace std;
int T,n,MAX,bo2,bo3,ans,s,l,lx,hj[100010],ly,sum[100010],x;
struct node
{
	int a,b,c,ab,ac,bc;
}a[100010];
void dfs(int ak,int bk,int ck,int k,int sum)
{
	if(k==n+1)
	{
		MAX=max(MAX,sum);
		return;
	}
	if(ak<n/2) dfs(ak+1,bk,ck,k+1,sum+a[k].a);
	if(bk<n/2) dfs(ak,bk+1,ck,k+1,sum+a[k].b);
	if(ck<n/2) dfs(ak,bk,ck+1,k+1,sum+a[k].c);
}
int cmp(node a,node b)
{
	return a.a>b.a;
}
int cmpl(node a,node b)
{
	return a.ab<b.ab;
}
int cmpk(node a,node b)
{
	return a.ac<b.ac;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		MAX=0;bo2=1;bo3=1;s=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a[j].a,&a[j].b,&a[j].c);
			a[j].ab=a[j].a-a[j].b;a[j].ac=a[j].a-a[j].c;
			a[j].bc=a[j].b-a[j].c;
			s+=a[j].a;
			if(a[j].b!=0) bo2=0;
			if(a[j].c!=0) bo3=0;
		}
		if(n<=10)
		{
			dfs(0,0,0,1,0);
			cout<<MAX<<endl;
		}
		else if(bo2==1&&bo3==1)
		{
			ans=0;
			sort(a+1,a+n+1,cmp);
			for(int j=1;j<=n/2;j++) ans+=a[j].a;
			cout<<ans<<endl;
		}
		else if(bo3==1)
		{
			sort(a+1,a+n+1,cmpl);
			for(int i=1;i<=n/2;i++) s-=a[i].ab;
			cout<<s<<endl;
		}
		else
		{
			sort(a+1,a+n+1,cmpl);
			l=1;lx=0;ly=0;
			while(l<=n)
			{
				if(a[l].ab<0)
				{
					if(a[l].ab<a[l].ac&&lx<=n/2) s-=a[l].ab,lx++;
					else if(a[l].ac<a[l].ab&&ly<=n) s-=a[l].ac,ly++;
				}
				else
				{
					x=l;
					break;
				}
			}
			for(int i=1;i<=n;i++) sum[i]=0;
			for(int i=x;i<=n;i++) sum[i]=sum[i-1]+a[i].ab;
			sort(a+x,a+n+1,cmpk);
			while(a[x].ac<0&&ly<=n&&x<=n)
			{
				s-=a[x].ac;
				ly++;
				x++;
			}
			if(ly==n) cout<<s<<endl;
			else
			{
				s-=(sum[x]-sum[l-1]);
				cout<<s<<endl;
			}
		}
	}
	return 0;
}
