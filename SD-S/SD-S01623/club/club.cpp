#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
struct node
{
	int a,b,c;
	bool operator<(const node &x)const
	{
		return a>x.a;
	}
}a[MAXN];
int n,m;
int f[220][220][220];
int main()
{
	//freopen()
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		if(n<=300)
		{
			for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(i,n/2);j++)
				{
					for(int p=0;p<=min(i,n/2);p++)
					{
						if(p+j>i||i-p-j>n/2) continue;
						if(j-1>=0) f[i][j][p]=max(f[i][j][p],f[i-1][j-1][p]+a[i].a);
						if(p-1>=0) f[i][j][p]=max(f[i][j][p],f[i-1][j][p-1]+a[i].b);
						if(i-j-p>0) f[i][j][p]=max(f[i][j][p],f[i-1][j][p]+a[i].c);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=(n/2);i++)
			{
				for(int j=0;j<=(n/2);j++)
				{
					if(n-i-j>n/2) continue;
					ans=max(ans,f[n][i][j]);
				}
			}
			cout<<ans<<endl;
			n=0;
			memset(f,0,sizeof(f));
			ans=0;	
		}
		else
		{
			for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].a;
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}
/*
I love CCF
I can't solve this problem
17:59 I can't solve this problem
I'll AFO
Goodbye
*/
