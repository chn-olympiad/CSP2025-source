#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
struct node{
	int sz,club;
}a[N][8];
int vis[N],cnt;
bool cmp(node x,node y){
	return x.sz>y.sz;
}
int tj1,tj2,tj3,ans=0,maxx,wz;
struct iny{
	int cz,id;
}x[N];
bool cmp2(iny x,iny y){
	return x.cz<y.cz;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		memset(vis,0,sizeof vis);
		memset(x,0,sizeof x);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j].sz;
				a[i][j].club=j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			sort(a[i]+1,a[i]+3+1,cmp);
		}
		tj1=0,tj2=0,tj3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1].club==1)
				tj1++;
			else if(a[i][1].club==2)
				tj2++;
			else
				tj3++;		
		}
		if(tj1>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][1].club!=1)
				{
					vis[i]=1,ans+=a[i][1].sz;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					x[++cnt].cz=a[i][2].sz-a[i][1].sz;
					x[cnt].id=i;
				}
			}
			sort(x+1,x+cnt+1,cmp2);
			for(int i=1;i<=cnt;i++)
			{
				if(i>n/2)	break;
				ans+=a[x[i].id][1].sz;
				vis[x[i].id]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
					vis[i]=1,ans+=a[i][2].sz;
			}
			cout<<ans<<"\n";
		}
		else if(tj2>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][1].club!=2)
				{
					vis[i]=1,ans+=a[i][1].sz;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					x[++cnt].cz=a[i][2].sz-a[i][1].sz;
					x[cnt].id=i;
				}
			}
			sort(x+1,x+cnt+1,cmp2);
			for(int i=1;i<=cnt;i++)
			{
				if(i>n/2)	break;
				ans+=a[x[i].id][1].sz;
				vis[x[i].id]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
					vis[i]=1,ans+=a[i][2].sz;
			}
			cout<<ans<<"\n";
		}
		else if(tj3>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][1].club!=3)
				{
					vis[i]=1,ans+=a[i][1].sz;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					x[++cnt].cz=a[i][2].sz-a[i][1].sz;
					x[cnt].id=i;
				}
			}
			sort(x+1,x+cnt+1,cmp2);
			for(int i=1;i<=cnt;i++)
			{
				if(i>n/2)	break;
				ans+=a[x[i].id][1].sz;
				vis[x[i].id]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
					vis[i]=1,ans+=a[i][2].sz;
			}
			cout<<ans<<"\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
				ans+=a[i][1].sz;
			cout<<ans<<"\n";	
		}
	}
	return 0;
}