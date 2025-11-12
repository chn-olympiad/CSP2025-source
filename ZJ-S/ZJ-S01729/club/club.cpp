#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],tmp[N],tot;
bool vis[N],flag;
long long ma;
void dfs(int nx,int ny,int nz,int to,long long sum)
{
    if(to==n+1)
    {
        ma=max(ma,sum);
        return;
    }
    for(int i=to;i<=n;i++)
    {
    	if(vis[i]==0)
    	{
    		vis[i]=1;
        	if(nx+1<=n/2)
        	    dfs(nx+1,ny,nz,to+1,sum+a[i][1]);
       		if(ny+1<=n/2)
            	dfs(nx,ny+1,nz,to+1,sum+a[i][2]);            
        	if(nz+1<=n/2)
            	dfs(nx,ny,nz+1,to+1,sum+a[i][3]);
			vis[i]=0;
        }
    }
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		ma=-1; flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) flag=1;
		}
		if(flag==0)
		{
			ma=0;
			for(int i=1;i<=n;i++) tmp[++tot]=a[i][1];
			sort(tmp+1,tmp+n+1);
			for(int i=n;i>=n/2+1;i--) ma+=tmp[i];
			printf("%lld\n",ma);
			continue;
		}
        dfs(0,0,0,1,0);
        printf("%lld\n",ma);
	}
return 0;
}
