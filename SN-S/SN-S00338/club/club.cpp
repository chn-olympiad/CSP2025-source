#include <stdio.h>
int t;
int n;
int x;
int a,b,c;
int e,f,g;
int sum;
int y[100005];
int m[100005][5];
int d[100005][5][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		a=0;
		b=0;
		c=0;
		e=0;
		f=0;
		g=0;
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&m[i][1],&m[i][2],&m[i][3]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(d[i][1][1]<m[j][1])
				{
					d[i][1][1]=m[j][1];
					d[i][1][0]=j;
					x=j;
				}
			}
			m[x][1]=0;
			for(int j=1;j<=n;j++)
			{
				if(d[i][2][1]<m[j][2])
				{
					d[i][2][1]=m[j][2];
					d[i][2][0]=j;
					x=j;
				}
			}
			m[x][2]=0;
			for(int j=1;j<=n;j++)
			{
				if(d[i][3][1]<m[j][3])
				{
					d[i][3][1]=m[j][3];
					d[i][3][0]=j;
					x=j;
				}
			}
			m[x][3]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(e==n/2)
			{
				e=0;
			}
			if(f==n/2)
			{
				f=0;
			}
			if(g==n/2)
			{
				g=0;
			}
			for(;;)
			{
				if(y[e]==0)
				{
					break;
				}
				e++;
			}
			for(;;)
			{
				if(y[f]==0)
				{
					break;
				}
				f++;
			}
			for(;;)
			{
				if(y[g]==0)
				{
					break;
				}
				g++;
			}
			if(d[e][1][1]>d[e][2][1]||d[e][1][1]>d[e][3][1])
			{
				sum=sum+d[e][1][1];
				y[d[e][1][0]]=1;
			}
			else if(d[f][2][1]>d[f][1][1]||d[f][2][1]>d[f][3][1])
			{
				sum=sum+d[f][2][1];
				y[d[f][2][0]]=1;
			}
			else
			{
				sum=sum+d[g][3][1];
				y[d[g][3][0]]=1;
			}
		}
		printf("%d",sum);
	}
	return 0;
}
