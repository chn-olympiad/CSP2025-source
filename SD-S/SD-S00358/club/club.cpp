#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct st
{
	int x,y,z,ma;
	friend bool operator<(st a,st b)
	{
		return a.ma > b.ma;
	}
}a[N];
int mx,n;
void dfs(int x,int q,int w,int e,int he)
{
	if(q>n/2||w>n/2||e>n/2)return;
	if(x==n+1)mx = max(mx,he);
	dfs(x+1,q+1,w,e,he+a[x].x);
	dfs(x+1,q,w+1,e,he+a[x].y);
	dfs(x+1,q,w,e+1,he+a[x].z);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int fl1 = 1,fl2 = 1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].ma = max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].y!=0)fl1 = 0;
			if(a[i].z!=0)fl2 = 0;
		}
		sort(a+1,a+1+n);
		if(fl1||fl2)
		{
			int ans = 0;
			for(int i=1;i<=n/2;i++)ans += a[i].x;
			printf("%d\n",ans);
			continue;
		}
		dfs(1,0,0,0,0); 
		printf("%d\n",mx);
		mx = 0;
	}
	return 0;
}


//Ren5Jie4Di4Ling5%
