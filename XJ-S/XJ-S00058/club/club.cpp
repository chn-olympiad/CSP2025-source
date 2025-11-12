#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4],m[N];
		long long n,maxx=0;
int f[N];

void dfs(int x,long long cnt,int a1,int b1,int c1)
{
	if(x==n+1)
	{
		maxx=max(maxx,cnt);
		return ;
	}

		if(a1<(n/2))
		{
			dfs(x+1,cnt+a[x][1],a1+1,b1,c1);
			
		}
		if(b1<(n/2))
		{
			dfs(x+1,cnt+a[x][2],a1,b1+1,c1);
		}
		if(c1<(n/2))
		{
			dfs(x+1,cnt+a[x][3],a1,b1,c1+1);
		}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
		while(T--)
	{
int a1=0,b1=0,c1=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			m[i]=a[i][1];
			c=c+a[i][2]+a[i][3];
		}
		if(c==0)
		{
			
			sort(m,m+1+n);
			for(int i=1;i<=n/2;i++)
			{
				maxx+=m[i];
			}
			cout<<maxx;
			
		}
		else
		dfs(1,0,0,0,0);
		cout<<maxx<<endl;
		maxx=0;
 }
 return 0; 
}
