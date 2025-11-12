#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

int a[MAXN][4],mx[MAXN][4],md[MAXN][4],a1[MAXN],b[MAXN],c[MAXN];
int cnt[MAXN],asum[MAXN],f[MAXN],g[MAXN][4];
int af[MAXN],bf[MAXN],cf[MAXN];

int cmp(int x,int y)
{
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
    	{
    		asum[i]=0;
    		mx[i][1]=0;
    		mx[i][2]=0;
    		mx[i][3]=0;
    		cnt[i]=0;
    		md[i][1]=0;
    		md[i][2]=0;
    		md[i][3]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int sum=0,id=0;
			for(int j=1;j<=3;j++)
			{
			    scanf("%d",&a[i][j]);
			    g[i][j]=a[i][j];
				if(sum<a[i][j])
				{
					sum=a[i][j];
					id=j;
				}
			}
			int sum2=0,id2=0,flag=0,d=0;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]==sum)
				{
					flag++;
					d=j;
				}
				if(sum2<a[i][j]&&a[i][j]!=sum)
				{
					sum2=a[i][j];
					id2=j;
				}
			}
			if(flag>=2)
			{
				sum2=sum;
				id2=d;
			}
			asum[id]+=sum;
			md[i][id2]=sum2;
			mx[i][id]=sum;
			cnt[id]++;
		}
		for(int k=1;k<=3;k++)
		{
			if(cnt[k]>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=3;j++)
					{
						if(md[i][j]!=0&&mx[i][k]!=0)
						{
							mx[i][j]=md[i][j];
						}
					}
				}
			}
		}
		if(n==2)
		{
	    	int ans=0;
			for(int i=1;i<=3;i++)
			{
    			for(int j=1;j<=3;j++)
				{
					if(i!=j) ans=max(ans,mx[1][i]+mx[2][j]);
				}
		    }
	    	printf("%d",ans);
	    	continue;
		}
		for(int i=1;i<=n;i++)
		{
			a1[i]=g[i][1];
			b[i]=g[i][2];
			c[i]=g[i][3];
		}
		sort(a1+1,a1+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		{
			af[a1[i]]=1;
			bf[b[i]]=1;
			cf[c[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(af[g[i][1]]!=1) mx[i][1]=0;
			if(bf[g[i][2]]!=1) mx[i][2]=0;
			if(cf[g[i][3]]!=1) mx[i][3]=0;
		}
		long long res=0;
		for(int i=1;i<=n;i++)
	    {
			for(int j=1;j<=3;j++)
	   	    {
	    		res+=mx[i][j];
		   	}
        }
		printf("%lld\n",res);
    }
	return 0;
}

