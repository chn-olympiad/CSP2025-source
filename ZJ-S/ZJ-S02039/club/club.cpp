#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int T,n,ans,a[N][3],c[N],t[3];
bool b[N];
void dfs(int k,int sum)
{
	if(k>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	  if(!b[i])
	    {
	    	b[i]=1;
	  		if(t[0]<n/2)
	  		{
	  			t[0]++;
	  			dfs(k+1,sum+a[i][0]);
	  			t[0]--;
	   		}
	   		if(t[1]<n/2)
	  		{
	  			t[1]++;
	  			dfs(k+1,sum+a[i][1]);
	  			t[1]--;
	   		}
	   		if(t[2]<n/2)
	  		{
	  			t[2]++;
	  			dfs(k+1,sum+a[i][2]);
	  			t[2]--;
	   		}
	   		b[i]=0;
	    }
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		bool flag=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2;j++)
			  scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;i++)
		  if(a[i][2]!=0||a[i][1]!=0)
		  {
		  	flag=false;
		  	break;
		  }
		if(flag)
		{
			for(int i=1;i<=n;i++)
			  c[i]=a[i][0];
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2;i--)
			  ans+=c[i];
			printf("%d\n",ans);
			continue;
		}
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
//chzx_lfw AK IOI!!!!!
